#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 10000
using namespace std;
bool check[MAX+1];
string moves[MAX+1];
string s;
int t, a, b;
int dslr_l(int number) {
    s = to_string(number);
    char first = s.front();
    for(int i=0; i<(int)s.length()-1; i++){
        s[i] = s[i+1];
    }
    s.back() = first;
    return stoi(s);
}
int dslr_r(int number) {
    s = to_string(number);
    char last = s.back();
    for(int i=(int)s.length()-1; i>0; i--){
        s[i] = s[i-1];
    }
    s.front() = last;
    return stoi(s);
}
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
                moves[next].append(moves[node] + "D");
            }
        }
        
        next = node - 1;
        if(next >= 0) {
            if(next == 0) next = 9999;
            if(check[next] == false) {
                q.push(next);
                check[next] = true;
                moves[next].append(moves[node] + "S");
            }
        }
        
        next = dslr_l(node);
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            moves[next].append(moves[node] + "L");
        }
        
        next = dslr_r(node);
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            moves[next].append(moves[node] + "R");
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        memset(check, false, sizeof(check));
        memset(moves, NULL, sizeof(moves));
        check[a] = true;
        bfs(a);
        printf("%s\n", moves[b].c_str());
    }
    return 0;
}
