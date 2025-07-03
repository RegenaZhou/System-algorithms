/*
问题描述
在生物学中，DNA 序列的相似性常被用来研究物种间的亲缘关系。
现在我们有两条 DNA 序列，每条序列由 A、C、G、T 四种字符组成，长度相同。
但是现在我们记录的 DNA 序列存在错误，为了严格满足 DNA 序列的碱基互补配对即
A - T 和 C - G，我们需要依据第一条 DNA 序列对第二条 DNA 序列进行以下操作：

选择第二条 DNA 序列的任意两个位置，交换他们的字符。

选择第二条 DNA 序列任意一个位置，将其字符替换为 A、C、G、T 中的任何一个。

需要注意的是：每个位置上的碱基只能被操作一次！

你的任务是通过最小的操作次数，使第二条 DNA 序列和第一条 DNA 序列互补。
并且已知初始两条 DNA 序列长度均为 N。

输入格式
第一行包含一个整数N，(1≤N≤10^3)，表示 DNA 序列的长度。

接下来的两行，每行包含一个长度为 N 的字符串，表示两条 DNA 序列。

输出格式
输出一个整数，表示让第二条 DNA 序列和第一条 DNA 序列互补所需的最小操作次数。

样例输入
5
ACGTG
ACGTC

样例输出
2

样例说明
将第二条 DNA 序列中的第一个和第四个碱基交换，
将第二个和第三个碱基交换即可完成全部配对，共操作两次。*/
#include <iostream>
#include <map>
using namespace std;
char s1[1010], s2[1010];
void solve()
{
    int n;
    cin >> n;
    cin >> s1;
    cin >> s2;
    map<pair<char, char>, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[{s1[i], s2[i]}]++;
    }
    int ans = max(mp[{'A', 'A'}], mp[{'T', 'T'}]) +
        max(mp[{'A', 'G'}], mp[{'C', 'T'}]) +
        max(mp[{'A', 'C'}], mp[{'G', 'T'}]) +
        max(mp[{'T', 'G'}], mp[{'C', 'A'}]) +
        max(mp[{'T', 'C'}], mp[{'G', 'A'}]) +
        max(mp[{'C', 'C'}], mp[{'G', 'G'}]);
    cout << ans << '\n';
}

int main()
{
    solve();
    return 0;
}