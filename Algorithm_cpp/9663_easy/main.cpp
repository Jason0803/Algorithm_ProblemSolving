#include <iostream>
#define MAX 15
using namespace std;
int n, result;
bool map[MAX][MAX];
bool check(int r, int c) {
    // 아래로 (row 증가)
    int nr, nc;
    for(nr=0; nr<n; nr++){
        if(nr == r) continue;
        if(map[nr][c]) return false;
    }
    // 좌상
    nr = r-1;
    nc = c-1;
    while(0 <= nr && 0 <= nc){
        if(map[nr][nc])
            return false;
        nr--;
        nc--;
    }
    // 우상
    nr = r - 1;
    nc = c + 1;
    while(0 <= nr && nc < n) {
        if(map[nr][nc])
            return false;
        nr--;
        nc++;
    }
    return true;
}
void solve(int r) {
    if(r == n) {
        result++;
    }
    for(int c=0; c<n; c++) {
        map[r][c] = true;
        if(check(r,c))
            solve(r+1);
        map[r][c] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    solve(0);
    cout << result << '\n';
    return 0;
}
