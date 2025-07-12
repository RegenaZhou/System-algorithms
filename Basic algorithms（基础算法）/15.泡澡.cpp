/*
��������
��һ������Ķ��죬�� N ������Ҫȥ�������裬�� i ���˻���ʱ���[Si,Ti)
��������Ti����ÿ����ʹ�� Pi ����ˮ�����ڸ������豸��ª���޷��洢��ˮ��
��ˮ����ÿ����������ṩ W ����ˮ���������ʸ������ܷ������� N ���˵���������
������������Yes���������No��

�����ʽ
��һ�а����������� N �� W����ʾϴ�����������ˮ����������

������ N �У�ÿ�а�����������Si ��Ti ��Pi��0��Si<Ti��2��10^5 ��
1��W,Pi��10^9������ʾ�� i ���˵�ϴ��ƻ������� Si �� Ti ��ʾ
�ƻ��Ŀ�ʼʱ��ͽ���ʱ�䣬Pi ��ʾÿ������Ҫ����ˮ����

�����ʽ
������԰��������˵ļƻ���Ӧ��ˮ�������Yes���������No��

��������
2 5
1 3 3
2 3 3

�������
No

����˵��
��ʱ���[2,3) �����ڣ��� 1 ������Ҫ 3 ����ˮ���� 2 ����Ҳ��Ҫ 3 ����ˮ��
�ܹ���Ҫ 6 ����ˮ����ʱ��ˮ���޷����㡣*/
#include <iostream>
using namespace std;
using ll = long long;
const ll N = 2e5 + 7;
ll a[N], diff[N];

void solve()
{
    ll n, w, ma = 0;
    bool flag = true;
    cin >> n >> w;
    for (ll i = 1; i <= n; i++)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        ma = max(ma, r);
        diff[l] += v, diff[r] -= v;
    }
    for (ll i = 0; i <= ma; i++)
    {
        if (i == 0) a[i] = diff[i];
        else a[i] = a[i - 1] + diff[i];
        if (a[i] > w)
        {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}