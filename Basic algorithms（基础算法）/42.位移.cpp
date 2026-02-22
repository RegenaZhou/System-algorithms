/*
问题描述
在一个神奇的玩具世界中，有两个小朋友，小明和小红，他们喜欢玩数字游戏。一天，他们发现了一种神奇的数字变换能力，只需使用位移运算（>> 和 <<）就能将一个数字变成另一个数字。

小明和小红决定进行一场数字变换的挑战。他们选定了两个数字 a 和 b ，并尝试通过位移运算将数字 a 变成数字 b 。他们非常兴奋，想知道是否存在一系列的位移操作可以实现这个目标。

他们开始思考，并设计了各种位移操作的组合，希望能够将数字 a 变成数字 b 。如果他们成功找到一种操作组合，则输出 Yes ，否则输出 No 。

现在，让我们来帮助小明和小红解决这个数字变换的挑战，看看他们是否能够成功通过位移运算将数字 a 变成数字 b 。

左移和右移的运算规则为：逻辑左移，高位丢弃，低位补 0；逻辑右移，高位补 0，低位丢弃。如 0000100，逻辑左移 1 位为 0001000 ；逻辑右移 1 位为 0000010 。（需着重注意左移高位的变化）

输入描述
第一行输入一个数字 t ，表示有 t 组测试数据。

接下来又 t 行输入，每行包含两个数字 a 和 b ，a 和 b 意义如题目所述。

数据保证 1≤t≤10^6 ,0≤a,b≤10^9  。

输出描述
对于每一组测试数据，输出 Yes 或 No 。

样例输入
5
1 20
7 7
3 5
30 254
114 514

样例输出
No
Yes
No
No
No*/
#include <iostream>
#include <string>
using namespace std;
string func(int num)
{
    string s;
    while (num)
    {
        if (num & 1)break;
        num >>= 1;
    }
    while (num)
    {
        s += (num & 1 ? '1' : '0');
        num >>= 1;
    }
    return s;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    string s1 = func(m), s2 = func(n);
    if (s1.find(s2) != -1)
    {
        cout << "Yes" << '\n';
    }
    else
    {
        cout << "No" << '\n';
    }
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