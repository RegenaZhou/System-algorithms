/*
题目描述
给定一个长度为 N 数组 a 和一个长度为 M 的数组 b。

请你求出它们的最长公共子序列长度为多少。

输入描述
输入第一行包含两个整数 N,M，分别表示数组 a 和 b 的长度。

第二行包含 N 个整数 a1,a2,...,an。

第三行包含 M 个整数 b1,b2,...,bn。

1≤N,M≤10^3，1≤ai,bi≤10^9。

输出描述
输出一行整数表示答案。

输入输出样例
示例 1
输入

5 6
1 2 3 4 5
2 3 2 1 4 5

输出

4*/
#include <iostream>

using namespace std;

int arr1[1009],arr2[1009];
int dp[1009][1009];
 
int main()
{
    int N,M;
    cin>>N>>M; 
    for(int i=1;i<=N;i++)cin>>arr1[i];
    for(int i=1;i<=M;i++)cin>>arr2[i];
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(arr1[i]==arr2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else 
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    
    cout<<dp[N][M]<<endl;
    return 0;
}
