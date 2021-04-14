#include <bits/stdc++.h>
#include <stdint.h>
#define int long long
#define ld long double
#define fi first
#define se second
#define vll vector<int>
#define pii pair<int, int>
#define pb push_back
#define sz(v) (int)(v).size()
#define inf (int)(1e18)
#define md (int)(998244353)
#define all (v)(v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
using namespace std;

const int M = 1e6 + 10;
int ex(int a, int b = md - 2)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % md;
        a = (a * a) % md, b /= 2;
    }
    return ans;
}

inline int add(int a, int b)
{
    a += b;
    if (a >= md)
        a -= md;
    return a;
}

inline int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += md;
    return a;
}

inline int mul(int a, int b)
{
    return (a * b) % md;
}

int dp[M], dp1[M];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[1] = dp1[1] = 0;
    dp[2] = dp1[2] = 0;

    rep(i, 2, M)
    {
        int A = ex(i - 1), B = mul(A, 2);
        int now = sub(dp[i - 1], dp[i / 2]);
        now = mul(now, B);
        if (i % 2 == 0)
            now = add(now, mul(A, sub(dp[i / 2], dp[i / 2 - 1])));
        dp1[i] = mul(now, 2);
        now = add(now, 1);
        dp[i] = now;

        dp1[i] = add(dp1[i], mul(i - 1 - i / 2, B));
        if (i % 2 == 0)
            dp1[i] = add(dp1[i], A);
        now = sub(dp1[i - 1], dp1[i / 2]);
        now = mul(now, B);
        if (i % 2 == 0)
            now = add(now, mul(A, sub(dp1[i / 2], dp1[i / 2 - 1])));
        dp1[i] = add(dp1[i], now);
        dp[i] = add(dp[i], dp[i - 1]);
        dp1[i] = add(dp1[i], dp1[i - 1]);
    }
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        cout << (sub(dp1[n], dp1[n - 1]) + sub(dp1[m], dp1[m - 1]) + 2 * mul(sub(dp[n], dp[n - 1]), sub(dp[m], dp[m - 1]))) % md << "\n";
    }
}