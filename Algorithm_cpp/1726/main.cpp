#include <iostream>
#include <queue>
#define MAX_SIZE 100
using namespace std;
typedef struct _Point {
    int r, c;
    int dir;
    int cnt;
}Point;
Point dept, dest;
int n, m, ans;
int map[MAX_SIZE+1][MAX_SIZE+1];
bool check[MAX_SIZE+1][MAX_SIZE+1][5];
int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};
queue<Point> q;
void input() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];
        }
    }
    cin >> dept.r >> dept.c >> dept.dir;
    dept.cnt = 0;
    cin >> dest.r >> dest.c >> dest.dir;
}
int opp(int _dir) {
    if(_dir == 1) return 2;
    else if(_dir == 2) return 1;
    else if(_dir == 3) return 4;
    else return 3;
}
void bfs() {
    q.push(dept);
    check[dept.r][dept.c][dept.dir] = true;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();
        if(r == dest.r && c == dest.c && dir == dest.dir) {
            ans = cnt;
            break;
        }
        // 1. Go K
        int nr, nc;
        for(int i=1; i<=3; i++) {
            nr = r + dr[dir]*i;
            nc = c + dc[dir]*i;
            if(nr < 1 || nr > n || nc < 1 || nc > m) break;
            if(map[nr][nc]) break;
            if(check[nr][nc][dir]) continue;
            check[nr][nc][dir] = true;
            q.push(Point{nr,nc,dir,cnt+1});
        }
        
        // 2. Turn Dir
        for(int i=1; i<=4; i++) {
            if(i == dir || i == opp(dir)) continue;
            if(check[r][c][i]) continue;
            check[r][c][i] = true;
            q.push(Point{r,c,i,cnt+1});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    input();
    bfs();
    cout << ans << '\n';
    return 0;
}
