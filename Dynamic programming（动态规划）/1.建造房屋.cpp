/*
问题描述
小蓝和小桥是两位年轻的建筑师，他们正在设计一座新的城市。

在这个城市中，有 N 条街道，每条街道上都有 M 个位置可以建造房屋（一个位置只能建造一个房屋）。建造一个房屋的费用为 1 元，小蓝和小桥共有 K 元的建造预算。

现在，他们想知道，一共有多少种建造方案，满足以下要求：

在每条街道上，至少建一个房屋。
建造的总成本不能超过 K 元。
由于方案数可能很大，他们只需要输出答案对 10^9+7 取模的结果。

输入格式
一行三个整数 N,M（1≤N,M≤50）和 K（1≤K≤N⋅M），分别表示街道数、街道的位置数和预算。

输出格式
一个整数，表示满足条件的建造方案数对 10^9+7 取模的结果。

样例输入
2 3 5

样例输出
8*/
#include<iostream>
using namespace std;
using ll = long long;
ll n, m, k, t = 0, a, b, x;
const ll N = 55;
const ll q = 1e9 + 7;
ll dp[N][2505];
int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= k && (k - j >= n - i); j++)
        {
            for (ll l = 1; l <= j - i + 1 && l <= m; l++)
            {
                dp[i][j] += (dp[i - 1][j - l]) % q;
                dp[i][j] %= q;
            }
        }
    }
    for (ll i = n; i <= k; i++)
    {
        t += dp[n][i];
        t %= q;
    }
    cout << t << '\n';

    return 0;
}
