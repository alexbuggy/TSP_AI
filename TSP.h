#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <functional>
using namespace std;

struct City {
    int id;
    string name;
    City(int id, string name) : id(id), name(name) {}
};

struct Edge {
    int from;
    int to;
    double distance;
    Edge(int from, int to, double distance) : from(from), to(to), distance(distance) {}
    bool operator>(const Edge& other) const {
        return distance > other.distance;
    }
};

double CalculatePathCost(const vector<int>& path, const vector<vector<double>>& distances);
double CalculateLongestLegCost(const vector<int>& path, const vector<vector<double>>& distances);

class TSP {
public:
    vector<City> cities;
    vector<vector<double>> distances;
    TSP(int n) : n(n) {
        distances.resize(n, vector<double>(n, 0.0));
    }

    void AddDistance(int from, int to, double distance) {
        distances[from][to] = distance;
        distances[to][from] = distance;
    }
private:
    int n;
};

#endif