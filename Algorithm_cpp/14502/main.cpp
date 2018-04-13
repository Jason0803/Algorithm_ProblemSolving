#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, map[8][8], cmap[8][8], pos, ans;
pair<int, int> pii[10];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int, int>> q;
void dfs(int r, int c) {
    for(int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(cmap[nr][nc] == 0) {
            cmap[nr][nc] = 2;
            dfs(nr,nc);
        }
    }
}
int getSafeArea() {
    int ret = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cmap[i][j] = map[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(cmap[i][j] == 2)
                dfs(i,j);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(cmap[i][j] == 0)
                ret++;
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                pii[pos++] = make_pair(i,j);
            }
        }
    }
    for(int r1=0; r1<N; r1++){
        for(int c1=0; c1<M; c1++) {
            if(map[r1][c1] != 0) continue;
            for(int r2=0; r2<N; r2++) {
                for(int c2=0; c2<M; c2++) {
                    if(map[r2][c2] != 0) continue;
                    for(int r3=0; r3<N; r3++) {
                        for(int c3=0; c3<M; c3++) {
                            if(map[r3][c3] != 0) continue;
                            if(r1 == r2 && c1 == c2) continue;
                            if(r2 == r3 && c2 == c3) continue;
                            if(r3 == r1 && c3 == c1) continue;
                            map[r1][c1] = 1;
                            map[r2][c2] = 1;
                            map[r3][c3] = 1;
                            ans = max(ans, getSafeArea());
                            map[r1][c1] = 0;
                            map[r2][c2] = 0;
                            map[r3][c3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
