// author: Moongee Cho
// date: 02/25/2019

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

void dfs(vector<vector<int>> &road, vector<bool> &visited, int city, long &numOfRoads) {
    visited[city] = true;
    for(int i = 0; i < road[city].size(); ++i) {
        int nextCity = road[city][i];
        if(!visited[nextCity]) {
            cout << city + 1 << " -> " << nextCity + 1 << endl;
            numOfRoads += 1;
            dfs(road, visited, nextCity, numOfRoads);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<vector<int>> road(n, vector<int>());
    int m = cities.size();  //number of roads;

    for (int i = 0; i < cities.size(); ++i) {
        road[cities[i][0] - 1].push_back(cities[i][1] - 1);
        road[cities[i][1] - 1].push_back(cities[i][0] - 1);
    }

    if(c_lib <= c_road) {
        return (long) c_lib * (long) n;
    }

    vector<bool> visited(n, false);
    long numOfRoads = 0;
    long numOfLibraries = 0;
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            numOfLibraries++;
            dfs(road, visited, i, numOfRoads);
        }
    }

    cout << " numOfRoads = " << numOfRoads << " numOfLibraries = " << numOfLibraries << endl;

    long minCost = numOfLibraries * (long) c_lib + numOfRoads * (long) c_road;

    cout << "minCost = " << minCost << endl;
    return minCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
