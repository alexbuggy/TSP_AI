#include "TSP.h"

void dfs(TSP& tsp) {
    int n = tsp.cities.size();
    stack<vector<int>> s;
    s.push({ 0 }); // Start from city 0
    double min_longest_leg_cost = numeric_limits<double>::max();
    vector<int> best_path;

    while (!s.empty()) {
        vector<int> path = s.top();
        s.pop();

        if (path.size() == n) {
            path.push_back(0); // Return to origin
            double longest_leg_cost = CalculateLongestLegCost(path, tsp.distances);
            if (longest_leg_cost < min_longest_leg_cost) {
                min_longest_leg_cost = longest_leg_cost;
                best_path = path;
            }
            path.pop_back();
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (find(path.begin(), path.end(), i) == path.end()) {
                    vector<int> new_path = path;
                    new_path.push_back(i);
                    s.push(new_path);
                }
            }
        }
    }

    cout << "DFS Best path: ";
    for (int city : best_path) cout << tsp.cities[city].name << " ";
    cout << "\nDFS Minimum longest leg cost: " << min_longest_leg_cost << endl;
}