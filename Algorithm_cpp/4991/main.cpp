/*
 방법 1)
 1. 청소할 장소 1번 ~ 10번(최대) 까지 먼저 들렸다가 방문하는 dfs
 
 방법 2)
 
 
 */

#include <iostream>
#include <string.h>
#include <queue>
#define MAX_SIZE 22
#define EMPTY       '.'
#define DIRTY       '*'
#define FURNITURE   'x'
#define ROBOT       'o'
using namespace std;
typedef struct _Point {
    int r, c;
} Point;
Point robot, dirty[10];
queue<Point> q;
int W, H, ans;
char map[MAX_SIZE][MAX_SIZE];
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dist[MAX_SIZE][MAX_SIZE]; // dist from robot to dirt
int dists[MAX_SIZE][MAX_SIZE];             // dist from dirt to dirt
bool visited[MAX_SIZE][MAX_SIZE];
bool cleaned[10];
int abs(int input) {
    return (input < 0 ? -input : input);
}
int getDist(Point from, Point to) {
    q.push(from);
    visited[from.r][from.c] = true;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        for(int d=0; d<8; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if(visited[nr][nc] || map[nr][nc] == FURNITURE) continue;
            visited[nr][nc] = true;
            dists[nr][nc] = dist[r][c] + 1;
            q.push(Point{nr,nc});
        }
    }
    return dist[to.r][to.c];
}
void dfs(Point current, int cnt_cleaned, int total_dirt, int distance) {
    if(cnt_cleaned == total_dirt) {
        ans += distance;
        return;
    }
    for(int i=0; i<total_dirt; i++) {
        if(cleaned[i]) continue;
        cleaned[i] = true;
        int next_distance = distance + getDist(current, dirty[i]);
        dfs(dirty[i], cnt_cleaned+1, total_dirt, next_distance);
        cleaned[i] = false;
    }
}

void bfs() {
    while(!q.empty()) {
        Point current = q.front();
        q.pop();
        for(int d=0; d<8; d++) {
            int nr = current.r + dr[d];
            int nc = current.c + dc[d];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if(visited[nr][nc] || map[nr][nc] == FURNITURE) continue;
            visited[nr][nc] = true;
            dist[nr][nc] = dist[current.r][current.c] + 1;
            q.push(Point{nr,nc});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        cin >> W >> H;
        if(W == 0 && H == 0) break;
        int cnt_dirty = 0;
        ans = 0;

        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                cin >> map[i][j];
                if(map[i][j] == ROBOT) {
                    robot.r = i;
                    robot.c = j;
                    q.push(robot);
                    visited[i][j] = true;
                } else if(map[i][j] == DIRTY) {
                    dirty[cnt_dirty++] = Point{i, j};
                }
            }
        }
        
        bfs();
        memset(visited, false, sizeof(visited));
        for(int i=0; i<cnt_dirty; i++) {
            if(dist[dirty[i].r][dirty[i].c] == 0) {
                ans = -1;
                break;
            } else {
                cleaned[i] = true;
                dfs(dirty[i], 1, cnt_dirty,dist[dirty[i].r][dirty[i].c]);
                cleaned[i] = false;
            }
            
        }
        cout << ans << '\n';
        
        memset(dist, 0, sizeof(dist));
        memset(visited, false, sizeof(visited));

    }
    
    return 0;
}

