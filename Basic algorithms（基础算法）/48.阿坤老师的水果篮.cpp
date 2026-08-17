/*
问题描述
阿坤老师是个非常有特色的人，他有一种独特的水果篮布局方式。他的水果篮中有 N 种不同的水果，每种水果可能有一个或多个。
阿坤老师的特殊之处在于，他每天会从篮子里挑选出最甜和最酸的水果，并且将同样口味的所有水果全部吃掉。他认为这样做可以平衡口感，也能保持健康。

每种水果的味道阿坤老师都用一个正整数表示，数值越大表示水果越甜，数值越小表示水果越酸，同一个数值表示口感相同的水果。

现在，阿坤老师告诉你他的水果篮里一开始有哪些水果（每个水果用一个正整数表示）。
请你帮他计算出，如果他按照上述的方式吃掉所有最甜和最酸的水果后，篮子里剩下的所有水果的口感之和是多少。

输入格式
第一行包含一个整数 N（3≤N≤10^4），表示阿坤老师的水果篮中总共有多少个水果。

第二行包含 N 个整数，分别表示阿坤老师水果篮中的每个水果的口感值。水果的口感值在 1∼10^4 之间。数据保证水果篮中至少有 3 种不同口感的水果。

输出格式
输出一个整数，表示阿坤老师吃掉所有最甜和最酸的水果后，篮子里剩下的所有水果的口感之和。

样例输入
5
1 1 2 2 3

样例输出
4*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int maxn = 0, minn = 10009, maxc = 0, minc = 0, num;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        if (num > maxn)
        {
            maxn = num, maxc = 1;
        }
        else if (num == maxn)
        {
            maxc++;
        }

        if (num < minn)
        {
            minn = num, minc = 1;
        }
        else if (num == minn)
        {
            minc++;
        }
    }

    sum = sum - maxn * maxc - minn * minc;
    cout << sum << '\n';
    return 0;
}