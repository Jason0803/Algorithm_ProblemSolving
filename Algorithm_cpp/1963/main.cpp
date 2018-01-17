#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int prime[10001];
bool check[10001];
int dist[10001];
int changed_digit(int number, int index, int digit) {
    if(index == 0 && digit == 0) return -1;
    string s = to_string(number);
    s[index] = digit + '0';
    return stoi(s);
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            for(int j=0; j<=9; j++){
                int next = changed_digit(node, i, j);
                if(next != -1 && prime[next] == false && check[next] == false) {
                    q.push(next);
                    dist[next] = dist[node] + 1;
                    check[next] = true;
                }
            }
        }
    }
}
int main(){
    for(int i=2; i<=10000; i++){
        if(prime[i]==false){
            for(int j= i*i; j<=10000; j+=i){
                prime[j] = true;
            }
        }
    }
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        memset(check, false, sizeof(check));
        memset(dist, 0, sizeof(dist));
        bfs(a);
        printf("%d\n", dist[b]);
    }
    return 0;
}
