/*
问题描述
在一个神秘的世界中，存在着一个称为"异或森林"的地方。异或森林中的每个树木都拥有独特的力量。肖恩进入了这片森林，
他得到了一个任务：找出数组中满足条件的连续子数组，使得连续子数组中所有元素异或运算结果的因数个数为偶数。完成任务将揭示宝藏的所在地。
现在，你能告诉肖恩有多少个连续子数组满足条件吗？

注意：0 的因数个数视为奇数。

输入描述
第一行输入一个数字 n 表示数组元素个数。

第二行输入 n 个数字，第 i 个数字 a[i] 表示数组的第 i 个元素。

数据保证 1≤n≤10^4 ，1≤a[i]≤n 。

输出描述
输出一个数字表示满足条件的连续子数组的数量。

样例输入
5
1 2 3 4 5

样例输出
7*/
#include <iostream>
using namespace std;
const int N = 1e5 + 9;
int a[N], pre[N], cnt[N];
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

    cnt[0] = 1;
    int ans = n * (n + 1) / 2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 200; j++)
        {
            int sq = j * j;
            ans -= cnt[pre[i] ^ sq];
        }
        cnt[pre[i]]++;
    }
    cout << ans << '\n';
    return 0;
}