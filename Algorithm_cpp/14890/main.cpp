#include<iostream>
#include<algorithm>
using namespace std;
int n, l, a[101][101], b[101][101], ans;
void check(int row, int a[101][101]) {
    bool c[101] = { false, };
    int temp = a[row][0];
    for (int i = 0; i < n; i++) {
        if (a[row][i] != temp) {
            if (abs(a[row][i] - temp) > 1) return;  //차이가 1보다 클경우
            if (a[row][i] < temp) {                 //다음것이 나보다 작을 경우(오른쪽 경사로)
                int num = -1;
                for (int j = i; j <= i + l - 1; j++) {
                    if (j >= n || c[j]) return;
                    c[j] = true;
                    if (num == -1) {
                        num = a[row][j];
                        continue;
                    }
                    if (num != -1 && a[row][j] != num) return;
                }
                i = i + l - 1;
                if (i >= n) break;
            }
            else {                                  //다음것이 나보다 큰 경우(왼쪽 경사로)
                int num = -1;
                for (int j = i - 1; j >= i - l; j--) {
                    if (j < 0 || c[j]) return;
                    c[j] = true;
                    if (num == -1) {
                        num = a[row][j];
                        continue;
                    }
                    if (num != -1 && a[row][j] != num) return;
                }
            }
            temp = a[row][i];
        }
    }
    ++ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    for (int i = 0; i < n; i++) {
        check(i, a);
        check(i, b);
    }
    cout << ans << endl;
    return 0;
}
