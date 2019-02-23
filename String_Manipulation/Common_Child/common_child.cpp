// author: Moongee Cho
// date: 01/31/2019

#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    vector<vector<int>> commonChildMax(s1.length() + 1, vector<int> (s2.length() + 1, 0));

    for (int i = 1; i <= s1.length(); ++i) {
        for (int j = 1; j <= s2.length(); ++j) {
            if(s1[i - 1] == s2[j - 1]) {
                commonChildMax[i][j] = commonChildMax[i - 1][j - 1] + 1;
            } else {
                commonChildMax[i][j] = max(commonChildMax[i - 1][j], commonChildMax[i][j - 1]);
            }
        }
    }
    return commonChildMax[s1.length()][s2.length()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
