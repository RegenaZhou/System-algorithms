/*
题目描述
小明是蓝桥王国的骑士，他喜欢不断突破自我。

这天蓝桥国王给他安排了 N 个对手，他们的战力值分别为 a1,a2,...,an，且按顺序阻挡在小明的前方。对于这些对手小明可以选择挑战，也可以选择避战。

身为高傲的骑士，小明从不走回头路，且只愿意挑战战力值越来越高的对手。

请你算算小明最多会挑战多少名对手。

输入描述
输入第一行包含一个整数 N，表示对手的个数。

第二行包含 N 个整数 a1,a2,...,an，分别表示对手的战力值。

1≤N≤3×10^5，1≤ai≤10^9。

输出描述
输出一行整数表示答案。

输入输出样例
示例 1
输入

6
1 4 2 2 5 6

输出

4*/
#include<iostream>
using namespace std;
const int N = 1e6;
int  arr[N], up[N];
int main()
{
    ios::sync_with_stdio, cin.tie(0), cout.tie(0);
    int n, len = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > up[len]) up[++len] = arr[i];
        else
        {
            int pos = upper_bound(up + 1, up + 1 + len, arr[i]) - up;
            up[pos] = arr[i];
        }
    }
    cout << len << '\n';
    return 0;
}