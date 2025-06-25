/*
问题描述

wzy 给你了一个n×n 的01 矩阵a，你需要求一下满足ai,j​=ai,k=aj,k=1
的三元组(i,j,k) 的个数。

注：给定的矩阵一定满足ai,j=aj,i。
同时，(1,2,3),(3,2,1) 这种视作同一个三元组，且i≠j,j≠k,i≠k。

输入格式
第一行输入一个数字n，表示矩阵大小。(1≤n≤800)

接来下n行，每行一个长度为n的01串。

输出格式
输出满足条件的三元组数量。

样例输入
4
0011
0011
1101
1110

样例输出
2*/
#include <bits/stdc++.h>
using namespace std;
int a[2010][2010];
char s[2010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &s);
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] == 1 && a[i][j] == a[i][k] && a[i][j] == a[j][k]) {
                    ans++;
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}