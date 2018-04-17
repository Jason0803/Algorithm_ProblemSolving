#include <cstdio>
#include <vector>
using namespace std;
int N, M, ans, map[51][51], mat[14][101];
bool check[14];
typedef struct _Point {
    int r, c;
}Point;
vector<Point> homes;
vector<Point> chickens;
int Abs(int a, int b) {
    return a>b?a-b:b-a;
}
int dist(Point *a, Point *b) {
    return Abs(a->r, b->r)+Abs(a->c, b->c);
}
void calculate() {
    for(int i=0; i<chickens.size(); i++) {
        for(int j=0; j<homes.size(); j++) {
            mat[i][j] = dist(&chickens[i], &homes[j]);
        }
    }
}
void dfs(int cnt_home, int cnt_chk, int sum) {
    if(sum>=ans) return;
    if(cnt_home == homes.size()-1) {
        if(sum<ans) ans=sum;
        return;
    }

    for(int i=0; i<chickens.size(); i++) {
        // 1. check for visited chks
        if(check[i]) {
            dfs(cnt_home+1, cnt_chk, sum+mat[i][cnt_home+1]);
        } else {
            // 2. check for !visited chks
            if(cnt_chk < M) {
                check[i] = true;
                dfs(cnt_home+1, cnt_chk+1, sum+mat[i][cnt_home+1]);
                check[i] = false;
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) {
                homes.push_back(Point{i,j});
            } else if(map[i][j] == 2) {
                chickens.push_back(Point{i,j});
            }
        }
    }
    calculate();
    ans = 987654321;
    for(int i=0; i<14; i++) check[i] = false;
    for(int i=0; i<chickens.size(); i++) {
        check[i] = true;
        dfs(0, 1, mat[i][0]);
        check[i] = false;
    }

    
    //homes.clear();
    //chickens.clear();
    printf("%d\n", ans);
    return 0;
}
