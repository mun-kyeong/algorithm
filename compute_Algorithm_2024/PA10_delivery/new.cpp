#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int node;
vector<pair<int, int> > nodes;
vector<vector<int> > distance_map;
vector<vector<int> > dp_distance;
vector<vector<int> > dp_order;

int manhattan_distance(pair<int, int> point1, pair<int, int> point2) {
    return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

void init(){
    node = n * 2 + 1;
    nodes.resize(node, make_pair(0, 0));
    nodes[0] = make_pair(500, 500);
    distance_map.resize(node, vector<int>(node, 0));
    dp_distance.resize(node, vector<int>(1 << node, -1));
    dp_order.resize(node, vector<int>(1 << node, 0));

    for (int i = 1; i <= node / 2; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        nodes[node / 2 - i + 1] = make_pair(c, d);
        nodes[i + node / 2] = make_pair(a, b);
    }
    for (int i = 0; i < node; ++i) {
        for (int j = 0; j < node; ++j) {
            distance_map[i][j] = manhattan_distance(nodes[i], nodes[j]);
        }
    }
}

int findDistance(int index, int visited, int boxCount) {
    if (visited == (1 << node) - 1) return 0;
    if (dp_distance[index][visited] != -1) return dp_distance[index][visited];

    dp_distance[index][visited] = INT_MAX;

    for (int i = 0; i < node; ++i) {
        if (visited & (1 << i)) continue;

        if (i <= node / 2) {
            if (!(visited & (1 << (node - i)))) continue;

            int dist = distance_map[index][i] + findDistance(i, visited | (1 << i), boxCount - 1);
            if (dist < dp_distance[index][visited]) {
                dp_distance[index][visited] = dist;
                dp_order[index][visited] = i;
            }
        } else {
            if (boxCount >= 2) continue;

            int dist = distance_map[index][i] + findDistance(i, visited | (1 << i), boxCount + 1);
            if (dist < dp_distance[index][visited]) {
                dp_distance[index][visited] = dist;
                dp_order[index][visited] = i;
            }
        }
    }
    return dp_distance[index][visited];
}

pair<vector<int>, int> DistancePath() {
    int minPath = findDistance(0, 1, 0);
    int index = dp_order[0][1];
    int visited = 1;
    vector<int> order;

    for (int i = 0; i < node / 2 * 2; ++i) {
        if (index <= node / 2) {
            order.push_back(-(node / 2 - index + 1));
        } else {
            order.push_back(index - node / 2);
        }
        visited |= 1 << index;
        index = dp_order[index][visited];
    }
    return make_pair(order, minPath);
}

int main() {
    cin >> n;
    init();
    pair<vector<int>, int> result = DistancePath();
    vector<int> order = result.first;
    int minPath = result.second;

    for (int node : order)
        cout << node << " ";
    
    cout << endl;
    cout << minPath << endl;

    return 0;
}
