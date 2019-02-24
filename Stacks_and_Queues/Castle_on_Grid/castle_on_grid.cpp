// author: Moongee Cho
// date: 02/25/2019

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void print(vector<string> grid, int distance, int newX, int newY) {
    for (int i = 0; i < grid.size(); ++i) {
        cout << grid[i] << endl;
    }
    cout << "distance = " << distance << endl;
    cout << "x = " << newX << " y = " << newY << endl;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX,
                 int goalY) {
    queue<int> distance;
    queue<pair<int, int>> location;
    location.push(make_pair(startX, startY));
    distance.push(0);
    grid[startX][startY] = 'X';

    vector<pair<int, int>> move;
    move.push_back(make_pair(-1, 0));
    move.push_back(make_pair(0, 1));
    move.push_back(make_pair(1, 0));
    move.push_back(make_pair(0, -1));

    while (!location.empty()) {
        pair<int, int> current = location.front();

        if (current.first == goalX && current.second == goalY) {
            cout << distance.front() << endl;
            return distance.front();
        }

        for (int i = 0; i < move.size(); ++i) {
            int newX = current.first + move[i].first;
            int newY = current.second + move[i].second;

            while (newX >= 0 && newX < grid.size() && newY >= 0 &&
                   newY < grid.size() && grid[newX][newY] != 'X') {
                location.push(make_pair(newX, newY));
                int newDist = distance.front() + 1;
                distance.push(newDist);
                grid[newX][newY] = 'X';
                // print(grid, newDist, newX, newY);

                newX += move[i].first;
                newY += move[i].second;
            }
        }

        location.pop();
        distance.pop();
    }

    return 0;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end =
            unique(input_string.begin(), input_string.end(),
                   [](const char &x, const char &y) { return x == y and x == ' '; });

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

    splits.push_back(
            input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
