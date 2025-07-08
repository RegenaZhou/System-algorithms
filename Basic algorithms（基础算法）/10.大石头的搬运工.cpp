/*
问题描述
在一款名为”大石头的搬运工“的游戏中，玩家需要操作一排 n 堆石头，进行 n−1 轮游戏。

每一轮，玩家可以选择一堆石头，并将其移动到任意位置。

在n−1 轮移动结束时，要求将所有的石头移动到一起（即所有石头的位置相同）即为成功。

移动的费用为石头的重量乘以移动的距离。例如，如果一堆重量为 2 的石头
从位置 3 移动到位置 5，那么费用为2×(5−3)=4。

请计算出所有合法方案中，将所有石头移动到一起的最小费用。

可能有多堆石头在同一个位置上，但是一轮只能选择移动其中一堆。

输入格式
第一行一个整数 n，表示石头的数量。

接下来 n 行，每行两个整数 wi 和pi，分别表示第 i 堆石头的重量和初始位置。

输出格式
输出一个整数，表示最小的总移动费用。

样例输入
3
2 3
3 1
1 5

样例输出
8

说明
一种最优的移动方式是：

首先，将第一个石头移动到位置 1，费用为2×(3−1)=4；

然后，将第三个石头移动到位置 1，费用为1×(5−1)=4。

所以最小的总移动费用为4+4=8。

数据范围
对于20% 的测试样例，1≤n≤10^3。

对于100% 的测试样例，1≤n≤10^5 ，1≤wi,pi≤10^6。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e5 + 7;
#define fi first
#define se second

ll pre[N], suf[N];

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.se < b.se;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a.begin() + 1, a.end(), cmp);

    ll s = 0;

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + s * (a[i].se - a[i - 1].se);
        s += a[i].fi;
    }

    s = 0;

    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + s * (a[i + 1].se - a[i].se);
        s += a[i].fi;
    }

    ll res = (ll)1e18;

    for (int i = 1; i <= n; i++)
    {
        res = min(res, pre[i] + suf[i]);
    }

    cout << res << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}