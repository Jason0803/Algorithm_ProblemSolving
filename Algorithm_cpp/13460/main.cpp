#include <iostream>
#include <algorithm>
#define EMPTY   '.'
#define WALL    '#'
#define BLUE    'B'
#define RED     'R'
#define HOLE    'O'
using namespace std;
typedef struct _Point {
    int r, c;
}Point;
Point p_blue, p_red, p_hole;
int N, M, ans;
char map[11][11];
bool visited[11][11][11][11];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool isOut(int r, int c) {
    return (r < 1 || r >= N-1 || c < 1 || c >= M-1);
}
void simulate(Point *blue, Point *red, int cnt) {
    if(ans != -1 && cnt > ans) return;
    if(blue->r == p_hole.r && blue->c == p_hole.c) {
        ans = -1;
        return;
    }
    if(red->r == p_hole.r && red->c == p_hole.c) {
        if(ans == -1) ans = cnt;
        else ans = min(ans,cnt);
        return;
    }
    for(int dir=0; dir<4; dir++) {
        int nbr = blue->r;
        int nbc = blue->c;
        int nrr = red->r;
        int nrc = red->c;
        
        for(int k=1; k < max(N,M)-1; k++) {
            nbr += dr[dir];
            nbc += dc[dir];
            nrr += dr[dir];
            nrc += dc[dir];
            
            if(isOut(nbr, nbc) || map[nbr][nbc] == WALL) {
                nbr -= dr[dir];
                nbc -= dc[dir];
            }
            if(isOut(nrr, nrc) || map[nrr][nrc] == WALL) {
                nrr -= dr[dir];
                nrc -= dc[dir];
            }
            if(map[nbr][nbc] == HOLE || map[nrr][nrc] == HOLE) {
                Point nbp = {nbr, nbc};
                Point nrp = {nrr, nrc};
                simulate(&nbp, &nrp, cnt+1);
            }
        }
        if(map[nbr][nbc] == HOLE || map[nrr][nrc] == HOLE) continue;
        
        if(nbr == nrr && nbc == nrc) {
            if(dir == 0) {
                if(blue->r > red->r) nbr += 1;
                else nrr += 1;
            } else if(dir == 1) {
                if(blue->r > red->r) nrr -= 1;
                else nbr -= 1;
            } else if(dir == 2) {
                if(blue->c > red->c) nbc += 1;
                else nrc+= 1;
            } else {
                if(blue->c > red->c) nrc -= 1;
                else nbc -= 1;
            }
        }
        if(visited[nbr][nbc][nrr][nrc]) continue;
        visited[nbr][nbc][nrr][nrc] = true;
        Point nbp = {nbr, nbc};
        Point nrp = {nrr, nrc};
        simulate(&nbp, &nrp, cnt+1);
        visited[nbr][nbc][nrr][nrc] = false;
        
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == RED) {
                p_red.r = i;
                p_red.c = j;
            } else if(map[i][j] == BLUE) {
                p_blue.r = i;
                p_blue.c = j;
            } else if(map[i][j] == HOLE) {
                p_hole.r = i;
                p_hole.c = j;
            }
        }
    }
    ans = 987654321;
    visited[p_blue.r][p_blue.c][p_red.r][p_red.c] = true;
    simulate(&p_blue, &p_red, 0);
    
    if(ans > 10) ans = -1;
    cout << ans << '\n';
    return 0;
}
