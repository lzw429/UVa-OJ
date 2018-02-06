#include<iostream>

using namespace std;

int main() {
    int S[20], cases = 0, n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> S[i];
        long long ans = 0;
        for (int i = 0; i < n; i++) { // 起点
            long long v = 1;
            for (int j = i; j < n; j++) { // 终点
                v *= S[j];
                if (v > ans) ans = v;
            }
        }
        cout << "Case #" << ++cases << ": The maximum product is " << ans << ".\n\n";
    }
    return 0;
}
