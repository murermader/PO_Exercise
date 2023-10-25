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
    /* Compute the most conservative valuation of the graph and use it
       to return true iff the goal is reachable in the relaxed task. */

    // TODO: add your code for exercise 5.3(b) here.
    return false;
}

int RelaxedTaskGraph::additive_cost_of_goal() {
    /* Compute the weighted most conservative valuation of the graph and
       use it to return the h^add value of the goal node. */

    // TODO: add your code for exercise 5.3(d) here.
    return -1;
}

int RelaxedTaskGraph::ff_cost_of_goal() {
    // Disclosed solution for computing the costs of h^FF.
    return -1;
}

}
