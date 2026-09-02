/*
问题描述
二进制王国是一个非常特殊的国家，因为该国家的居民仅由 0 和 1 组成。

在这个国家中，每个家庭都可以用一个由 0 和 1 组成的字符串 S 来表示，例如 101、000、111 等。

现在，国王选了出 N 户家庭参加邻国的庆典。为了符合王国的审美标准，我们需要选择一种排队顺序，使得最终形成的队伍在字典序上是最小的。

国王将这个任务交给了你，请你解决这个问题。

输入格式
第一行包含一个整数 N(1 ≤N≤2×10^5)，代表二进制家庭数量。

接下来输入 N 行，第 i 行输入一个二进制字符串 Si 表示第 i​​ 户家庭。

数据范围保证：∑i=1~n∣Si∣≤2×10^5 ，其中∣Si∣表示第 i 个字符串的长度。

输出格式
输出一行一个字符串，表示字典序最小的排队情况。

输入样例
3
111
000
101

输出样例
000101111

说明
字典序最小的排队应该是 S2S3S1 ，形成的队伍为 000101111。*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(const string& s1, const string& s2)
{
    return s1 + s2 < s2 + s1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}