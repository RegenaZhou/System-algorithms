/*
问题描述
小蓝最近在学习位运算，由于他的数学不好，于是他去请教小桥，希望能得到小桥的指点。

小桥出了一道练习题：

给定 n 个正整数序列。
定义 xorl,r=al⊕al+1⊕...⊕ar−1⊕ar，⊕ 为异或运算符号。
求 ∏i=1n∏j=inxori,j 对 1e9+7 取模的值。
输入格式
第一行一个正整数 n。

第二行 n 个正整数 a1,a2,a3,...,an。

输出格式
输出一个正整数，表示 ∏i=1n∏j=inxori,j 对 1e9+7 取模的值。

样例输入
3
5 27 17

样例输出
10327500

评测数据规模
对于 100% 的评测数据，1≤n≤10^6 ,1≤ai<8192。*/
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e6 + 4;
const int mood = 1e9 + 7;
ll a[N], pre[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i];
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ll num = pre[i - 1] ^ pre[j];
            if (num == 0)
            {
                cout << 0;
                return 0;
            }
            ans = ans * (num) % mood;
        }
    }
    cout << ans << '\n';

    return 0;
}