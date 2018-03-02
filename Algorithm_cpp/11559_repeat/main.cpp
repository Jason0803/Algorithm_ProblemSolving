#include <iostream>
#include <queue>
#include <algorithm>
#define HEIGHT  12
#define WIDTH   6
using namespace std;
queue<pair<int, int>> q;
int ans;
bool flag;
char map[HEIGHT+1][WIDTH+1];
bool check[HEIGHT][WIDTH];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void input () {
    for(int i=0; i<HEIGHT; i++) {
        cin >> map[i];
    }
}
void init() {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            check[i][j] = false;
        }
    }
}
void dfs(int r, int c, char colour) {
    for(int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 0 || nr >= HEIGHT || nc < 0 || nc >= WIDTH) continue;
        if(check[nr][nc] || map[nr][nc] != colour) continue;
        check[nr][nc] = true;
        q.push(make_pair(nr,nc));
        dfs(nr,nc,colour);
    }
}
void clear_blocks() {
    bool satisfied = false;
    if(q.size() >= 4) {
        satisfied = true;
        flag = true;
    }
    while(!q.empty()) {
        if(satisfied) {
            int r = q.front().first;
            int c = q.front().second;
            map[r][c] = '.';
        }
        q.pop();
    }
}
void gravity() {
    for(int col=0; col<WIDTH; col++) {
        for(int row=HEIGHT-1; row>=0; row--) {
            if(map[row][col] == '.') continue;
            for(int k=HEIGHT-1; k>row; k--) {
                if(map[k][col] == '.') {
                    map[k][col] = map[row][col];
                    map[row][col] = '.';
                    break;
                }
            }
        }
    }
    
}
int main() {
    input();
    while(true) {
        flag = false;
        for(int i=0; i<HEIGHT; i++) {
            for(int j=0; j<WIDTH; j++) {
                if(map[i][j] != '.' && !check[i][j]) {
                    check[i][j] = true;
                    q.push(make_pair(i,j));
                    dfs(i,j,map[i][j]);
                    clear_blocks();
                }
            }
        }
        if(!flag) break;
        gravity();
        init();
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
