// author: Moongee Cho
// date: 01/04/2019
// problem URL: https://www.hackerrank.com/challenges/ctci-array-left-rotation/copy-from/94953462?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result;
    vector<int> finalResult;
    
    for(int i = 0; i < a.size(); i++)
        result.push_back(a[i]);
    
    for(int i = 0; i < d; i++)
        result.push_back(a[i]);
    
    for(int i = d; i < result.size(); i++)
        finalResult.push_back(result[i]);
    
    return finalResult;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string nd_temp;
    getline(cin, nd_temp);
    
    vector<string> nd = split_string(nd_temp);
    
    int n = stoi(nd[0]);
    
    int d = stoi(nd[1]);
    
    string a_temp_temp;
    getline(cin, a_temp_temp);
    
    vector<string> a_temp = split_string(a_temp_temp);
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);
        
        a[i] = a_item;
    }
    
    vector<int> result = rotLeft(a, d);
    
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
        
        if (i != result.size() - 1) {
            fout << " ";
        }
    }
    
    fout << "\n";
    
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

