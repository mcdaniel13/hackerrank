// author: Moongee Cho
// date: 01/31/2019

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    char next;
    int deletionCount = 0;

    if (s[0] == 'A') {
        next = 'B';
    } else {
        next = 'A';
    }

    for (int i = 1; i < s.length(); ++i) {
        if(s[i] != next) {
            deletionCount++;
        } else {
            if(s[i] == 'A') {
                next = 'B';
            } else {
                next = 'A';
            }
        }
    }
    cout << deletionCount << endl;
    return deletionCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
