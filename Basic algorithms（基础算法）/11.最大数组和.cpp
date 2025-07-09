/*
问题描述
小明是一名勇敢的冒险家，他在一次探险途中发现了一组神秘的宝石，
这些宝石的价值都不同。但是，他发现这些宝石会随着时间的推移逐渐失去价值，
因此他必须用规定的次数对它们进行处理。

小明想要最大化这些宝石的总价值。他有两种处理方式：

选出两个最小的宝石，并将它们从宝石组中删除。
选出最大的宝石，并将其从宝石组中删除。
现在，给你小明手上的宝石组，请你告诉他用规定的次数，
最大化宝石的总价值是多少。

输入格式
第一行包含一个整数 t，表示数据组数。

对于每组数据，第一行包含两个整数 n 和 k，表示宝石的数量和规定的处理次数。

第二行包含 n 个整数a1,a2,...,an ，表示每个宝石的价值。

输出格式
对于每组数据，输出一个整数，表示用规定的次数，能够最大化宝石的总价值。

样例输入
6
5 1
2 5 1 10 6
5 2
2 5 1 10 6
3 1
1 2 3
6 1
15 22 12 10 13 11
6 2
15 22 12 10 13 11
5 1
999999996 999999999 999999997 999999998 999999995

样例输出
21
11
3
62
46
3999999986

样例说明
在第一个测试用例中，两个最小值是 1 和 2，去掉它们，数组为[5，10，6]，和为 21。
而最大值为 10，去掉它，则数组为 [2,5,1,6]，和为 14。
最优的操作为执行一次操作一，得到最好的答案为 21。

在第二个测试用例中，最优的处理结果先删除两个最小值，然后再删除一个最大值。

评测数据规模
对于100% 的评测数据，1≤t≤10,3≤n≤2⋅10^5 ,1≤k≤99999,2k<n。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

//贪心不可
/*void solve()
{
  int n,k,i,zjl;
  cin>>n>>k;
  vector<int> sz;
  for(i=1;i<=n;i++)
  {
    cin>>zjl;
    sz.push_back(zjl);
  }
  sort(sz.begin(),sz.end());
  for(i=1;i<=k;i++)
  {
    if(sz[0]+sz[1]<=sz[sz.size()-1])
    {
      sz.erase(sz.begin(), sz.begin()+2);
    }
    else sz.pop_back();
  }
  long long sum=0;
  for(const int& j:sz)
  {
    sum+=j;
  }
  cout<<sum<<'\n';
}*/

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), sum(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }

    ll ans = 0;
    int pos = 0;
    while (k >= 0)
    {
        ans = max(ans, sum[n - k] - sum[pos]);
        pos += 2;
        k--;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}