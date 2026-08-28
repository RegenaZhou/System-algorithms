/*
问题描述
蓝桥镇发明了一种新的电池。当一块电池的电力是 a 时，另一块电池的电力是 b 时，两块电池产生的总电池功率是 a×b+a−b 。

现在小蓝有一个电池集合，她想知道，通过选择这个集合中的两块不同的电池，她可以产生的最大功率效果的电力是多少？

输入格式
第一行将包含 N，表示电池的数量。

第二行包含 N 个空格分隔的整数，这些整数表示电池的电力值。

数据范围保证：2≤N≤10^3 ，−10^5≤Ai≤10^5 。

输出格式
输出一行，表示小蓝可以产生的最大效率的电力。

样例输入
3
5 3 2
样例输出
17

样例说明
在测试用例中，小蓝有几种不同的选择。例如，她可以选择力量为 5 和 3 的电池，产生的电力效率的力量是 5×3+5−3=17。这是所有可能选择中最大的电力，所以输出为 17。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll ans = max(arr[0] * arr[1] + abs(arr[0] - arr[1]), arr[n - 1] * arr[n - 2] + abs(arr[n - 1] - arr[n - 2]));
    cout << ans << '\n';
    return 0;
}