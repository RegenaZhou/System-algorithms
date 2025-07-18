/*
问题描述
鸡哥在“无尽的夏日”购物节上看中了一系列的商品，这些商品的价格各不相同。
然而，鸡哥的购物车有一条特殊的规则：购物车中的商品数量必须是偶数个。

鸡哥希望在满足购物车规则的前提下，选择总价值最高的商品。
他将商品的价格列表给了你，希望你能帮他计算出他能购买到的商品的最高总价值是多少。

输入格式
第一行包含一个整数 N（ 2≤N≤10^5 ），表示商品的数量。

第二行包含 N 个整数，表示每个商品的价格Ai （−10^9≤Ai≤10^9 ）。

输出格式
输出一行，表示鸡哥能购买到的商品的最高总价值。

样例输入
5
1 2 3 4 5

样例输出
14*/
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], b[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, j = 1, k = 1;
    ll sum = 0, zjl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> zjl;
        if (zjl >= 0)
        {
            a[j] = zjl;
            sum += a[j];
            j++;
        }
        else
        {
            b[k] = zjl;
            k++;
        }
    }
    sort(a + 1, a + j);
    sort(b + 1, b + k);
    j--;
    k--;
    if (j % 2 == 0) cout << sum << '\n';
    else cout << max((sum - a[1]), (sum + b[k])) << '\n';
    return 0;
}