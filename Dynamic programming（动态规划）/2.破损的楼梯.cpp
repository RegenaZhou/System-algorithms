/*
问题描述
小蓝来到了一座高耸的楼梯前，楼梯共有 N 级台阶，从第 0 级台阶出发。小蓝每次可以迈上 1 级或 2 级台阶。但是，楼梯上的第 a1 级、第 a2 级、第 a3 级，以此类推，共 M 级台阶的台阶面已经坏了，不能踩上去。

现在，小蓝想要到达楼梯的顶端，也就是第 N 级台阶，但他不能踩到坏了的台阶上。请问他有多少种不踩坏了的台阶到达顶端的方案数？

由于方案数很大，请输出其对 10^9+7 取模的结果。

输入格式
第一行包含两个正整数 N（1≤N≤10^5）和 M（0≤M≤N），表示楼梯的总级数和坏了的台阶数。

接下来一行，包含 M 个正整数 a1,a2,…,aM（ 1≤a1<a2<a3<aM≤N），表示坏掉的台阶的编号。

输出格式
输出一个整数，表示小蓝到达楼梯顶端的方案数，对 10^9+7 取模。

样例输入
6 1
3

样例输出
4*/
#include <iostream>
using namespace std;
using ll=long long;
const int N=1e5+9;
const ll p=1e9+7;
ll dp[N];
bool broken[N];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int x;
    cin>>x;
    broken[x]=true;
  }
  dp[0]=1;
  if(!broken[1]) dp[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(broken[i]) continue;
    dp[i]=(dp[i-1]+dp[i-2])%p;
  }
  cout<<dp[n];
  return 0;
}
