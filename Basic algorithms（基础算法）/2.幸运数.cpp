/*
问题描述
小蓝认为如果一个数含有偶数个数位，
并且前面一半的数位之和等于后面一半的数位之和，
则这个数是他的幸运数字。
例如 2314 是一个幸运数字, 因为它有 4 个数位, 并且
2+3=1+4 。现在请你帮他计算从 1 至 100000000 之间共有多少个不同的幸运数字。

答案提交
这是一道结果填空的题，你只需要算出结果后提交即可。
本题的结果为一个整数，在提交答案时只填写这个整数，
填写多余的内容将无法得分。*/
#include <iostream>
using namespace std;
int len(int x)
{
    int v = 0;
    while (x)
    {
        v++;
        x /= 10;
    }
    return v;
}
int check(int x)
{
    int t = len(x);
    if (t % 2 == 1) return 0;
    int n = 0;//记录当前是倒数第几位
    int l = 0, r = 0;
    while (x)
    {
        n++;
        int b = x % 10;
        if (n * 2 <= t) r += b;
        else l += b;
        x /= 10;
    }
    return l == r;
}
int main()
{
    int ans=0;
    for(int i=1;i<=100000000;i++)
    {
      if(check(i))
      {
        ans++;
      }
    }
    cout<<ans<<'\n';
    //cout << 4430091 << '\n';
    return 0;
}