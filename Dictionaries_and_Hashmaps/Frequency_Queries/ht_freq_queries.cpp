// author: Moongee Cho
// date: 01/24/2019
// problem URL: https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> dataMap;
    map<int, int> freqMap;
    vector<int> res;
    for (int i = 0; i < queries.size(); ++i) {
        if(queries[i][0] == 1) {
            map<int, int>::iterator it = dataMap.find(queries[i][1]);
            if(it != dataMap.end() && dataMap[queries[i][1]] > 0) {
                freqMap[dataMap[queries[i][1]]]--;
            }
            dataMap[queries[i][1]]++;
            freqMap[dataMap[queries[i][1]]]++;
        } else if(queries[i][0] == 2) {
            map<int, int>::iterator it = dataMap.find(queries[i][1]);
            if(it != dataMap.end() && dataMap[queries[i][1]] > 0) {
                freqMap[dataMap[queries[i][1]]]--;
                dataMap[queries[i][1]]--;
                freqMap[dataMap[queries[i][1]]]++;
            }
        } else {
            map<int, int>::iterator it = freqMap.find(queries[i][1]);
            if(it != freqMap.end()) {
                if(freqMap[queries[i][1]] != 0) {
                    res.push_back(1);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(0);
            }
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
