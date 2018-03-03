#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 11
#define INF 987654321
#define EMPTY       '.'
#define WALL        '#'
#define HOLE        'O'
#define RED_ORB     'R'
#define BLUE_ORB    'B'
using namespace std;
typedef struct _Point {
    int r, c;
    int cnt;
}Point;
Point hole;
queue<Point> red_q;
queue<Point> blue_q;
int N, M, ans;
char map[MAX_SIZE][MAX_SIZE];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs() {
    while(!red_q.empty() && !blue_q.empty()) {
        int red_r = red_q.front().r;
        int red_c = red_q.front().c;
        int cnt = red_q.front().cnt;
        red_q.pop();
        int blue_r = blue_q.front().r;
        int blue_c = blue_q.front().c;
        blue_q.pop();
        
        if(red_r == hole.r && red_c == hole.c) {
            if(cnt < ans) ans = cnt;
            continue;
        }
        
        
        
        // MOVE - RED
        for(int dir = 0; dir < 4; dir++) {
            for(int mult = 1; mult < MAX_SIZE; mult++) {
                int red_nr = red_r + dr[dir] * mult;
                int red_nc = red_c + dc[dir] * mult;
                
                if(dir < 3){    // UP & DOWN
                    
                    if(red_nr == 1 || red_nr == N-1) {
                        int ncnt = cnt + 1;
                        red_q.push(Point{red_nr, red_nc, ncnt});
                        break;
                    }
                } else {        // Left & Right
                    if(red_nc == 1 || red_nc == M-1) {
                        int ncnt = cnt + 1;
                        red_q.push(Point{red_nr, red_nc, ncnt});
                        break;
                    }
                }
                
            }
        }
        
        
        // Up & Down
        for(int dir=0; dir<2; dir++) {
            int red_nr, blue_nr;
            for(int mult=1; mult<=N; mult++) {
                if(map[red_r + dr[dir] * mult][red_c] == EMPTY) {
                    if(red_r + dr[dir] * mult == 1 || red_r + dr[dir] * mult == N-1) {
                        red_nr = red_r + dr[dir] * mult;
                    }
                }
                blue_nr = blue_r + dr[dir] * mult;
                
            }
        }

        // Left & Right
        
        
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == RED_ORB) {
                red_q.push(Point{i,j});
            } else if(map[i][j] == BLUE_ORB) {
                blue_q.push(Point{i,j});
            } else if(map[i][j] == HOLE) {
                hole.r = i;
                hole.c = i;
            }
        }
    }
    
    ans = -1;
    bfs();
    return 0;
}
