#include <iostream>
using namespace std;
int map[11][11];
bool visited[11][11];
int T, N, M, C, cost, ans;
void dfs(int r, int c, int i, int sum, int co) {
    if(sum > C) return;
    if(cost < co) cost = co;
    if(i == M) return;
    dfs(r,c+1, i+1, sum + map[r][c], co + map[r][c] * map[r][c]);
    dfs(r,c+1, i+1, sum, co);
}
int solve(int r, int c){
    for(int i=c; i<c+M; i++)
        visited[r][i] = true;
    cost = 0;
    dfs(r,c,0,0,0);
    int value_1 = cost;
    int value_2 = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=N-M; j++) {
            if(visited[i][j]) continue;
            cost = 0;
            dfs(i,j,0,0,0);
            value_2 = cost > value_2 ? cost : value_2;
        }
    }
    return value_1 + value_2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cin >> N >> M >> C;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> map[i][j];
            }
        }
        ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<=N-M; j++) {
                int temp = solve(i,j);
                ans = temp > ans ? temp : ans;
            }
        }
        // 각 줄에서 n 개씩 뽑아 가장 최대가 되는것들 구함
        cout << "#" << test_case << " " << ans << '\n';
    }
    return 0;
}
