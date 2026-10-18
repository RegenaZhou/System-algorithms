/*
问题描述
构造王国一年一度的构造大赛又开始了，这次构造王国的国王将只给定两个数字 k 和 n ，需要大家回答出能构造多少个符合以下条件的序列：

序列的长度为 n 。
1≤a1≤a2≤a3≤......≤an≤k。
ai 是 ai−1 的倍数（ i≥2 ）。
由于答案可能非常大，你需要对 10^9+7 取模。

输入格式
输入一行包括两个空格分隔的整数 k 和 n 。

数据范围保证：1≤n,k≤2000 。

输出格式
输出一个整数表示答案，答案需要对 10^9+7 取模。

样例输入
2 2

样例输出
3

说明
样例中符合条件的序列有[1,1]，[1,2]，[2,2] 总共三种。*/
#include <iostream>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll dp[2005][2005];

int main()
{
    int N,K;
    ll ans=0;
    cin>>K>>N;
    for(int i=1;i<=K;i++)dp[1][i]=1;
    for(int i=2;i<=N;i++)
    { 
        for(int j=1;j<=K;j++)
        {
            for(int k=1;k*k<=j;k++)
            {
                if(k*k==j)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                } 
                else if(j%k==0)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j/k]+dp[i-1][k])%mod;
                } 
            }    
        } 
    }    
    
    for(int i=1;i<=K;i++)
    {
        ans=(ans+dp[N][i])%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
