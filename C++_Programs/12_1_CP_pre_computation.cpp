#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    Given a number N calculate its factorial for T test cases
    1 <= N <= 10e5
    1 <= T <= 10e5
    Solve in linear time complexity - O(n)
    Print ans modulo M, M = 10^9 + 7
*/
int n = (10e5 + 10);
long long M = 10e9 + 7;

int main()
{

    vector<int> fact(n);
    fact[0] = fact[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << fact[x] << endl;
    }
    return 0;
}