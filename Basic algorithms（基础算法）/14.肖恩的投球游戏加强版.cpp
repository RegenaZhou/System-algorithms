/*
问题描述
小羊肖恩最近喜欢上了投球游戏，但他已经不满足只有一行球筐的玩法了。

具体来说，在他面前摆放了 n×m 个球筐，这些球筐形成了一个 n×m 的矩阵，
整数 ai,j 表示第 i 行第 j 列的球筐最开始的球的个数。

接下来小羊会进行 q 次操作，每次操作会给出五个整数x1,y1,x2,y2,c，
他会将以 (x1,y1) 为左上角，(x2,y2) 为右下角的球筐矩阵都投入 c 个球。
请你输出操作完成之后每个框各有多少个球？

输入格式
第一行输入三个整数 n,m,q ，表示球筐矩阵的大小和操作次数。

接下来 n 行，每行包含 m 个整数，表示球筐矩阵。

接下来 q 行，每次输入五个整数x1,y1,x2,y2,c。

数据范围保证：1≤q≤10^5 ，1≤n,m≤10^3 ，1≤x1≤x2≤n，1≤y1≤y2≤m，
1≤ai,j,c≤10^5 。

输出格式
输出 n​ 行，每行 m 个数，表示操作完毕后每个球筐里球的个数。

样例输入
4 4 2
3 2 9 10
7 2 1 7
10 4 8 4
1 1 2 1
4 1 4 3 1
3 3 4 4 3

样例输出
3 2 9 10
7 2 1 7
10 4 11 7
2 2 6 4 */
#include <iostream>
using namespace std;
const int N = 1e3 + 7;
int a[N][N], diff[N][N];

void solve()
{
    int n, m, q;
    int i, j, k;
    cin >> n >> m >> q;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            diff[i][j] = a[i][j] - a[i][j - 1];
        }
    }
    for (i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for (j = x1; j <= x2; j++)
        {
            diff[j][y1] += c, diff[j][y2 + 1] -= c;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            a[i][j] = a[i][j - 1] + diff[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}