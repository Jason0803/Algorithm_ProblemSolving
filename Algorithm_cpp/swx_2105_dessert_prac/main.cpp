#include <iostream>
#include <algorithm>
#define MAX_SIZE    21
#define MAX_DESSERT 101
using namespace std;
int T, N, ans;
int map[MAX_SIZE][MAX_SIZE];
bool dessert[MAX_DESSERT];
int dr[] = {1, 1, -1, -1};
int dc[] = {1, -1, -1, 1};
pair<int, int> departure;
void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
}
void dfs(int r, int c, int cnt, int turned) {
    for(int d=0; d<2; d++) {
        int nr = r + dr[turned + d];
        int nc = c + dc[turned + d];
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(dessert[map[nr][nc]]) {
            if(nr == departure.first && nc == departure.second) {
                ans = ans > cnt ? ans : cnt;
            }
            continue;
        }

        dessert[map[nr][nc]] = true;
        dfs(nr,nc,cnt+1,turned+d);
        dessert[map[nr][nc]] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        input();
        ans = -1;
        for(int i=0; i<N-2; i++) {
            for(int j=1; j<N-1; j++) {
                departure = {i,j};
                
                dessert[map[i][j]] = true;
                dfs(i,j,1,0);
                dessert[map[i][j]] = false;
            }
        }
        cout << "#" << test_case << " " << ans << '\n';
    }
    return 0;
}
