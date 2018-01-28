#include <iostream>
using namespace std;
int r, c;
int result = 1;
char map[21][21];
bool visit[26];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
void dfs(int x, int y, int count) {
    if(count > result) result = count;
    for(int k=0; k<4; k++) {
        int nr = x + dr[k];
        int nc = y + dc[k];
        if(0 <= nr && nr < r && 0 <= nc && nc < c) {
            int index = map[nr][nc]-'A';
            if(visit[index] == false){
                visit[index] = true;
                dfs(nr,nc,count+1);
                visit[index] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
        }
    }
    visit[map[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << result << '\n';
    return 0;
}
