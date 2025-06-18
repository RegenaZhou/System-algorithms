/*
问题描述
小蓝有一个长度为n的括号串，括号串仅由字符 ( 、 ) 构成，
请你帮他判断一下该括号串是否合法，合法请输出 Yes ，反之输出 No 。

合法括号序列：
1.空串是合法括号序列。
2.若s是合法括号序列，则 (s) 也是合法括号序列。
3.若s,t都是合法括号序列，则st也是合法括号序列。

例如 ()() ， (()) ， (())() 均为合法括号序列。

输入格式
第一行包含一个正整数n，表示括号串的长度。

第二行包含一个长度为n的括号串。

输出格式
输出共1行，若括号串合法请输出 Yes ，反之输出 No 。

样例输入1
10
(()(()))()

样例输出1
Yes

样例输入2
5
()()(

样例输出2
No

评测数据规模
对于所有评测数据，1≤n≤1×10^2，括号串仅包含两种字符 ( ， ) 。*/
#include <iostream>
using namespace std;
const int N = 105;
char stk[N];
int top;
char s[N];

int main()
{
    int n;
    cin >> n;
    cin >> s + 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == ')')
        {
            if (top && stk[top] == '(')
            {
                top--;
                continue;
            }
        }
        stk[++top] = s[i];
    }
    if (top) cout << "No" << '\n';
    else cout << "Yes" << '\n';
    return 0;
}