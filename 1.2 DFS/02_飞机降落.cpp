#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int n;
int t[N], d[N], l[N];

bool st[N]; // 标记路径中哪些飞机已经摆放过

bool dfs(int pos, int end)
{
    if(pos > n)
    {
        return true;
    }

    for(int i = 1; i <= n; i++)
    {
        if(st[i] == true) continue; // 剪枝
        if(end > t[i] + d[i]) continue; // 剪枝
        int newend = max(t[i], end) + l[i];
        st[i] = true;
        if(dfs(pos + 1, newend)) return true;
        st[i] = false; // 回复现场
    }

    return false;
}

int main()
{
    int T; cin >> T;

    while(T--) // 多组测试数据的时候，一定要注意清空数据
    {
        memset(st, 0, sizeof st);
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> t[i] >> d[i] >> l[i];

        if(dfs(1, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}