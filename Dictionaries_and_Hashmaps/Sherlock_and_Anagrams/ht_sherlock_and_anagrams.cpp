// author: Moongee Cho
// date: 01/05/2019
// problem URL: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int anaCount = 0;
    // i = Range
    // j = point to start for substr in Range

    for (int i = 1; i < s.length(); ++i) {
        vector<string> sSub;
        for (int j = 0; j + i < s.length() + 1; ++j) {
            sSub.push_back(s.substr(j, i));
        }

        for (int j = 0; j < sSub.size(); j++) {
            sort(sSub[j].begin(), sSub[j].end());
        }

        for (int j = 0; j < sSub.size(); j++) {
            for (int k = j + 1; k < sSub.size(); ++k) {
                if (sSub[j] == sSub[k]) {
                    anaCount++;
                }
            }
        }
    }

    cout << anaCount << endl;
    return anaCount;

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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
