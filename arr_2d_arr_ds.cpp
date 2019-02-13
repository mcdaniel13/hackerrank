// author: Moongee Cho
// date: 01/04/2019
// problem URL: https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    
    for(int i = 0; i < 4; i++) {
        int x = i;
        for (int j = 0; j < 4; j++) {
            int y = j;
            int findSum = arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1] + arr[x+2][y] + arr[x+2][y+1] + arr[x+2][y+2];
            maxSum = max(maxSum, findSum);
        }
    }
    
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int result = hourglassSum(arr);
    
    fout << result << "\n";
    
    fout.close();
    
    return 0;
}
