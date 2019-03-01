// author: Moongee Cho
// date: 03/01/2019
#include <bits/stdc++.h>

using namespace std;

vector<int> ways;

int stepPerms(int n) {
    ways.resize(n + 3);

    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;

    if(n >= 3)
        ways[n] = stepPerms(n - 3) + stepPerms(n - 2) + stepPerms(n - 1);

    return ways[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
