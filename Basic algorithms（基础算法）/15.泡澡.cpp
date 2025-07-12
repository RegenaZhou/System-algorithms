/*
问题描述
在一个寒冷的冬天，有 N 个人想要去澡堂泡澡，第 i 个人会在时间段[Si,Ti)
（不包括Ti）内每分钟使用 Pi 升热水。由于该澡堂设备简陋，无法存储热水。
热水器在每分钟最多能提供 W 升热水。现在请问该澡堂能否满足这 N 个人的泡澡需求，
如果可以请输出Yes，否则输出No。

输入格式
第一行包含两个整数 N 和 W，表示洗澡的人数和热水器的容量。

接下来 N 行，每行包含三个整数Si ，Ti 和Pi（0≤Si<Ti≤2×10^5 ，
1≤W,Pi≤10^9），表示第 i 个人的洗澡计划。其中 Si 和 Ti 表示
计划的开始时间和结束时间，Pi 表示每分钟需要的热水量。

输出格式
如果可以按照所有人的计划供应热水，则输出Yes，否则输出No。

样例输入
2 5
1 3 3
2 3 3

样例输出
No

样例说明
在时间段[2,3) 分钟内，第 1 个人需要 3 升热水，第 2 个人也需要 3 升热水，
总共需要 6 升热水，此时热水器无法满足。*/
#include <iostream>
using namespace std;
using ll = long long;
const ll N = 2e5 + 7;
ll a[N], diff[N];

void solve()
{
    ll n, w, ma = 0;
    bool flag = true;
    cin >> n >> w;
    for (ll i = 1; i <= n; i++)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        ma = max(ma, r);
        diff[l] += v, diff[r] -= v;
    }
    for (ll i = 0; i <= ma; i++)
    {
        if (i == 0) a[i] = diff[i];
        else a[i] = a[i - 1] + diff[i];
        if (a[i] > w)
        {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}