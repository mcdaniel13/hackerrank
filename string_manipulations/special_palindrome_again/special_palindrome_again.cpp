// author: Moongee Cho
// date: 01/31/2019

#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long palindromeCount = n;

    for (int i = 0; i < s.length(); ++i) {
        char startChar = s[i];
        int numOfChar = -1;
        for (int j = i + 1; j < s.length(); ++j) {
            char endChar = s[j];
            if(startChar == endChar) {
                if(numOfChar == -1 || (numOfChar - i) == (j - numOfChar)) {
                    palindromeCount++;
                }
            } else {
                if(numOfChar == -1) {
                    numOfChar = j;
                } else {
                    break;
                }
            }
        }
    }
    cout << palindromeCount << endl;
    return palindromeCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}