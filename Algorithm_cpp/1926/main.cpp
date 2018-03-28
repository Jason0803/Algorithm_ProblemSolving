#include <iostream>
#include <vector>
#include <algorithm>
#define INF 98765432
#define MAX_SIZE 501
#define EMPTY   0
#define PAINTED 1
#define VISITED 2
using namespace std;
int N, M, cnt, paints, largest;
int map[MAX_SIZE][MAX_SIZE];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
void dfs(int r, int c) {
    for(int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(map[nr][nc] != PAINTED) continue;
        map[nr][nc] = VISITED;
        cnt++;
        dfs(nr,nc);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    largest = -1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == PAINTED) {
                cnt = 1;
                paints++;
                map[i][j] = VISITED;
                dfs(i,j);
                if(largest < cnt) largest = cnt;
            }
        }
    }

    cout << paints << '\n';
    if(largest != -1) cout << largest << '\n';
    else cout << "0\n";
    return 0;
}
