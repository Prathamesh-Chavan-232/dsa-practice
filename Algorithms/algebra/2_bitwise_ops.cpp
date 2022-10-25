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
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/falconcodes/prathamesh/programming/input.txt", "r", stdin);
    freopen("/home/falconcodes/prathamesh/programming/output.txt", "w", stdout);
    freopen("/home/falconcodes/prathamesh/programming/err.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}