#include <iostream>
#include <queue>
using namespace std;
typedef struct _Point {
    int r, c, l;
    int cnt;    // time
} Point;
Point st, fn;
queue<Point> q;
int L, R, C, ans;
char building[34][34][31];
bool visited[31][31][31];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int dl[] = {-1, 1};
void input() {
    for(int l=L; l>0; l--) {
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                cin >> building[r][c][l];
                if(building[r][c][l] == 'S') {
                    st.r = r;
                    st.c = c;
                    st.l = l;
                    st.cnt = 0;
                    visited[r][c][l] = true;
                    q.push(st);
                } else if(building[r][c][l] == 'E') {
                    fn.r = r;
                    fn.c = c;
                    fn.l = l;
                }
            }
        }
    }
    ans = -1;
    for(int l=1; l<=L; l++) {
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                visited[r][c][l] = false;
            }
        }
    }
}
void escape(){
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int l = q.front().l;
        int cnt = q.front().cnt;
        q.pop();
        
        // Escape
        if(r == fn.r && c == fn.c && l == fn.l) {
            ans = cnt;
            break;
        }
     
        // 1. 4-ways
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(visited[nr][nc][l] || building[nr][nc][l] == '#') continue;
            visited[nr][nc][l] = true;
            q.push(Point{nr,nc,l,cnt+1});
        }
        
        // 2. floor
        
        for(int d=0; d<2; d++) {
            int nl = l + dl[d];
            if(nl < 1 || nl > L) continue;
            if(visited[r][c][nl] || building[r][c][nl] == '#') continue;
            visited[r][c][nl] = true;
            q.push(Point{r,c,nl,cnt+1});
        }
    }
    while(!q.empty()) q.pop();
}
void output() {
    if(ans != -1) {
        cout << "Escaped in " << ans << " minute(s).\n";
    } else {
        cout << "Trapped!\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        input();
        escape();
        output();
    }
    
    return 0;
}
