#include <iostream>
#include <queue>
#define CB_NORMAL 1
#define CB_ABNORMAL 0
using namespace std;
int n;
char current_colour;
char map[105][105];
bool visited[101][101];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int,int>> q;
void bfs(int condition) {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(visited[nr][nc]) continue;
                
                if(condition == CB_NORMAL) {
                    if(map[nr][nc] == current_colour) {
                        visited[nr][nc] = true;
                        q.push(make_pair(nr,nc));
                    }
                } else { // 비정상
                    if(current_colour == 'B') { // 현재 파란색일경우
                        if(map[nr][nc] == 'B') {
                            visited[nr][nc] = true;
                            q.push(make_pair(nr,nc));
                        }
                    } else {
                        if(map[nr][nc] == 'R' || map[nr][nc] == 'G') {
                            visited[nr][nc] = true;
                            q.push(make_pair(nr,nc));
                        }
                    }
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    // 정상인
    int area = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j] == false) {
                visited[i][j] = true;
                q.push(make_pair(i,j));
                current_colour = map[i][j];
                bfs(CB_NORMAL);
                area++;
            }
        }
    }
    cout << area << ' ';
    // 초기화
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }
    // 비정상
    area = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j] == false) {
                visited[i][j] = true;
                q.push(make_pair(i,j));
                current_colour = map[i][j];
                bfs(CB_ABNORMAL);
                area++;
            }
        }
    }
    cout << area << '\n';
    return 0;
}
