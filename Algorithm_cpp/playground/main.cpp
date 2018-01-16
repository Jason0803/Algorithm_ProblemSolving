#include<iostream>
#include<stack>
#include<queue>
#define MAX_VERTEX 1005
using namespace std;

// N 정점 갯수, M 간선 갯수, V 방문할 정점
int N, M, V;
// 그래프
bool graph[MAX_VERTEX][MAX_VERTEX];

stack <int> DFS_STACK;
queue <int> BFS_QUE;

int main() {
    scanf("%d %d %d", &N, &M, &V);
    
    // 간선 정보 입력받아서 N * N 배열에 그래프 정보 저장
    for (int i = 0, vertex1, vertex2; i < M; i++) {
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = true; graph[vertex2][vertex1] = true;
    }
    
    // dfs
    int DFS_VISIT[MAX_VERTEX] = { false }; // 방문체크 변수
    DFS_STACK.push(V); DFS_VISIT[V] = true; printf("%d ", V); // 출발 정점 처리
    
    while (!DFS_STACK.empty()) {
        for (int i = 1; i <= N; i++) {
            // 현재 stack의 top에 저장된 정점에서 갈 수 있는 정점중 숫자가 가장 작은 정점을 stack에 push후 방문처리 후 break
            if (graph[DFS_STACK.top()][i] == true && DFS_VISIT[i] == false) {
                printf("%d ", i);
                DFS_VISIT[i] = true;
                DFS_STACK.push(i);
                break;
            }
            // 만약 현재 stack의 top에 있는 정점에서 갈 수 있는 다른 정점이 없다면 pop한다.
            if (i == N) {
                DFS_STACK.pop();
            }
        }
    }
    printf("\n");
    
    // bfs
    int BFS_VISIT[MAX_VERTEX] = { false };  // 방문체크 변수
    BFS_QUE.push(V); BFS_VISIT[V] = true; // 출발 정점 처리
    
    while (!BFS_QUE.empty()) {
        for (int i = 1; i <= N; i++) {
            // 현재 Queue front에 저장된 출발지점에서 갈 수 있는 다른 정점들을 모두 Que에 저장
            // 이떄 방문 체크 된 것은 Que에 저장하지않음
            if (graph[BFS_QUE.front()][i] == true && BFS_VISIT[i] == false) {
                BFS_VISIT[i] = true;
                BFS_QUE.push(i);
            }
        }
        printf("%d ", BFS_QUE.front());
        BFS_QUE.pop();
    }
    printf("\n");
}
