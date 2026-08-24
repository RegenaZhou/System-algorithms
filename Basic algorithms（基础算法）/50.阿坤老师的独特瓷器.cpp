/*
问题描述
阿坤老师是一位热爱中国传统文化的老师，特别喜欢收藏各种各样的瓷器。他有一个习惯，就是在每一个瓷器底部都标注上瓷器的直径 d 和高度 h。

一天，阿坤老师突然想整理一下自己的瓷器收藏。他有一个特别的定义：“独特瓷器”，即对于一个瓷器 A，如果不存在另一个瓷器 B ，
其直径和高度都严格大于瓷器 A 的直径和高度，则称瓷器 A 为“独特瓷器”。

阿坤老师有 N 个瓷器，每个瓷器都有一个直径和高度。请你帮助阿坤老师，计算出他的瓷器收藏中有多少个“独特瓷器”。

输入格式
输入的第一行包含一个整数 N（1≤N≤10^5）。

接下来的 N 行，每行包含两个整数，分别表示瓷器的直径 d 和高度 h（1≤d,h≤10^6）。

输出格式
输出一个整数，表示阿坤老师的瓷器收藏中“独特瓷器”的数量。

样例输入
5
3 4
5 6
2 5
3 7
6 5

样例输出
3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
struct Node
{
    int d, h;
};
bool cmp(Node& x, Node& y)
{
    if (x.d == y.d) return x.h < y.h;
    return x.d < y.d;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Node> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].d >> arr[i].h;
    }

    sort(arr.begin(), arr.end(), cmp);

    int ans = 1, th = arr[n - 1].h;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i].d == arr[n - 1].d) ans++;
        else if (arr[i].h >= th)
        {
            ans++;
            th = arr[i].h;
        }
    }

    cout << ans << '\n';
    return 0;
}