/*
问题描述
小蓝是一个热爱阅读的年轻人，他有一个小型图书馆。
为了能够管理他的书籍库存，他需要一个程序来记录图书的信息并执行两种操作：
添加图书add 和查找作者find。

初始小蓝没有书，给出n个操作。
add 操作给出两个字符串bookname,author，表示添加的图书图书名和作者；
find 操作给出一个字符串author，你需要输出小蓝的图书馆里这个author有多少本图书。

输入格式
第一行一个整数n，表示有n个操作。

之后n行，给出操作及后面的参数，如题所述。

给出的字符串长度len 不超过10。

输出格式
对每一个find 操作，你需要输出这个作者在小蓝的图书馆有多少本书，
注意是书的数量，不是不同书的数量，同时不同作者可能出现同名的书。

样例输入
7
find author1
add book1 author1
find author1
add book1 author1
find author1
add book1 author2
find author2

样例输出
0
1
2
1

评测数据规模
1≤n≤1000,1≤len≤10。*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<string, int> mp;
    int n, i;
    string a, b, c;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a;
        if (a == "find")
        {
            cin >> c;
            if (!mp.count(c)) cout << 0 << '\n';
            else cout << mp[c] << '\n';
        }
        else if (a == "add")
        {
            cin >> b >> c;
            mp[c]++;
        }
    }
    return 0;
}