#include "TSP.h"

struct PathCost {
    vector<int> path;
    double cost;
    double longest_leg_cost;
    bool operator<(const PathCost& other) const {
        return longest_leg_cost > other.longest_leg_cost;
    }
};

void ucs(TSP& tsp) {
    int n = tsp.cities.size();
    priority_queue<PathCost> pq;
    pq.push({ {0}, 0, 0 });
    double min_longest_leg_cost = numeric_limits<double>::max();
    vector<int> best_path;

    while (!pq.empty()) {
        PathCost current = pq.top();
        pq.pop();

        if (current.path.size() == n) {
            current.path.push_back(0); // Return to origin
            double current_longest_leg = CalculateLongestLegCost(current.path, tsp.distances);
            if (current_longest_leg < min_longest_leg_cost) {
                min_longest_leg_cost = current_longest_leg;
                best_path = current.path;
            }
        }
        else {
            int last_city = current.path.back();
            for (int next_city = 1; next_city < n; ++next_city) {
                if (find(current.path.begin(), current.path.end(), next_city) == current.path.end()) {
                    vector<int> new_path = current.path;
                    new_path.push_back(next_city);
                    double new_cost = current.cost + tsp.distances[last_city][next_city];
                    double new_longest_leg = max(current.longest_leg_cost, tsp.distances[last_city][next_city]);
                    pq.push({ new_path, new_cost, new_longest_leg });
                }
            }
        }
    }

    cout << "UCS Best path: ";
    for (int city : best_path) {
        cout << tsp.cities[city].name << " ";
    }
    cout << "\nUCS Minimum longest leg cost: " << min_longest_leg_cost << endl;
}