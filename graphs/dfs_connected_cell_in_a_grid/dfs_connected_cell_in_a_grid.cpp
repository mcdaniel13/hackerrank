// author: Moongee Cho
// date: 02/26/2019

#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &isVisited, int x, int y) {
    int regionCount = 0;
    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && !isVisited[x][y]) {
        if(grid[x][y] != 0) {
            regionCount = 1;
            isVisited[x][y] = true;
            regionCount += dfs(grid, isVisited, x + 1, y);
            regionCount += dfs(grid, isVisited, x - 1, y);
            regionCount += dfs(grid, isVisited, x, y + 1);
            regionCount += dfs(grid, isVisited, x, y - 1);
            regionCount += dfs(grid, isVisited, x + 1, y + 1);
            regionCount += dfs(grid, isVisited, x + 1, y - 1);
            regionCount += dfs(grid, isVisited, x - 1, y + 1);
            regionCount += dfs(grid, isVisited, x - 1, y - 1);
        } else {
            isVisited[x][y] = true;
        }
    }

    return regionCount;
}

int maxRegion(vector<vector<int>> grid) {
    vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), false));
    int regionCount = 0;
    int maxRegion = INT_MIN;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if(!isVisited[i][j] && grid[i][j] != 0) {
                regionCount = dfs(grid, isVisited, i, j);
            } else if (grid[i][j] == 0) {
                isVisited[i][j] = true;
            }
            maxRegion = max(maxRegion, regionCount);
            regionCount = 0;
        }
    }

    cout << maxRegion << endl;
    return maxRegion;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
