// author: Moongee Cho
// date: 02/25/2019

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    vector<vector<int>> node(graph_nodes, vector<int>());
    for (int i = 0; i < graph_from.size(); ++i) {
        node[graph_from[i] - 1].push_back(graph_to[i] - 1);
        node[graph_to[i] - 1].push_back(graph_from[i] - 1);
    }

    queue<int> nodeQueue;
    vector<bool> isVisited(graph_nodes, false);
    vector<int> dist(graph_nodes, 0);
    int minDistance = -1;

    auto it = find(ids.begin(), ids.end(), val);
    int start;

    if(it != ids.end())
        start = distance(ids.begin(), it);
    else {
        cout << minDistance << endl;
        return minDistance;
    }

    nodeQueue.push(start);
    isVisited[start] = true;
    dist[start] = 0;

    while(!nodeQueue.empty()) {
        int curNode = nodeQueue.front();
        nodeQueue.pop();

        for (int i = 0; i < node[curNode].size(); ++i) {
            int nextNode = node[curNode][i];
            if(!isVisited[nextNode]) {
                nodeQueue.push(nextNode);
                isVisited[nextNode] = true;
                dist[nextNode] = dist[curNode] + 1;
                if(ids[nextNode] == val) {
                    minDistance = dist[nextNode];
                    cout << minDistance << endl;
                    return minDistance;
                }
            }
        }
    }

    cout << minDistance << endl;
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
