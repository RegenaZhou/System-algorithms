﻿/*
问题描述
小蓝想要给她的女朋友小桥买一份生日礼物，她来到了一家礼品店。
在店里，她看中了 N 件物品，每件物品都有一个价格 Ai 。

小蓝手中有 K 元钱和一张 50% 的折扣券，可以在购买任意一件物品时使用。
使用折扣券后，购买该物品的价格为原价的一半向上取整。

对于一件价值为 X 的物品，当小蓝使用折扣卷后，他只需要花费 ⌈x2⌉ 元即可带走该商品。

请帮助小蓝确定，在使用折扣券的情况下，她最多能够购买多少件物品送给小桥作为生日礼物。

输入格式
第一行是两个整数 N 和 K，分别表示物品的数量和小蓝手中的预算。

接下来一行是 N 个整数，表示每个物品的价格Ai 。

数据范围保证：1≤N≤10^5 ，1≤Ai≤10^9 ，0≤K≤10^9 。

输出格式
输出一个整数，表示在使用折扣券的情况下，小蓝最多可以购买多少件物品作为生日礼物。

样例输入
5 10
3 1 3 4 5

样例输出
4

说明
对于样例，我们可以买下前 4 个物品，对第 4 个物品使用优惠卷，
总共需要花费 9 元。*/
#include <iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (k >= a[i])
        {
            k -= a[i];
            ans++;
        }
        else
        {
            if (k >= (a[i] + 1) / 2)
            {
                ans++;
            }
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}