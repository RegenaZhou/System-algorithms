/*
问题描述
小蓝有一个长度为n的数组a，现在对于每一个ai，
小蓝可以选择下面三种操作之一：
ai=ai−1
ai=ai+1
ai=ai
小蓝想知道当她把每一个ai都操作之后，数组众数的数目最大是多少。
但是小蓝并不擅长这个问题，请你帮小蓝计算所有操作完成之后数组众数的最大数目。

输入格式
第一行输入一个整数，代表n 。

第二行输入n个整数，代表a1,a2,a3,...,an。

输出格式
输出一行一个整数，代表众数的最大数目。

样例输入
3
1 2 3

样例输出
3

说明
对于样例，将a1加一，a3减一，a2不变，此时三个数都是2，
而其他操作得到的结果众数数目都小于3 ，所以最终答案是3。

评测数据规模
对于50% 的评测数据1≤n≤10^3,1≤ai≤10^4。

对于100% 的评测数据1≤n≤10^5,1≤ai≤10^9。*/
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
map<ll, ll> mp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll a, ma = 0;
    cin >> n;
    while (n--)
    {
        cin >> a;
        mp[a]++, mp[a - 1]++, mp[a + 1]++;
    }
    for (auto& x : mp)
    {
        ma = max(ma, x.second)
    }
    cout << ma << '\n';
    return 0;
}