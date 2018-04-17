#include <cstdio>
struct Point{int r; int c;};
int N, M, ans, map[50][50], cnt_pp, cnt_ch;
bool check[13];
Point people[100], chickens[13];
int Abs(int a){
    return a>0?a:-a;
}
int dist(Point* h, Point* p) {
    return (Abs(h->r-p->r) + Abs(h->c-p->c));
}
int getMinimum(){
    int ret = 0;
    for(int p=0; p<cnt_pp; p++) {
        int min = 987654321;
        for(int h=0; h<cnt_ch; h++) {
            if(!check[h]) continue;
            int d = dist(&chickens[h], &people[p]);
            if(min>d) min = d;
        }
        ret += min;
    }
    return ret;
}
void dfs(int idx, int d){
    if(d==M) {
        int min = getMinimum();
        if(ans>min) ans = min;
        return;
    }
    for(int i=idx+1; i<cnt_ch; i++) {
        if(check[i]) continue;
        check[i] = true;
        dfs(i, d+1);
        check[i] = false;
    }
}
int main() {
    scanf("%d %d", &N, &M);
    ans = 987654321;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j]==1) people[cnt_pp++] = {i,j};
            else if(map[i][j]==2) chickens[cnt_ch++] = {i,j};
        }
    }
    for(int i=0; i<cnt_ch; i++) {
        check[i] = true;
        dfs(i,1);
        check[i] = false;
    }
    printf("%d\n", ans);
    return 0;
}
