#include "h_add.h"

#include "../plugins/plugin.h"

using namespace std;

namespace planopt_heuristics {
HAddHeuristic::HAddHeuristic(const plugins::Options &options)
    : Heuristic(options),
      relaxed_task_graph(task_proxy) {
}

int HAddHeuristic::compute_heuristic(const State &state) {
    relaxed_task_graph.change_initial_state(state);
    if (relaxed_task_graph.is_goal_relaxed_reachable()) {
        return relaxed_task_graph.additive_cost_of_goal();
    } else {
        return DEAD_END;
    }
}

class HAddHeuristicFeature : public plugins::TypedFeature<Evaluator, HAddHeuristic> {
public:
    HAddHeuristicFeature() : TypedFeature("planopt_add") {
        Heuristic::add_options_to_feature(*this);
    }
};

static plugins::FeaturePlugin<HAddHeuristicFeature> _plugin;
}
