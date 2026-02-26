/*
问题描述
小蓝有一个无限集，该集合生成方式如下：

集合里面初始元素为 1。
如果 x 在集合中，则 x⋅a,x+b 均在集合中。
例如 a=2,b=3 时，该集合五个最小元素如下：

1。
2，因为 2=1⋅2。
4，因为 4=1+3。
5，因为 5=2+3。
7，因为 7=5+2。
现在有 t 组数据，每组数组给定你 3 个正整数 a,b,n，在 a,b 符合以上条件的情况下，你判断 n 是否在集合中。

输入格式
第一行输入一个正整数 t，表示测试案例组数。

接下来 t 行，每行输入 3 个正整数 a,b,n，由若干个空格分割，含义如题所述。

输出格式
对于每组数据，如果 n 在集合中，输出 Yes，否则输出 No。

样例输入
4
1 4 7
2 5 8
3 6 8
12 11 81

样例输出
No
Yes
No
No

评测数据规模 1≤t≤10^3 ,1≤a,b,n≤10^9 。*/
#include <iostream>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, n; cin >> a >> b >> n;
    if (a == 1)
    {
        if ((n - 1) % b == 0 && n - 1 > 0) cout << "Yes" << '\n';
        else cout << "No" << '\n';
        return;
    }
    while (n > 1)
    {
        if (n % a == 0) n /= a;
        if (n > b) n -= b;
        else break;
    }
    if (n == 1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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