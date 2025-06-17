/*
问题描述
给定按从小到大的顺序排列的数字1到n，
随后对它们进行m次操作，每次将一个数字x移动到数字y之前或之后。
请输出完成这m次操作后它们的顺序。

输入格式
第一行为两个数字n,m，表示初始状态为1到n的从小到大排列，后续有m次操作。

第二行到第m+1行，每行三个数x,y,z。
当z=0 时，将x移动到y之后；当z=1时，将x移动到y之前。

输出格式
一行，n个数字，中间用空格隔开，表示m次操作完成后的排列顺序。

样例输入
5 3
3 1 0
5 2 1
2 1 1

样例输出
2 1 3 5 4

说明/提示
n≤1e4，m≤1e4。*/
#include <iostream>
using namespace std;
const int N = 2e5 + 9;
int e[N], p[N], head, tail;

void del(int x)
{
    if (e[x] == -1)
    {
        e[p[x]] = -1;
    }
    else
    {
        e[p[x]] = e[x];
        p[e[x]] = p[x];
    }
}

void insert_front(int y, int x)
{
    e[x] = y, p[x] = p[y], p[e[x]] = x, e[p[x]] = x;
}

void insert_back(int y, int x)
{
    if (e[y] == -1)
    {
        e[y] = x;
        p[x] = y;
        e[x] = -1;
    }
    else
    {
        e[x] = e[y];
        p[x] = y;
        e[y] = x;
        p[e[x]] = x;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        e[i] = i + 1;
        p[i] = i - 1;
    }
    e[0] = 1, e[n] = -1;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z)
        {
            del(x);
            insert_front(y, x);
        }
        else
        {
            del(x);
            insert_back(y, x);
        }
    }

    for (int i = e[0]; i != -1; i = e[i])
    {
        cout << i << " ";
    }
    return 0;
}