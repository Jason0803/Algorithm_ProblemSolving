#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#define WIDTH 12
#define HEIGHT 6
using namespace std;
int ans;
bool stable;
int chain[WIDTH*HEIGHT +1];
char map[WIDTH+1][HEIGHT+1];
int dist[WIDTH+1][HEIGHT+1];
bool check[WIDTH+1][WIDTH+1];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

void display() {
    cout << "\n=== Display ===\n";
    for(int row = 0; row < WIDTH; row++) {
        for(int column = 0; column < HEIGHT; column++) {
            cout << map[row][column];
        }
        puts("");
    }
}
void make_empty() {
    for(int row = WIDTH-1; row > 0; row--) {
        for(int column = 0; column < HEIGHT; column++) {
            if(chain[dist[row][column]] >= 3) {
                map[row][column] = '.';
                stable = false;
            }
        }
    }
}
void bfs(char colour, int connected) {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= WIDTH || nc < 0 || nc >= HEIGHT) continue;
            if(check[nr][nc]) continue;
            
            if(map[nr][nc] == colour) {
                check[nr][nc] = true;
                q.push(make_pair(nr,nc));
                dist[nr][nc] = connected;
                chain[connected]++;
            }
        }
    }
}
void gravity() {
    for(int column = 0; column < HEIGHT; column++) {
        int row = WIDTH-1;
        while(true) {
            if(map[row][column] == '.') {
                swap(map[row][column], map[row-1][column]);
            }
            row--;
        }
    }
    display();
    ans++;
}

int main() {
    for(int i=0; i<WIDTH; i++) {
        cin >> map[i];
    }
    //display();
    while(!stable) {
        stable = true;
        memset(check, false, sizeof(check));
        memset(dist, 0, sizeof(dist));
        memset(chain, 0, sizeof(chain));
        
        int connected = 0;
        for(int row = WIDTH-1; row > 0; row--) {
            for(int column = 0; column < HEIGHT; column++) {
                if(map[row][column] != '.' && check[row][column] == false) {
                    q.push(make_pair(row, column));
                    bfs(map[row][column], connected++);
                }
            }
        }
        make_empty();
        gravity();
    }
    
    cout << ans << '\n';
    
    return 0;
}
