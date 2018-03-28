#include <iostream>
#include <queue>
#define MAX_SIZE 51
using namespace std;
typedef struct _Point {
    int r, c;
    int dir;
} Point;
Point robot;
queue<Point> q;
int N, M, ans;
int map[MAX_SIZE][MAX_SIZE];
bool cleaned[MAX_SIZE][MAX_SIZE];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
/*
 0  1 2  3
 북 동 남 서
 */
// turn = (dir+3) % 4
bool isOut(int nr, int nc) {
    return (nr < 1 || nr >= N-1 || nc < 1 || nc >= M-1);
}
int opp(int dir) {
    if(dir == 0) return 2;
    else if(dir == 1) return 3;
    else if(dir == 2) return 0;
    else return 1;
}

void dfs(Point p) {
    int r = p.r;
    int c = p.c;
    int dir = p.dir;
    cleaned[r][c] = true;
    ans++;
    
    for(int i=0; i<4; i++) {
        int ndir = (dir+3) % 4;
        int nr = r + dr[ndir];
        int nc = c + dc[ndir];
        if(isOut(nr, nc) || cleaned[nr][nc]) continue;
        dfs(Point{nr,nc,ndir});
        return;
    }
    
    int ndir = (dir+2) % 4;
    int nr = r + dr[ndir];
    int nc = c + dc[ndir];
    if(map[nr][nc] == 1) return;
    else dfs(Point{nr,nc,dir});
    
}

// delete
void clean() {
    while(!q.empty()) {

        int r = q.front().r;
        int c = q.front().c;
        int dir = q.front().dir;
        q.pop();
        
        // 1. lookup for 4 directions
        bool flag = false;
        for(int i=0; i<4; i++) {
            int ndir = (dir + 3) % 4;
            int nr = r + dr[ndir];
            int nc = c + dc[ndir];
            if(isOut(nr, nc)) continue;
            if(cleaned[nr][nc] || map[nr][nc] != 0) continue;
            flag = true;
            cleaned[nr][nc] = true;
            q.push(Point{nr,nc,ndir});
            ans++;
            break;
        }
        if(!flag) {
            int ndir = opp(dir);
            int nr = r + dr[ndir];
            int nc = c + dc[ndir];
            if(map[nr][nc] == 1) break;
            q.push(Point{nr, nc, dir});
        }
        
    }
}
int main() {
    cin >> N >> M;
    cin >> robot.r >> robot.c >> robot.dir;
    q.push(robot);
    cleaned[robot.r][robot.c] = true;
    ans = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    //clean();
    dfs(robot);
    cout << ans << '\n';
    return 0;
}
