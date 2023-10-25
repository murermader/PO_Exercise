#include "h_ff.h"

#include "../plugins/plugin.h"

using namespace std;

namespace planopt_heuristics {
HFFHeuristic::HFFHeuristic(const plugins::Options &options)
    : Heuristic(options),
      relaxed_task_graph(task_proxy) {
}

int HFFHeuristic::compute_heuristic(const State &state) {
    relaxed_task_graph.change_initial_state(state);
    if (relaxed_task_graph.is_goal_relaxed_reachable()) {
        return relaxed_task_graph.ff_cost_of_goal();
    } else {
        return DEAD_END;
    }
}

class HFFHeuristicFeature : public plugins::TypedFeature<Evaluator, HFFHeuristic> {
public:
    HFFHeuristicFeature() : TypedFeature("planopt_ff") {
        Heuristic::add_options_to_feature(*this);
    }
};

static plugins::FeaturePlugin<HFFHeuristicFeature> _plugin;
}
