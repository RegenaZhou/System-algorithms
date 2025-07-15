/*
问题描述
给定 n 副卡牌，每张卡牌具有正反面，正面朝上数字为ai ，背面朝上数字为 bi 。
一副卡牌的价值为正面朝上数字之和。一开始所有卡牌都是正面朝上的。
小蓝是蓝桥学院最优秀的魔法师，他知道所有卡牌的背面数字bi ，
他最多可以进行 k 次操作，每次可以将一副卡牌翻转，
将正面朝上的数字变为背面朝上的数字，或将背面朝上的数字变为正面朝上的数字。
请问，小蓝最多可以使卡牌的价值之和为多少？

输入格式
第一行输入两个整数 n 和 k ，表示卡牌的数量和小蓝可以操作的次数。

第二行输入 n 个整数ai ，表示所有卡牌正面的数字。

第三行输入 n 个整数bi ，表示所有卡牌反面的数字。

数据范围保证：1≤n≤1×10^5 ，1≤ai,bi,k≤10^9 。

输出格式
输出一个整数，表示可以得到的卡牌的最大价值和。

样例输入
3 1
1 2 3
3 2 1

样例输出
8

说明
将第一张卡牌翻转，此时卡牌的总和为3+2+3=8。*/
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 7;
int  zm[N], fm[N], dt[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    ll sum = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> zm[i];
        sum += zm[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> fm[i];
        dt[i] = fm[i] - zm[i];
    }
    sort(dt + 1, dt + n + 1);
    for (int i = n; i >= 1 && k > 0; i--, k--)
    {
        if (dt[i] > 0) sum += dt[i];
        else break;
    }
    cout << sum << '\n';
    return 0;
}