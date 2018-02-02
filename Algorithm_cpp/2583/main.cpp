#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {
    int r;
    int c;
};
int m, n, k, cnt, ans[10001];
int x1, x2, y1, y2;
int map[100][100];
bool visit[100][100];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
Point p1, p2;

void colouring(Point p1, Point p2) {
    int finish_r = m - p1.r;
    int finish_c = n - p1.c;
    int start_r = m - p2.r;
    int start_c = n - p2.c;
    
    for(int i=start_r; i<finish_r; i++) {
        for(int j=start_c; j<finish_c; j++) {
            map[i][j] = 1;
        }
    }

}
void dfs(int r, int c) {
    map[r][c] = 1;
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(0 <= nr && nr < m && 0 <= nc && nc < n) {
            if(visit[nr][nc] == false && map[nr][nc] == 0) {
                visit[nr][nc] = true;
                map[nr][nc] = 1;
                ans[cnt]++;
                dfs(nr, nc);
            }
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> m >> n >> k;
    for(int i=0; i<k; i++) {
        cin >> p1.c >> p1.r >> p2.c >> p2.r;
        colouring(p1, p2);
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 0) {
                ans[cnt] = 1;
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    sort(ans, ans+cnt);
    for(int i=0; i<cnt; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
 
    return 0;
}
