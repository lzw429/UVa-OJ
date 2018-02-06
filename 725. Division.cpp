#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, cases = 0;
    while (cin >> n) {
        if (n == 0)
            return 0;
        if (cases++)cout << endl; // 题目格式要求
        char buf[15];
        int cnt = 0; // 用于记录解的个数，如果为0输出无解
        for (int fghij = 1234;; ++fghij) {
            int abcde = fghij * n;
            sprintf(buf, "%05d%05d", abcde, fghij);
            if (strlen(buf) > 10)break;
            sort(buf, buf + 10);
            bool ok = true;
            for (int i = 0; i < 10; ++i) {
                if (buf[i] != '0' + i)
                    ok = false;
            }
            if (ok) {
                cnt++;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if (!cnt)
            cout << "There are no solutions for " << n << ".\n";
    }
    return 0;
}
