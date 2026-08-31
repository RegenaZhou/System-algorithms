/*
问题描述
新一在蓝桥云课赚了一些钱，今天他决定去外面吃顿大餐。他来到了一家餐厅，这家餐厅的菜单上有 N 种菜品。菜单上的第 i 道菜属于类型 Ai ，需要 Bi 的时间来烹饪。

新一想要享受一顿完整的大餐。因此，他的大餐中应该至少包含 K 种不同的菜品类型。他点的所有菜品的烹饪时间之和，就是他等待食物的总时间。

请你帮助新一找出享受一顿完整大餐所需的最短时间，或者告诉他无法做到的话。

输入格式
第一行包含两个由空格分隔的整数 N 和 K，分别表示菜单上的菜品数量和一顿完整大餐中需要的不同菜品类型的数量。

第二行包含 N 个由空格分隔的整数，第 i 个整数是 Ai，表示菜单上的第 i 道菜品的类型。

第三行包含 N 个由空格分隔的整数，第 i 个整数是 Bi，表示烹饪菜单上的第 i 道菜品所需的时间。

数据范围保证：1≤N,K≤10^5，1≤Ai,Bi≤10^5。

输出格式
对于每个测试用例，输出一行包含一个整数，表示新一享受一顿完整大餐所需的最短时间。

如果无法享受一顿完整的大餐，输出−1。

样例输入
3 3
1 2 3
1 2 3

样例输出
6*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
struct Node
{
    int a, b;
};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<Node> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].a;
    for (int i = 0; i < n; i++) cin >> arr[i].b;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i].a) == mp.end())
        {
            mp[arr[i].a] = arr[i].b;
        }
        else
        {
            mp[arr[i].a] = min(mp[arr[i].a], arr[i].b);
        }
    }

    vector<int> cnt;
    for (const auto& item : mp)
    {
        cnt.push_back(item.second);
    }

    sort(cnt.begin(), cnt.end());

    ll ans = 0;
    if (cnt.size() < k) ans = -1;
    else
    {
        for (int i = 0; i < k; i++)
        {
            ans += cnt[i];
        }
    }
    cout << ans << '\n';

    return 0;
}