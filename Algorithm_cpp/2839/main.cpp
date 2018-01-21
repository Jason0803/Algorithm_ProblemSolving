#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int minimum;
int dist[5001];
bool check[5001];
queue<int> q;

void bfs(){
    int next;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        next = current - 3;
        if(next >= 0 && check[next] == false) {
            q.push(next);
            check[next] = true;
            dist[next] = dist[current] + 1;
        }
        next = current - 5;
        if(next >= 0 && check[next] == false){
            q.push(next);
            check[next] = true;
            dist[next] = dist[current] + 1;
        }
    }
}
int main(){
    scanf("%d", &n);
    q.push(n);
    dist[0] = -1;
    bfs();
    printf("%d\n", dist[0]);
    return 0;
}
