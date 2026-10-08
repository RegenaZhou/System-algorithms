/*
题目描述
小明是蓝桥王国的勇士，他晋升为蓝桥骑士，于是他决定不断突破自我。

这天蓝桥首席骑士长给他安排了 N 个对手，他们的战力值分别为 a1,a2,...,an，且按顺序阻挡在小明的前方。对于这些对手小明可以选择挑战，也可以选择避战。

作为热血豪放的勇士，小明从不走回头路，且只愿意挑战战力值越来越高的对手。

请你算算小明最多会挑战多少名对手。

输入描述
输入第一行包含一个整数 N，表示对手的个数。

第二行包含 N 个整数 a1,a2,...,an，分别表示对手的战力值。

1≤N≤10^3，1≤ai≤10^9。

输出描述
输出一行整数表示答案。

输入输出样例
示例
输入

6
1 4 3 2 5 6

输出

4*/
#include<iostream>
using namespace std;
int n;
int a[1010];
int dp[1010];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    int t=0;
    for(int j=i-1;j>=0;j--)
    {
      if(a[i]>a[j])
      {
        t=max(t,dp[j]);
      }
      dp[i]=t+1;
    }
    ans=max(ans,dp[i]);
  }
  cout<<ans<<'\n';
  return 0;
}
