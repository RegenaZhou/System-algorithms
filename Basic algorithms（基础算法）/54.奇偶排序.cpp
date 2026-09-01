/*
问题描述
小蓝所在的王国名为偶数王国，在他们王国中数字的比较通常按以下步骤进行：

如果两个数字的奇偶性不同，那么偶数一定大于奇数。
如果两个数字的奇偶性相同，则比较它们的实际数值大小。
现在给你一个正整数数组 A，请你输出按照偶数王国规则从小到大排序后的 A。

输入格式
第一行输入一个整数 N(1≤N≤10^3) 表示数组 A 的长度。

第二行输入 N 个整数 A1,A2,A3,⋯,AN(1≤Ai≤10^5) 表示数组 A。

输出格式
输出一行 N 个整数表示答案。

样例输入
5
1 2 3 4 5

样例输出
1 3 5 2 4*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, num;
    cin >> n;
    vector<int> js, ys;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2) js.push_back(num);
        else ys.push_back(num);
    }

    sort(js.begin(), js.end());
    sort(ys.begin(), ys.end());

    for (const auto& tmp : js)
    {
        cout << tmp << ' ';
    }
    for (const auto& tmp : ys)
    {
        cout << tmp << ' ';
    }

    return 0;
}