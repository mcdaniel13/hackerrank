// author: Moongee Cho
// date: 03/04/2019

#include <bits/stdc++.h>

using namespace std;

void print(vector<string> result) {
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}

vector<string> finalCrossword;

void solve(const vector<string> &crossword, const vector<string> &word, int n) {
    if(n == word.size()) {
        finalCrossword = crossword;
        return;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if ((j == 0 || crossword[i][j - 1] != '-') && j + word[n].length() <= 10 && (j + word[n].length() == 10 || crossword[i][j + word[n].length()] != '-')) {
                int rowLength = 0;
                for (int k = j; k < j + word[n].length(); ++k) {
                    if (crossword[i][k] == '-' || crossword[i][k] == word[n][k - j])
                        rowLength++;
                    else
                        break;
                }
                if(rowLength == word[n].length()) {
                    vector<string> crosswordBuffer = crossword;
                    for (int k = j; k < j + word[n].length(); ++k) {
                        crosswordBuffer[i][k] = word[n][k - j];
                    }
                    print(crosswordBuffer);
                    solve(crosswordBuffer, word, n + 1);
                }
            }
            if ((i == 0 || crossword[i - 1][j] != '-') && i + word[n].length() <= 10 && (i + word[n].length() == 10 || crossword[i + word[n].length()][j] != '-')) {
                int colLength = 0;
                for (int k = i; k < i + word[n].length(); ++k) {
                    if (crossword[k][j] == '-' || crossword[k][j] == word[n][k - i])
                        colLength++;
                    else
                        break;
                }
                if (colLength == word[n].length()) {
                    vector<string> crosswordBuffer = crossword;
                    for (int k = i; k < i + word[n].length(); ++k) {
                        crosswordBuffer[k][j] = word[n][k - i];
                    }
                    print(crosswordBuffer);
                    solve(crosswordBuffer, word, n + 1);
                }
            }
        }
    }
}


// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> word;
    string wordBuffer = "";
    for (int i = 0; i < words.size(); ++i) {
        if(words[i] != ';')
            wordBuffer.push_back(words[i]);
        else {
            word.push_back(wordBuffer);
            wordBuffer.clear();
        }
    }
    word.push_back(wordBuffer);

    solve(crossword, word, 0);
    print(finalCrossword);

    return finalCrossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
