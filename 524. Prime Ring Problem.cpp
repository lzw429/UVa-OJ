#include <iostream>

using namespace std;
bool vis[40];
bool isP[40];
int a[40], n;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)return false;
    }
    return true;
}

void DFS(int cur) { // cur的范围是1到n，n是递归边界
    if (cur == n && isP[a[0] + a[n - 1]]) {
        for (int i = 0; i < n; ++i) {
            if (i != 0)cout << " ";
            cout << a[i];
        }
        cout << endl;
    } else {
        for (int i = 2; i <= n; i++) // 尝试填数
            if (!vis[i] && isP[i + a[cur - 1]]) {
                vis[i] = true;
                a[cur] = i;
                DFS(cur + 1);
                vis[i] = false;
            }
    }
}

int main() {
    int cases = 0;
    while (cin >> n && n >= 0) {
        if (cases)cout << endl;
        cout << "Case " << ++cases << ":" << endl;
        for (int i = 2; i <= 2 * n; ++i) {
            // 循环到2*n的原因是，需要判断素数环中两个数字的和是否为素数
            isP[i] = isPrime(i);
        }
        a[0] = 1;
        DFS(1);
    }
    return 0;
}
