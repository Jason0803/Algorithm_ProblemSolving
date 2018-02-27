#include <iostream>
#include <string.h>
#include <queue>
#define WIDTH 6
#define HEIGHT 12
using namespace std;
int ans;
char map[HEIGHT+1][WIDTH+1];
bool check[HEIGHT][WIDTH], flag;
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
queue<pair<int, int>> q;
void display() {
    for(int i=0; i<HEIGHT; i++) {
        cout << map[i] << '\n';
    }
}
void dfs(int r, int c, char colour) {
    for(int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 0 || nr >= HEIGHT || nc < 0 || nc >= WIDTH) continue;
        if(check[nr][nc]) continue;
        if(map[nr][nc] == colour) {
            check[nr][nc] = true;
            q.push(make_pair(nr,nc));
            dfs(nr,nc,colour);
        }
    }
}
void make_empty() {
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
    for(int i=0; i<6; i++) {
        for(int j=HEIGHT-1; j>=0; j--) {
            if(map[j][i] == '.') continue;
            for(int k=HEIGHT-1; k>j; k--) {
                if(map[k][i] != '.') continue;
                map[k][i] = map[j][i];
                map[j][i] = '.';
                break;
            }
        }
    }
}
int main() {
    for(int i=0; i<HEIGHT; i++) {
        cin >> map[i];
    }
    while(1) {
        flag = false;
        memset(check, false, sizeof(check));

        for(int i=0; i<HEIGHT; i++) {
            for(int j=0; j<WIDTH; j++) {
                if(map[i][j] != '.' && !check[i][j]) {
                    check[i][j] = true;
                    q.push(make_pair(i,j));
                    dfs(i, j, map[i][j]);
                    make_empty();
                }
            }
        }
        
        if(flag) {
            ans++;
        } else break;
        
        gravity();
    }
    cout << ans << '\n';
    return 0;
}
