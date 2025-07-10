/*
问题描述
小羊肖恩最近喜欢上了投球游戏，具体来说，在他面前摆放了 n 个球筐，
第 i 个框最开始有 ai 个球。

接下来小羊会进行 q 次操作，每次操作会给出三个整数 l,r,c，
会将第 l 个框到第 r 个框，都投入 c 个球。
请你输出操作完成之后每个框各有多少个球？

输入格式
第一行输入两个整数 n 和 q，表示球筐个数和操作次数。

第二行输入 n 个整数，表示每个球筐最开始的球数。

接下来 q 行，每次输入三个整数l,r,c。

数据范围保证：1≤n,q≤10^5 ，1≤l≤r≤n ，1≤ai ,c≤10^5 。

输出格式
输出一行 n 个整数，表示每个框最终的球的个数，以空格分开。

样例输入
5 3
7 5 7 7 3
1 5 3
1 5 2
4 4 4

样例输出
12 10 12 16 8*/
#include <iostream>
using namespace std;
const int N = 1e5 + 7;
int a[N], diff[N];

void solve(int n, int m)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        diff[i] = a[i] - a[i - 1];
    }
    for (i = 1; i <= m; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        diff[l] += v, diff[r + 1] -= v;
    }
    for (i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + diff[i];
    }
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}