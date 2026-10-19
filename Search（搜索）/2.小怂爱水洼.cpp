/*
问题描述
小怂喜欢收集水洼中的水，他每到一个水量不为零的小水洼中就会收集里面的所有水。

小怂去到了一个大小为 N×M 的水洼上，水洼上的每一块小水洼水量为 ai,j (i∈[1,n],j∈[1,m])。
小怂的起始点是水洼中水量不为 0 的任意一个小水洼。假设小怂的起始点是 (1,1)，他可以移动无数次，
每次移动只能移动到当前水洼上下左右四个方向的相邻小水洼上，并且需要满足相邻小水洼水量大于 0，即如果新的小水洼水量为零，小怂就不能走到这个小水洼上。
特别地，小怂可以重复走到某块小水洼，但是小水洼中的水只能被收集一次；如果起始点的水洼中有水，他会收集那些水。

值得注意的是：每块上下左右相连且水量不为 0 的小水洼会合成一块大水洼，小怂每到一块新的大水洼，他之前收集到的水量会变为 0。

求解小怂在大水洼中可以收集到的最大水量。

输入格式
第一行是两个整数 N,M，分别表示行数、列数。

接下来 N 行，每行包含 M 个整数，每个整数表示当前位置的小水洼的水量。

数据范围保证：1≤N,M≤100，1≤ai,j≤10^6，(数据不保证起始点不为0)。

输出格式
输出共 1 行，一个整数，表示小怂在水洼中可以收集到的最大水量。

样例输入
3 3
1 2 0
3 4 0
0 0 5

样例输出
10

样例解释
由题意得，样例中有两个大水洼。

第一个大水洼由 (1,1)，(1,2)，(2,1)，(2,2) 四个小水洼组成，水量总和为 10。

第二个大水洼由 (3,3) 一个小水洼组成，水量总和为 5。

因此小怂在大水洼中可以获得的最大水量是 10。*/
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> arr, vis;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
ll tmp, ans = 0;

void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (arr[x][y] == 0 || vis[x][y] == 1) return;
    vis[x][y] = 1;
    tmp += arr[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    arr.resize(n, vector<int>(m, 0));
    vis.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0 || vis[i][j] == 1) continue;
            tmp = 0;
            dfs(i, j);
            ans = max(ans, tmp);
        }
    }

    cout << ans << '\n';
    return 0;
}
