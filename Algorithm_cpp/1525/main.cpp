#include <cstdio>
#include <queue>
#include <set>
#define MAX 3
using namespace std;

int dc[] = {-1,1,0,0};
int dr[] = {0,0,-1,1};
int graph[MAX][MAX];
int temp[MAX][MAX];
queue<pair<int,int>> q;
set<int> visit;

int bfs(){
    while(!q.empty()){
        int sum = q.front().first;
        int w = q.front().second;
        q.pop();
        
        if(sum == 123456780) return w;
        
        int r,c;
        for(int i=MAX-1; i>=0; i--) {
            for(int j=MAX-1; j>=0; j--) {
                temp[i][j] = sum % 10;
                if(temp[i][j] == 0) {
                    r = i;
                    c = j;
                }
                sum /= 10;
            }
        }
        for(int k=0; k<4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < MAX && 0 <= nc && nc < MAX) {
                int next = temp[nr][nc];                        // 0 과 인접한 것
                int temp_sum = 0;                                   // 3*3 행렬 상태 저장용 변수
                for(int i=0; i<MAX; i++){
                    for(int j=0; j<MAX; j++){
                        temp_sum *= 10;
                        if(i == r && j == c) temp_sum += next;      // 0이었던 위치 찾으면 새거 집어넣고
                        else if(i == nr && j == nc) temp_sum += 0;  // 새 위치를 온거면 0 집어넣고
                        else temp_sum += temp[i][j];                // 아니면 원래 있던 값 놓고
                    }
                }
                if(visit.find(temp_sum) == visit.end()) {
                    visit.insert(temp_sum);
                    q.push(make_pair(temp_sum,w+1));
                }
            }
        }
    }
    return -1;
}
int main() {
    int sum = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            scanf("%d", &graph[i][j]);
            sum *= 10;
            sum += graph[i][j];
        }
    }
    q.push(make_pair(sum ,0));
    visit.insert(sum);
    printf("%d\n", bfs());
    return 0;
}
