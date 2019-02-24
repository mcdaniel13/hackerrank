// author: Moongee Cho
// date: 01/27/2019
// problem URL: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void print(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
    cout<<endl;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    vector<int> ArrayCalculateMedian(expenditure.begin(), expenditure.begin() + d);
    int WarningCount = 0;
    sort(ArrayCalculateMedian.begin(), ArrayCalculateMedian.end());

    for (int i = d; i < expenditure.size(); ++i) {
        if(i > d) {
            int popVal = expenditure[i - d - 1];
            int pushVal = expenditure[i - 1];
            vector<int>::iterator low = lower_bound(ArrayCalculateMedian.begin(), ArrayCalculateMedian.end(), popVal);
            ArrayCalculateMedian.erase(low);

            vector<int>::iterator up = upper_bound(ArrayCalculateMedian.begin(), ArrayCalculateMedian.end(), pushVal);
            ArrayCalculateMedian.insert(up, pushVal);

        }

        double median;
        if(d % 2 != 0) {
            median = ArrayCalculateMedian[d / 2];
        } else {
            median = (ArrayCalculateMedian[d / 2 - 1] + ArrayCalculateMedian[d / 2]) / 2.0;
        }
        //cout << "median = " << median << endl;
        if(expenditure[i] >= median * 2) {
            WarningCount++;
        }
    }
    cout << "WarningCount = " << WarningCount << endl;
    return WarningCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
