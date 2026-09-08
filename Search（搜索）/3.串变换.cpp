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
using namespace std;
struct Option
{
    int select;
    int x;
    int y;
};

string S, T;
int N, K;
Option opt[10];
bool visit[10];
bool flag = 0;

void dfs(string s, int start)
{

    if (flag) return;

    visit[start] = true;
    int x = opt[start].x;
    int y = opt[start].y;

    if (opt[start].select == 1)
    {
        int tmp = (int)(s[x] - '0');
        tmp = (tmp + y) % 10;
        s[x] = (char)(tmp + '0');
    }
    else if (opt[start].select == 2)
    {
        swap(s[x], s[y]);
    }

    if (s == T)
    {
        flag = 1;
        return;
    }

    for (int i = 1; i <= K; i++)
    {
        string ss;
        if (i == start) continue;
        if (visit[i] == 0)
        {
            ss = s;
            dfs(ss, i);
            visit[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string temp_S;
    cin >> N;
    cin >> S >> T;
    temp_S = S;
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> opt[i].select >> opt[i].x >> opt[i].y;
    }

    for (int i = 1; i <= K; i++)
    {
        memset(visit, 0, sizeof(visit));
        temp_S = S;
        dfs(temp_S, i);
        if (flag)
        {
            cout << "Yes\n";
            break;
        }
    }
    if (flag == 0)cout << "No\n";

    return 0;
}
