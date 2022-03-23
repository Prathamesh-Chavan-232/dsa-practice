#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N = 10e7 + 10;
vector<int> v(N, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);   // input
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout); // output
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        v[val]++;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int value;
        cin >> value;
        cout << value << " ";
        cout << v[value] << endl;
    }
    return 0;
}