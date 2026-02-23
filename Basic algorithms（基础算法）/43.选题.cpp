/*
问题描述
肖恩需要在 n 道题中选出一套完整的比赛题集，每道题都有一个难度分数 ai 。主办方要求肖恩选的题目必须满足以下条件：

难度分数必须包含起码 3 种不同的值。

选出的题目中，最难的题和最简单的题难度分差不能小于 x 。

选出的题目难度分数的总和必须在 [l,r] 的范围内。

请计算有多少种可能的选题方式满足以上所有条件。

输入描述
第一行包括四个整数 n,l,r,x ，分别表示题目总数，难度和区间，最小难度差。

第二行包括 n 个整数，输入的第 i 个数字 a[i] 表示第 i 道题的难度。

数据保证 1≤n≤15,1≤l≤r≤10^9 ,1≤x≤10^6 ,1≤a[i]≤10^6 。

输出描述
输出一个数字表示可能的方案数。

样例输入
5 1 10 3
1 1 3 5 7

样例输出
3

说明
比如 1,1,3,5 是一个满足所有条件的方案。不同的难度一共有三种，难度和是 10 ，属于区间 [1,10] ，难度最大的 5 和难度最小的 1 差值为 4 ，大于 3 。*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
const int N = 17;
ll a[N];
set<int> t;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    ll num = (1 << n);
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        ll sum = 0, maxn = LONG_MIN, minn = LONG_MAX;
        t.clear();
        for (int j = 0; j < n; j++)
        {
            if (((i >> j) & 1) == 1)
            {
                sum += a[j];
                t.insert(a[j]);
                maxn = max(maxn, a[j]);
                minn = min(minn, a[j]);
            }
        }
        if (t.size() >= 3 && sum >= l && sum <= r && (maxn - minn) >= x) ans++;
    }
    cout << ans << '\n';

    return 0;
}