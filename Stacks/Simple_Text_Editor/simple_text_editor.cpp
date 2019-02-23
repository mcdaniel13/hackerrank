// author: Moongee Cho
// date: 02/24/2019

#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

stack<string> wStack;

void simpleTextEditor(int type, string value) {
    if(type == 1) {
        string addedString = value;
        if(!wStack.empty()) {
            addedString = wStack.top();
            addedString.append(value);
        }
        wStack.push(addedString);
    } else if(type == 2) {
        string deletedString = wStack.top();
        deletedString.erase(deletedString.end() - stoi(value), deletedString.end());
        wStack.push(deletedString);
    } else if(type == 3) {
        string printedString = wStack.top();
        char printedChar = printedString.at(stoi(value) - 1);
        cout << printedChar << endl;
    } else {
        wStack.pop();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int type;
        string value;
        cin >> type;
        if(type != 4) {
            cin >> value;
            simpleTextEditor(type, value);
        } else
            simpleTextEditor(type, "");
    }
    return 0;
}
