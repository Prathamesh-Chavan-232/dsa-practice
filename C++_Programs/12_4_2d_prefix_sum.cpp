#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    Given a 2d array of NxN, for t test cases find the sum of elements between (a,b) to (c,d)
    1 <= n <= 10^3
    1 <= t <= 10^5
*/

const int N = 10e3 + 1;
int arr[N][N];
long long pf[N][N];

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

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> arr[i][j];
            pf[i][j] = arr[i][j] + pf[i][j - 1] + pf[i - 1][j] - pf[i - 1][j - 1];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long sum = pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1];
        cout << sum << endl;
    }
    return 0;
}

// void brute()
// {
//     long long sum = 0;
//     for (int i = a; i <= c; ++i)
//     {
//         for (int j = b; j <= d; ++j)
//         {
//             sum += arr[i][j];
//         }
//     } // time complexity -> O(n^3) = O(10^11)
// }