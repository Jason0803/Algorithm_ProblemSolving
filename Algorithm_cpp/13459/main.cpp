#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 12
using namespace std;
typedef struct _Node {
    int red_r, red_c;
    int blue_r, blue_c;
}Node;
int N, M, cnt=0;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<Node> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> N >> M;
    int a, b, c, d;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'R') {
                a = i;
                b = j;
            }
            if(map[i][j] == 'B') {
                c = i;
                d = j;
            }
        }
    }
    visited[a][b][c][d] = true;
    q.push(Node{a,b,c,d});
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--) {
            int rr = q.front().red_r;
            int rc = q.front().red_c;
            int br = q.front().blue_r;
            int bc = q.front().blue_c;
            q.pop();
            if(map[rr][rc] == 'O') {
                cout << "1\n";
                return 0;
            }
            for(int i=0; i<4; i++) {
                int nrr = rr;
                int nrc = rc;
                int nbr = br;
                int nbc = bc;
                bool flag = false; // 파란 구슬이 들어가는 지
                while(map[nrr+dr[i]][nrc+dc[i]] != '#' && map[nrr][nrc] != 'O') {
                    nrr += dr[i];
                    nrc += dc[i];
                }
                while(map[nbr+dr[i]][nbc+dc[i]] != '#' && map[nbr][nbc] != 'O') {
                    nbr += dr[i];
                    nbc += dc[i];
                    if(map[nbr][nbc] == 'O') flag = true;
                }
                if(nrr == nbr && nrc == nbc) {
                    if(i==0) {
                        if(bc>rc) nrc -= 1;
                        else nbc -= 1;
                    }else if(i==1) {
                        if(bc>rc) nbc += 1;
                        else nrc += 1;
                    } else if(i==2) {
                        if(br>rr) nrr -= 1;
                        else nbr -= 1;
                    } else {
                        if(br>rr) nbr += 1;
                        else nrr += 1;
                    }
                }
                if(flag) continue;
                if(visited[nrr][nrc][nbr][nbc]) continue;
                visited[nrr][nrc][nbr][nbc] = true;
                q.push(Node{nrr,nrc,nbr,nbc});
            }
            cnt++;
            if(cnt > 10) break;
        }
    }
    cout << "0\n";
    return 0;
}
