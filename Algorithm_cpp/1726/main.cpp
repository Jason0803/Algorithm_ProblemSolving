#include <iostream>
#include <queue>
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4
#define MAX_SIZE 101
using namespace std;
typedef struct _Point {
    int r, c, dir;
    int cnt;
}Point;
Point Dept, Dest;
queue<Point> q;
int N, M, ans;
int map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE][5];
int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};
int opp(int _dir) {
    if(_dir == EAST) return WEST;
    else if(_dir == WEST) return EAST;
    else if(_dir == SOUTH) return NORTH;
    else return SOUTH;
}
void input() {
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin >> map[i][j];
    
    cin >> Dept.r >> Dept.c >> Dept.dir;
    Dept.cnt = 0;
    cin >> Dest.r >> Dest.c >> Dest.dir;
    q.push(Dept);
}
void dfs() {
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();
        
        if(r == Dest.r && c == Dest.c && dir == Dest.dir) {
            ans = cnt;
            break;
        }
        
        for(int i=1; i<=3; i++) {
            int nr = r + dr[dir]*i;
            int nc = c + dc[dir]*i;
            if(nr < 1 || nr > N || nc < 1 || nc > M) break;
            if(map[nr][nc] == 1) break;
            if(check[nr][nc][dir]) continue;
            check[nr][nc][dir] = true;
            q.push(Point{nr,nc,dir,cnt+1});
        }
        
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
    dfs();
    cout << ans << '\n';
    return 0;
}
