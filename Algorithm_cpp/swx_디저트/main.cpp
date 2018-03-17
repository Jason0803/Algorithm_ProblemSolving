#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, ans;
int map[21][21];
bool dessert[101];
int mi[] = {1, 1, -1, -1};
int mj[] = {1, -1, -1, 1};
pair<int, int> departing;

void dfs(int ci, int cj, int cnt, int turned) {
    for (int i = 0; i < 2; i++) {
        int ni = ci + mi[turned + i];
        int nj = cj + mj[turned + i];
        
        //over
        if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
        
        //answer
        if (dessert[map[ni][nj]]) {
            if (departing.first == ni && departing.second == nj)
                ans = max(ans, cnt);
            continue;
        }
        
        //next
        dessert[map[ni][nj]] = true;
        dfs(ni, nj, cnt + 1, turned + i);
        dessert[map[ni][nj]] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> map[i][j];
        ans = -1;
        for (int i = 1; i < N-1; i++)
            for (int j = 2; j < N; j++) {
                departing = {i, j};
                dessert[map[i][j]] = true;
                dfs(i, j, 1, 0);
                dessert[map[i][j]] = false;
            }
        cout << "#" << test_case << " " << ans << endl;
    }
    return 0;
}
