#include <cstdio>
#define DEPTH 14
#define WIDTH 21
int T, D, W, K, ans;
int map[DEPTH][WIDTH];
int chemical[DEPTH];
void input() {
    for(int i=0; i<D; i++){
        for(int j=0; j<W; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}
void solve(int current_depth, int cnt_chemical, int prev_types[WIDTH], int prev_max_cnt[WIDTH] ){
    // return condition 1
    if(cnt_chemical >= ans) return;
    
    // return condition 2
    if(current_depth == D) {
        bool satisfied = true;
        for(int i=0; i<W; i++) {
            if(prev_max_cnt[i] < K) {
                satisfied = fasle;
                break;
            }
        }
        if(satisfied && cnt_chemical < ans)
            ans = cnt_chemical;
        return;
    }
    
    int types[WIDTH], max_cnt[WIDTH];
    int prev, cur;
    for(int i=2; i>=0; i--) {
        chemical[current_depth] = i;
        for(int j=0; j<W; j++) {
            if(chemical[current_depth] == 2) {
                cur = map[current_depth][j];
                prev = map[current_depth-1][j];
            } else {
                cur = chemical[current_depth];
                prev = chemical[current_depth-1];
            }
            if(cur == prev) {
                types[j] = prev_types[j]+1;
            } else types[j] = 1;
            
            if(types[j] > prev_types[j]) max_cnt[j] = types[j];
            else max_cnt[j] = prev_types[j];
        }
        solve(current_depth+1, cnt_chemical+(i==2?0:1), types, max_cnt);
    }
}
int main() {
    scnaf("%d", &T);
    for(int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d", &D, &W, &K);
        input();
        ans = K;
        
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
