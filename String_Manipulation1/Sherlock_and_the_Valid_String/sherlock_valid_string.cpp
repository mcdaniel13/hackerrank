// author: Moongee Cho
// date: 01/31/2019

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char,int> letterCount;
    map<int, int> removableCount;

    for (int i = 0; i < s.length(); ++i) {
        letterCount[s[i]]++;
    }

    for (map<char, int>::iterator it = letterCount.begin(); it != letterCount.end(); it++) {
        removableCount[it->second]++;
    }

    string res;
    if (removableCount.size() > 2) {
        res = "NO";
    } else if (removableCount.size() == 2) {
        map<int, int>::iterator it1 = removableCount.begin();
        map<int, int>::iterator it2 = it1++;
        int numOfLetterAppeared1 = it1->first;
        int numOfLetterAppeared2 = it2->first;
        int numOfAppearedCount1 = it1->second;
        int numOfAppearedCount2 = it2->second;

        if (abs(numOfLetterAppeared1-numOfLetterAppeared2) > 1) {
            if (numOfLetterAppeared1 > numOfLetterAppeared2 && numOfAppearedCount2 == 1) {
                res = "YES";
            } else if (numOfLetterAppeared2 > numOfLetterAppeared1 && numOfAppearedCount1 == 1) {
                res = "YES";
            } else {
                res = "NO";
            }
        } else {
            if (numOfAppearedCount1 > 1 && numOfAppearedCount2 > 1) {
                res = "NO";
            } else {
                res = "YES";
            }
        }
    } else {
        res = "YES";
    }

    cout << res << endl;
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
