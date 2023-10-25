#include "h_relaxed_task_graph.h"

#include "../plugins/plugin.h"
#include "../task_utils/task_properties.h"

using namespace std;

namespace planopt_heuristics {
RelaxedTaskGraphHeuristic::RelaxedTaskGraphHeuristic(
    const plugins::Options &options)
    : Heuristic(options),
      relaxed_task_graph(task_proxy),
      min_operator_cost(task_properties::get_min_operator_cost(task_proxy)){
}

int RelaxedTaskGraphHeuristic::compute_heuristic(const State &state) {
    relaxed_task_graph.change_initial_state(state);
    if (relaxed_task_graph.is_goal_relaxed_reachable()) {
        if (task_properties::is_goal_state(task_proxy, state)) {
            return 0;
        } else {
            return min_operator_cost;
        }
    } else {
        return DEAD_END;
    }
}

class RelaxedTaskGraphHeuristicFeature : public plugins::TypedFeature<Evaluator, RelaxedTaskGraphHeuristic> {
public:
    RelaxedTaskGraphHeuristicFeature() : TypedFeature("planopt_relaxed_task_graph") {
        Heuristic::add_options_to_feature(*this);
    }
};

static plugins::FeaturePlugin<RelaxedTaskGraphHeuristicFeature> _plugin;
}
