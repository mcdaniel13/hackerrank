#include <bits/stdc++.h>

using namespace std;

vector<int> ways;
// Complete the stepPerms function below.
int stepPerms(int n) {
    ways.resize(37);

    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;

    for(int i = 3; i <= 36; i++) {
        ways[i] = ways[i - 3] + ways[i - 2] + ways[i - 1];
    }

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
