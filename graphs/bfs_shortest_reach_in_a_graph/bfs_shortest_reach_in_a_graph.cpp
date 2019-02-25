// author: Moongee Cho
// date: 02/26/2019

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> node;
    int numberOfNodes;
public:
    Graph(int n) {
        numberOfNodes = n;
        node.resize(numberOfNodes, vector<int>());
    }

    void add_edge(int u, int v) {
        node[u].push_back(v);
        node[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
        queue<int> nodeQueue;
        vector<bool> isVisited(numberOfNodes, false);
        vector<int> distance(numberOfNodes, -1);

        nodeQueue.push(start);
        isVisited[start] = true;
        distance[start] = 0;

        while(!nodeQueue.empty()) {
            int curNode = nodeQueue.front();
            nodeQueue.pop();

            for (int i = 0; i < node[curNode].size(); ++i) {
                int nextNode = node[curNode][i];
                if(!isVisited[nextNode]) {
                    nodeQueue.push(nextNode);
                    isVisited[nextNode] = true;
                    distance[nextNode] = distance[curNode] + 6;
                }
            }
        }

        return distance;
    }
};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

