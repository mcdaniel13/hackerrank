// author: Moongee Cho
// date: 03/01/2019

#include <iostream>

using namespace std;

int fibonacciInternal(int first, int second, int n, int round) {
    if(round <= n) {
        return fibonacciInternal(second, first + second, n, round + 1);
    } else {
        return first + second;
    }
}

int fibonacci(int n) {
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacciInternal(0, 1, n, 3);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}