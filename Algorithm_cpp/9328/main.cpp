#include <iostream>
#include <queue>
#define EMPTY       '.'
#define WALL        '*'
#define DOC         '$'
#define MAX_SIZE    101
using namespace std;
int t, n, m, ans;
queue<pair<int, int>> q;
char keys[27];      // a ~ z + '\n'
char map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

/*
 
 '.'는 빈 공간을 나타낸다.
 '*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
 '$'는 상근이가 훔쳐야하는 문서이다.
 알파벳 대문자는 문을 나타낸다.
 알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.
 
 */
void input() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }
    
}
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int d=0; d<4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(check[nr][nc] || map[nr][nc] == WALL) continue;
            
            // cases..
            // 1. DOOR
            // 2. KEY
            // 3. EMPTY
        }
    }
}
int main() {
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++) {
        ans = 0;
        input();
        cin >> keys;
        if(keys[0] == '0') cout << ans << '\n';
        else {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(map[i][j] == DOC) {
                        q.push(make_pair(i,j));
                        check[i][j] = true;
                        bfs();
                    }
                }
            }
        }
    }
    /*
    char temp = 65;
    char temp_b = 97;
    cout << temp << '\n';
    cout << temp_b << '\n';
     */
    return 0;
}
