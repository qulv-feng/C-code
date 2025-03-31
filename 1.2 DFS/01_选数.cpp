#include <iostream>

using namespace std;

const int N = 25;

int n, k;
int a[N];

int ret;
int path; // 记录路径中所选择的数的和

bool isprime(int x)
{
    if(x <= 1) return false;
    // 试除法
    for(int i = 2; i <= x / i; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int pos, int begin)
{
    if(pos > k)
    {
        if(isprime(path)) ret++;
        return;
    }

    for(int i = begin; i <= n; i++)
    {
        path += a[i];
        dfs(pos + 1, i + 1);
        path -= a[i]; // 恢复现场
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dfs(1, 1);

    cout << ret << endl;

    return 0;
}