/*
��������
С����һ���Ȱ��Ķ��������ˣ�����һ��С��ͼ��ݡ�
Ϊ���ܹ����������鼮��棬����Ҫһ����������¼ͼ�����Ϣ��ִ�����ֲ�����
���ͼ��add �Ͳ�������find��

��ʼС��û���飬����n��������
add �������������ַ���bookname,author����ʾ��ӵ�ͼ��ͼ���������ߣ�
find ��������һ���ַ���author������Ҫ���С����ͼ��������author�ж��ٱ�ͼ�顣

�����ʽ
��һ��һ������n����ʾ��n��������

֮��n�У���������������Ĳ���������������

�������ַ�������len ������10��

�����ʽ
��ÿһ��find ����������Ҫ������������С����ͼ����ж��ٱ��飬
ע����������������ǲ�ͬ���������ͬʱ��ͬ���߿��ܳ���ͬ�����顣

��������
7
find author1
add book1 author1
find author1
add book1 author1
find author1
add book1 author2
find author2

�������
0
1
2
1

�������ݹ�ģ
1��n��1000,1��len��10��*/
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