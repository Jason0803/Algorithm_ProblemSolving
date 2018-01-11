#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int N, input;
vector<int> graph[101];
bool check[101];
int visited[101][101];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

void bfs(int start){
    queue<int> q;
    for(int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];
        if(check[next] == false) {
            check[next] = true;
            visited[start][next] = 1;
            visited[next][start] = 1;
            q.push(next);
        }
    }
}
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            scanf("%d", &input);
            if(input == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for(int i=0; i<N; i++)
        bfs(i);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            printf("%d ", visited[i][j]);
        }
        puts("");
    }
    return 0;
}
