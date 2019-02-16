// author: Moongee Cho
// date: 01/27/2019
// problem URL: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
    static int comparator(Player a, Player b)  {
        if(a.score > b.score) {
            Player temp = a;
            a = b;
            b = temp;
        } else if (a.score == b.score) {
            if(a.name < b.name) {
                Player temp = a;
                a = b;
                b = temp;
            } else {
                return -1;
            }
        } else {
            return -1;
        }

        return 0;
    }
};

bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}