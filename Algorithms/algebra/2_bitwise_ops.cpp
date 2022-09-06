#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long

#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string varname, Args &&...values)
{
    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

void solve()
{
    ll x;
    scanf("%lld", &x);
    ll n = ceil(log2((float)x));
    int bin[n];
    debug(n);
    Fo(i, n - 1, -1)
    {
        if (x & (1LL << i))
        {
            printf("%d", 1);
            bin[(n - 1) - i] = 1;
        }
        else
        {
            printf("%d", 0);
            bin[(n - 1) - i] = 0;
        }
    }
    printf("\n");
    fo(i, n) printf("%d", bin[i]);
}
int main()
{
    cin.tie(NULL);
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