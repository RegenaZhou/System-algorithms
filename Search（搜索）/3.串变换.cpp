/*
问题描述
有两个长度为 n 的数字字符串 S,T ，下标从 0 开始。

一共有 k 个操作，操作只可能是以下两种类型：

1 x v 表示将 Sx 变为 (Sx+v)mod10；
2 x y 表示交换 Sx，Sy 。
你可以挑选出任意个操作，以任意顺序执行，但是每个操作最多只能执行一次，如果可以将 S 串变为 T 串则输出 Yes，反之输出 No。

输入格式
第一行输入一个正整数 n，表示字符串 S 和 T 的长度。

第二行输入一个长度为 n 只由数字构成的字符串 S。

第三行输入一个长度为 n 只由数字构成的字符串 T。

第四行输入一个正整数 k，表示操作的数量。

接下来 k 行，每行三个整数，其中第 i 行表示第 i 种操作的三个参数 opi, xi, yi。

输出格式
一行一个字符串：

如果可以通过操作使得 S 串与 T 串相等，则输出 Yes。
反之输出 No。
样例输入
5
01012
10103
3
2 0 1
2 3 2
1 4 1

样例输出
Yes

数据范围
对于 100% 的数据，1≤n≤10，1≤k≤7，1≤opi≤2，0≤xi,yi<n。*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

struct Node
{
    int op, x, y;
};

int n, k;
string s1, s2;
vector<Node> cz;
vector<int> vis;
bool ans = false;

void dfs()
{
    if (ans) return;

    if (s1 == s2)
    {
        ans = true;
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs();
            if (cz[i].op == 1)
            {
                s1[cz[i].x] = (char)((s1[cz[i].x] - '0' + cz[i].y) % 10 + '0');
                dfs();
                s1[cz[i].x] = (char)((s1[cz[i].x] - '0' - cz[i].y + 10) % 10 + '0');
            }
            else
            {
                char c1 = s1[cz[i].x];
                s1[cz[i].x] = s1[cz[i].y];
                s1[cz[i].y] = c1;
                dfs();
                c1 = s1[cz[i].x];
                s1[cz[i].x] = s1[cz[i].y];
                s1[cz[i].y] = c1;
            }
            vis[i] = 0;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s1 >> s2 >> k;

    cz.resize(k);
    vis.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> cz[i].op >> cz[i].x >> cz[i].y;
    }

    dfs();

    cout << (ans ? "Yes" : "No") << '\n';
    return 0;
}
