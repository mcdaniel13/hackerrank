// author: Moongee Cho
// date: 01/30/2019

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int deleteCount = 0;
    map<char, int> isExisted;

    for (int i = 0; i < a.length(); ++i) {
        isExisted[a[i]]++;
    }

    for (int i = 0; i < b.length(); ++i) {
        isExisted[b[i]]--;
    }


    for (map<char, int>::iterator it = isExisted.begin(); it != isExisted.end(); ++it) {
        deleteCount += abs(it->second);
    }

    cout << deleteCount << endl;
    return deleteCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
