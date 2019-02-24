// author: Moongee Cho
// date: 02/25/2019

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    stack<int> indexStack;
    stack<int> numOfDaysToDieStack;

    indexStack.push(0);
    numOfDaysToDieStack.push(-1);

    int maxNumberOfDaysToDie = INT_MIN;
    for (int i = 1; i < p.size(); ++i) {
        int numberOfDaysToDie = 1;
        while(!indexStack.empty() && p[indexStack.top()] >= p[i]) {
            numberOfDaysToDie = max(numberOfDaysToDie, numOfDaysToDieStack.top() + 1);
            indexStack.pop();
            numOfDaysToDieStack.pop();
        }

        if(indexStack.empty())
            numberOfDaysToDie = -1;

        indexStack.push(i);
        numOfDaysToDieStack.push(numberOfDaysToDie);
        maxNumberOfDaysToDie = max(numberOfDaysToDie, maxNumberOfDaysToDie);
    }

    cout << (maxNumberOfDaysToDie > 0 ? maxNumberOfDaysToDie : 0) << endl;
    return maxNumberOfDaysToDie > 0 ? maxNumberOfDaysToDie : 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

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
