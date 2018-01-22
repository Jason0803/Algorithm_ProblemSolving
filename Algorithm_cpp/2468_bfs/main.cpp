#include <cstdio>
#include <queue>
#define MAX 100
// bfs 로 풀어보자
using namespace std;
int n, rain;
int map[MAX][MAX];
bool check[MAX][MAX];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
queue<pair<int,int>> q;
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(map[nr][nc] > rain && check[nr][nc] == false) {
                    check[nr][nc] = true;
                    q.push(make_pair(nr,nc));
                }
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    int highest = 0;
    int lowest = 101;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &map[i][j]);
            highest = max(map[i][j], highest);
            lowest = min(map[i][j], lowest);
        }
    }
    int count = 0;
    for(rain=lowest; rain<highest; rain++){
        int ans = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                check[i][j] = false;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] > rain && check[i][j] == false) {
                    q.push(make_pair(i,j));
                    check[i][j] = true;
                    bfs();
                    ans++;
                }
            }
        }
        count = max(ans, count);
    }
    printf("%d\n", count);
    return 0;
}

