/*
问题描述
丽丽的家里建了两座宝石塔高度为 N 的宝石塔，宝石塔每一层都有一颗独特的宝石，且宝石的亮度各不相同。

阿鹏决定美化这些宝石。他可以在两个宝石塔的任意两层交换宝石，交换的次数没有限制。他想通过交换，使得他收集到的第一个宝石塔的宝石亮度差异（最亮的宝石的亮度减去最暗的宝石的亮度）尽可能小。

请你帮助阿鹏，找出最小的亮度差异值。

输入格式
第一行输入一个整数 N（1≤N≤10^3），表示两座宝石塔的层数。

第二行输入 N 个空格分隔的整数 A1,A2,…,AN（1≤Ai≤10^5），表示第一个宝石塔每一层宝石的亮度。

第三行输入 N 个空格分隔的整数 B1,B2,…,BN（1≤Bi≤10^5），表示第二个宝石塔每一层宝石的亮度。

输出格式
输出一行，表示最小的亮度差异值。

样例输入
4
2 1 4 3
3 2 6 2

样例输出
1*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans;
    cin >> n;
    vector<int> arr(n * 2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n + i];
    }
    sort(arr.begin(), arr.end());
    ans = arr[n - 1] - arr[0];
    cout << ans << '\n';
    return 0;
}