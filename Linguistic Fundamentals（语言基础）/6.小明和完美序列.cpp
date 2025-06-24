/*
问题描述
小明又新学了一个概念，叫做完美序列。一个仅包含数字序列被称为完美序列，
当且仅当数字序列中每个数字出现的次数等于这个数字。比如(1)，(2,2,3,3,3)。
空序列也算。现在小明得到了一个数字序列，
他想知道最少要删除多少个数字才能使得这个数字序列成为一个完美序列。

输入格式
输入包括两行。

第一行一个整数n，表示数字序列中数字的个数。

第二行，包括n个整数，是数字序列中具体的每个数字。

输出格式
输出一个整数，表示最少要删除的数字个数。

样例输入
6
3 3 3 1 13 15

样例输出
2

评测数据规模
对于所有评测数据，1≤n≤10^5,ai≤10^9。*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<int, int> mp;
    int n, i, num;
    long sum = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> num;
        //if(!mp.count(num)) mp[num]=0;
        mp[num]++;
    }
    for (const auto& pair : mp)
    {
        if (pair.first > pair.second) sum += pair.second;
        else sum += pair.second - pair.first;
    }
    cout << sum << '\n';
    return 0;
}
