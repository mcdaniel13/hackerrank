// author: Moongee Cho
// date: 01/20/2019
// problem URL: https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    unordered_set<char> map;
    for(int i = 0; i < s1.length(); i++) {
        map.insert(s1[i]);
    }

    int isYes = false;
    for(int i = 0; i < s2.length(); i++) {
        unordered_set<char>::iterator it = map.find(s2[i]);
        if(it != map.end()) {
            isYes = true;
            break;
        }
    }

    if(isYes) {
        string result = "YES";
        return result;
    }
    else {
        string result = "NO";
        return result;
    }


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
