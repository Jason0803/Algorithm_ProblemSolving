#include <iostream>
#include <queue>
#define MAX_SIZE 10001
using namespace std;
typedef struct _Point {
    int r, c;
}Point;
queue<Point> q_to_visit;
queue<Point> q;
int T, W, H, N, ans;
bool isOut(int r, int c) {
    return (r < 1 || r > H || c < 1 || c > W);
}
void bfs(Point dept) {
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        q.pop();
        if(r == ) {
            
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cin >> W >> H >> N;
        
        for(int i=0; i<N; i++) {
            Point temp;
            cin >> temp.c >> temp.r;
            q_to_visit.push(temp);
        }
        
        while(!q_to_visit.empty()) {
            Point from = q_to_visit.front();
            q_to_visit.pop();
            q.push(from);
        }
        
    }
    
    return 0;
}
