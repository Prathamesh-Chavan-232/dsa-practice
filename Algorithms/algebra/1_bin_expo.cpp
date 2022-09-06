#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long

ll binpow_rec(ll a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    ll res = binpow_rec(a, n / 2);
    res *= res;
    if (n % 2 != 0)
    {
        res *= a;
    }
    return res;
}

ll binpow(ll a, int n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
            res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}
void solve()
{
    int n;
    ll a, res;
    scanf("%lld", &a);
    scanf("%d", &n);
    res = binpow(a, n);
    printf("res : %lld\n", res);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}