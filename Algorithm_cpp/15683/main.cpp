#include <iostream>
#include <vector>
using namespace std;
typedef struct _Point{
    int r, c;
    int dir;    // 0 1 2 3
    int type;   // 1 2 3 4 5
}Point;
int N, M, map[8][8], cnt_zero, ans;

vector<Point> cctvs;    // 각 cctv 의 위치와 방향 정보 담음
/*
 1. As if I get maximum ranges from every single cams, I think it'd work;
 2. 모든 cctv 상태를 param 넘김
 */

// 1. 번 방법
void solve_1() {
    // 1-1. 맵 복사
    int tmap[8][8];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            tmap[i][j] = map[i][j];
        }
    }
    for(int i=0; i<cctvs.size(); i++) {
        if(cctvs[i].type != 5) {
            for(int d=0; d<4; d++) {
                // 각 방향 별, # 치는 갯수 최댓값 구함
                
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] < 6){
                cctvs.push_back({i,j,0,map[i][j]});
            }
        }
    }
    
    return 0;
}
