// author: Moongee Cho
// date: 02/24/2019

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long largestRectangle(vector<int> h) {
    stack<int> hStack;
    int area = 0;
    int maxArea = 0;

    h.push_back(0);

    for (int i = 0; i < h.size(); ++i) {
        if(hStack.empty() || h[i] >= h[hStack.top()]) {
            hStack.push(i);
        } else {
            while(h[i] < h[hStack.top()]) {
                int j = hStack.top();
                hStack.pop();
                if(hStack.empty()) {
                    area = h[j] * i;
                    maxArea = max(maxArea, area);
                    break;
                } else {
                    area = h[j] * (i - hStack.top() - 1);
                    maxArea = max(maxArea, area);
                }
            }
            hStack.push(i);
        }
    }

    cout << maxArea << endl;
    return maxArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
