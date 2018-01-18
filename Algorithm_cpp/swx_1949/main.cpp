#include <cstdio>
#define MAX 10

typedef struct _point {
    int r,c;
    int height;
    bool fixed;
    int len;
}point;

int n, k;
int highest;
int ans;
int map[MAX][MAX];
bool check[MAX][MAX];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void dfs(point current) {
    ans = ans > current.len ? ans : current.len;
    
    for(int k=0; k<4; k++){
        point next = current;
        next.r += dr[k];
        next.c += dc[k];
        
        if(next.r >= n || next.r < 0 || next.c >= n || next.c < 0) continue;
        if(check[next.r][next.c]) continue;
        
        next.height = map[next.r][next.c];
        
        if(next.height < current.height) {
            check[next.r][next.c] = true;
            next.len++;
            dfs(next);
            check[next.r][next.c] = false;
        } else {
            if(current.fixed == false && (next.height - k < current.height)){
                check[next.r][next.c] = true;
                next.len++;
                next.fixed = true;
                next.height = current.height-1;
                dfs(next);
                check[next.r][next.c] = false;
            }
        }
    }
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int test_case = 1; test_case <= t; test_case++){
        scanf("%d %d", &n, &k);
        highest = 0;
        ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &map[i][j]);
                if(highest < map[i][j])
                    highest = map[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == highest){
                    check[i][j] = true;
                    point currnet = {i, j, map[i][j], false, 1};
                    dfs(currnet);
                    check[i][j] = false;
                }
            }
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}

