// author: Moongee Cho
// date: 03/04/2019
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int findSuperDigit(string n) {
    long sum = 0;
    for (int i = 0; i < n.length(); ++i) {
        sum += n[i] - '0';
    }
    return sum % 9;
}

int superDigit(string n, int k) {
    k = k % 9;

    if (k == 0)
        return 9;

    int subDigitSum = findSuperDigit(n);
    int superDigit = (subDigitSum * k) % 9;

    if(superDigit == 0)
        return 9;
    else
        return superDigit;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
