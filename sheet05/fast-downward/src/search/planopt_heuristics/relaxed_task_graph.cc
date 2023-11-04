#include "relaxed_task_graph.h"

#include <iostream>
#include <vector>

using namespace std;

namespace planopt_heuristics {
RelaxedTaskGraph::RelaxedTaskGraph(const TaskProxy &task_proxy)
    : relaxed_task(task_proxy),
      variable_node_ids(relaxed_task.propositions.size()) {
    for (const Proposition &proposition : relaxed_task.propositions) {
        variable_node_ids[proposition.id] = graph.add_node(NodeType::OR);
    }

    initial_node_id = graph.add_node(NodeType::AND);
    for (PropositionID id : relaxed_task.initial_state) {
        graph.add_edge(variable_node_ids[id], initial_node_id);
    }

    for (const RelaxedOperator &op : relaxed_task.operators) {
        NodeID precondition_node_id = graph.add_node(NodeType::AND);
        for (PropositionID pre : op.preconditions) {
            graph.add_edge(precondition_node_id, variable_node_ids[pre]);
        }

        // We set the cost of an effect node here for exercise (c)
        NodeID effect_node_id = graph.add_node(NodeType::AND, op.cost);
        for (PropositionID eff : op.effects) {
            graph.add_edge(variable_node_ids[eff], effect_node_id);
        }

        graph.add_edge(effect_node_id, precondition_node_id);
    }

    goal_node_id = graph.add_node(NodeType::AND);
    for (PropositionID goal : relaxed_task.goal) {
        graph.add_edge(goal_node_id, variable_node_ids[goal]);
    }
}

void RelaxedTaskGraph::change_initial_state(const State &state) {
    /* Remove all initial edges that where introduced for
       relaxed_task.initial_state. */
    for (PropositionID id : relaxed_task.initial_state) {
        graph.remove_edge(variable_node_ids[id], initial_node_id);
    }

    // Switch initial state of relaxed_task
    relaxed_task.initial_state = relaxed_task.translate_state(state);

    // Add all initial edges for relaxed_task.initial_state.
    for (PropositionID id : relaxed_task.initial_state) {
        graph.add_edge(variable_node_ids[id], initial_node_id);
    }
}

bool RelaxedTaskGraph::is_goal_relaxed_reachable() {
    cout << "initial_node_id=" << initial_node_id << endl;
    cout << "goal_node_id=" << goal_node_id << endl;
    cout << "nodes in total =" << variable_node_ids.size() << endl;

    // Initialize reachable HashMap
    for(Proposition proposition : relaxed_task.propositions){
        cout << "Proposition ID=" << proposition.id << " and name=" << proposition.name << endl;
    }

    using HashMap = utils::HashMap<NodeID, bool>;
    HashMap reachable;

    // Initialize reachable HashMap
    for(NodeID nodeID : variable_node_ids){
        AndOrGraphNode node = graph.get_node(nodeID);

        if(nodeID == initial_node_id){
            reachable[nodeID] = true;
            cout << "Node " << nodeID << " reachable=true" << endl;
        } else {
            reachable[nodeID] = false;
            cout << "Node " << nodeID << " reachable=false" << endl;
        }
    }

    /* Compute the most conservative valuation of the graph and use it
    to return true iff the goal is reachable in the relaxed task. */

    // TODO: add your code for exercise 5.3(b) here.


    int currentNodeID = 0;
    int lastChangedNodeID = -1;
    int iterations = 30;

    while(true){
        AndOrGraphNode currentNode = graph.get_node(currentNodeID);

        if(currentNodeID == lastChangedNodeID){
            // We have reached a fixed point. Since changing the reachability of this node,
            // no other node has been changed.
            cout << "Node " << currentNodeID << "BREAK: Fixed point reached" << endl;
            break;
        }

        bool isCurrentNodeReachable = false;
        if(currentNode.type == NodeType::AND){
            // All successors have to be reachable
            isCurrentNodeReachable = true;
            for (NodeID successorNodeID : currentNode.successor_ids){
                if(reachable[successorNodeID] == false){
                    isCurrentNodeReachable = false;
                    break;
                }
            }
        } else {
            // At least one successor has to be reachable
            for (NodeID successorNodeID : currentNode.successor_ids){
                if(reachable[successorNodeID] == true){
                    isCurrentNodeReachable = true;
                    break;
                }
            }
        }

        if(isCurrentNodeReachable){
            cout << "Node " << currentNodeID << "set reachable=true and set lastChangedNodeID=" << lastChangedNodeID << endl;
            reachable[currentNodeID] = true;
            lastChangedNodeID = currentNodeID;
        }
        
        // Cycle through node IDs
        currentNodeID = (currentNodeID + 1) % variable_node_ids.size();
        cout << "Next Node " << currentNodeID << endl;

        iterations += 1;
        if(iterations >= 50){
            cout << "BREAK: Iteration Limit reached" << endl;
            break;
        }
    }
    
    bool is_goal_reachable = reachable[initial_node_id];
    cout << "is_goal_relaxed_reachable=" << is_goal_reachable << endl;
    return is_goal_reachable;
}

int RelaxedTaskGraph::additive_cost_of_goal() {
    /* Compute the weighted most conservative valuation of the graph and
       use it to return the h^add value of the goal node. */

    // TODO: add your code for exercise 5.3(d) here.
    graph.weighted_most_conservative_valuation();
    AndOrGraphNode node = graph.get_node(goal_node_id);
    //cout << "Goal Node ID: " << goal_node_id << endl;
    return node.additive_cost;
}

int RelaxedTaskGraph::ff_cost_of_goal() {
    // Disclosed solution for computing the costs of h^FF.
    return -1;
}

}
