#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n;
bool col[N], st1[N * 2], st2[N * 2];

int ret;
vector<int> path;

void dfs(int x)
{
    if(x > n)
    {
        ret++;
        if(ret <= 3)
        {
            for(auto x : path) cout << x << " ";
            cout << endl;
        }
        return;
    }

    for(int y = 1; y <= n; y++)
    {
        // 判断能不能摆在这一列
        if(col[y] || st1[y - x + n] || st2[y + x]) continue; // 剪枝
        col[y] = st1[y - x + n] = st2[y + x] = true;
        path.push_back(y);
        dfs(x + 1);
        col[y] = st1[y - x + n] = st2[y + x] = false;
        path.pop_back();
    }
}

int main()
{
    cin >> n;

    dfs(1);

    cout << ret << endl;

    return 0;
}