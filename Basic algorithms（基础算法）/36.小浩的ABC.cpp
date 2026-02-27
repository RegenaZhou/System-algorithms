/*
问题描述
小浩有一个整数 X，他想找到一个三元组 (A,B,C)​ 满足：
1≤A,B,C≤10^6 。
A⋅B+C=X​。
在满足条件的情况下让 (B,C,A)​ 的字典序最小，如果不存在这样的三元组输出 −1​。

输入格式
第一行输入一个正整数 T 表示测试数据的组数。

接下来 T 行每行输入一个整数 X​ 如题所述。

输出格式
对于每组测试数据，输出 A,B,C 的值，如果不存在这样的三元组输出 −1，并换行。

样例输入1
4
1
15
2
100

样例输出1
-1
14 1 1
1 1 1
99 1 1

说明
样例 1：可以证明没有这样的三元组存在。

样例 2：考虑 A=14,B=1,C=1，满足：1≤A,B,C≤10^6 。A⋅B+C=2⋅7+1=15=X。没有比 (1,1,14) 更小的三元组。

样例 3：考虑 A=1,B=1,C=1，满足：1≤A,B,C≤10^6 ​。A⋅B+C=1⋅1+1=2=X。没有比 (1,1,1) 更小的三元组。

评测数据规模
对于所有的评测数据，1≤T≤2×10^5 ，1≤X≤10^12 。*/
#include <iostream>
using namespace std;
using ll = long long;
void solve()
{
    ll x;
    cin >> x;
    if (x == 1)
    {
        cout << "-1\n";
        return;
    }
    else if (x <= 1e6 + 1)
    {
        cout << x - 1 << " " << "1 1\n";
    }
    else
    {
        ll a = 1e6, b, c;
        b = x / a;
        c = x % a;
        cout << a << " " << b << " " << c << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}