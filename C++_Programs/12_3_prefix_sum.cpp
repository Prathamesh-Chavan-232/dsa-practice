#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

    int a[n + 1], pf[n + 1];
    a[0] = pf[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long sum = pf[r] - pf[l - 1];
        cout << sum << endl;
    }
    return 0;
}
