// author: Moongee Cho
// date: 03/01/2019
#include <bits/stdc++.h>

using namespace std;

long flippingBits(long n) {
    long logMax = 0xFFFFFFFF;
    n ^= logMax;

    cout << n << endl;
    return n;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
