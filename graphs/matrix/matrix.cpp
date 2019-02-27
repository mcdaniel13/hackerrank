// author: Moongee Cho
// date: 02/28/2019

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Node {
    vector<int> end;
    vector<int> weight;
};

void dfs(const int &start,const int &prevStart, vector<vector<long>> &findMinCount, vector<bool> &isMachine, vector<Node> &nodes) {
    long long count = 0;
    for(int i = 0; i < nodes[start].end.size(); ++i) {
        int end = nodes[start].end[i];
        int weight = nodes[start].weight[i];
        if(end == prevStart)
            continue;
        dfs(end, start, findMinCount, isMachine, nodes);
        count += min(weight + findMinCount[1][end], findMinCount[0][end]);
    }

    if(isMachine[start]) {
        findMinCount[1][start] = count;
        findMinCount[0][start] = LONG_MAX;
        return;
    }

    findMinCount[0][start] = count;
    for (int i = 0; i < nodes[start].end.size(); ++i) {
        int end = nodes[start].end[i];
        int weight = nodes[start].weight[i];
        if(end != prevStart) {
            long first = findMinCount[1][start];
            long second = (long) count + findMinCount[1][end] - min(findMinCount[1][end] + (long) weight, findMinCount[0][end]);
            findMinCount[1][start] = min(first, second);
        }
    }
}

int minTime(vector<vector<int>> roads, vector<int> machines, int n) {
    vector<Node> nodes(n);
    vector<bool> isMachine(n, false);
    vector<vector<long>> findMinCount(2, vector<long>(n, INT_MAX));

    for (int i = 0; i < roads.size(); ++i) {
        nodes[roads[i][0]].end.push_back(roads[i][1]);
        nodes[roads[i][0]].weight.push_back(roads[i][2]);
        nodes[roads[i][1]].end.push_back(roads[i][0]);
        nodes[roads[i][1]].weight.push_back(roads[i][2]);
    }

    for (int i = 0; i < machines.size(); ++i) {
        isMachine[machines[i]] = true;
    }

    dfs(machines[0], -1, findMinCount, isMachine, nodes);

    int minCount =  min(findMinCount[0][machines[0]], findMinCount[1][machines[0]]);

    return minCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines, n);

    fout << result << "\n";

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
