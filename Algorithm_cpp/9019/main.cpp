#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 10000
using namespace std;
bool check[MAX+1];
//vector<string> moves(MAX+1);
string moves[MAX+1];
string s;
int t, a, b;
void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        if(node == b) break;
        q.pop();
        int next;
        
        next = node*2;
        if(next >= 10000) next %= 10000;
        if(next < MAX*2) {
            if(check[next] == false){
                q.push(next);
                check[next] = true;
                moves[next] += moves[node] + "D";
            }
        }
        
        next = node - 1;
        if(next >= 0) {
            if(next == 0) next = 9999;
            if(check[next] == false) {
                q.push(next);
                check[next] = true;
                moves[next] += moves[node] + "S";
            }
        }
        
        next = (node%1000)*10 + node/1000;
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            moves[next] += moves[node] + "L";
        }
        
        next = (node/10) + (node%10)*1000;
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            moves[next] += moves[node] + "R";
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        memset(check, false, sizeof(check));
        
        //moves.clear();
        memset(moves, NULL, sizeof(moves));
        check[a] = true;
        bfs(a);
        printf("%s\n", moves[b].c_str());
    }
    return 0;
}

