#include <iostream>
#include <queue>
#define MAX_SIZE 1001
#define INF 987654321
#define PATH 0
#define WALL 1
using namespace std;
typedef struct _Point {
    int r,c, passed;
}Point;
queue<Point> q;
int N, M, ans;
char map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE][2];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> map[i];
    
    check[0][0][0] = true;
    q.push(Point{0,0,0});
    ans = -1;
}
void bfs() {
    int dist = 0;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int passed = q.front().passed;
        q.pop();

        if(r == N-1 && c == M-1) {
            ans = dist;
            cout << ans << '\n';
            break;
        }
        
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(check[nr][nc][passed] || map[nr][nc] != '0') continue;
            check[nr][nc][passed] = true;
            q.push(Point{nr,nc,passed});
        }
        
        if(passed == 0) {
            for(int d=0; d<4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if(check[nr][nc][passed]) continue;
                check[nr][nc][1] = true;
                q.push(Point{nr,nc,1});
            }
        }
        dist++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    input();
    bfs();
    
    if(ans == -1) cout << "-1\n";
    return 0;
}
