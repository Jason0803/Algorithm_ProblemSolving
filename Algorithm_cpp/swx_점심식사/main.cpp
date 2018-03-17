// h0ngjun_7

#include <stdio.h>

const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN*MAXN;

struct PT {
    int x, y;
    PT() {}
    PT(int x, int y) : x(x), y(y) {}
} man[MAXN], stair[2];

int N, M, S;
int map[MAXN][MAXN];
int match[MAXN];
int ans;

int ABS(int x) {
    return x >= 0 ? x : (-x);
}

int dist(int man_index, int stair_index) {
    int dx = ABS(man[man_index].x - stair[stair_index].x);
    int dy = ABS(man[man_index].y - stair[stair_index].y);
    return dx + dy;
}

void update() {
    int total_max_time = 0;
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        PT &now_stair = stair[stair_index];
        
        int arrival_time[MAXN * 2] = { 0, };
        int current_stair[MAXT] = { 0, };
        
        for (int man_index = 0; man_index < M; man_index++) {
            if (match[man_index] == stair_index) {
                arrival_time[dist(man_index, stair_index) + 1]++;
            }
        }
        
        int now_max_time = 0;
        for (int time = 1; time <= 20; time++) {
            while (arrival_time[time] > 0) {
                arrival_time[time]--;
                
                int remain_time = map[now_stair.x][now_stair.y];
                
                for (int walk_time = time; walk_time < MAXT; walk_time++) {
                    if (current_stair[walk_time] < 3) {
                        
                        current_stair[walk_time]++;
                        remain_time--;
                        
                        if (remain_time == 0) {
                            if (now_max_time < walk_time + 1) {
                                now_max_time = walk_time + 1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        
        if (total_max_time < now_max_time) {
            total_max_time = now_max_time;
        }
    }
    if (ans > total_max_time) {
        ans = total_max_time;
    }
}

void dfs(int man_index) {
    if (man_index == M) {
        update();
        return;
    }
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        match[man_index] = stair_index;
        dfs(man_index + 1);
    }
}

int main() {
    int T; for (scanf("%d", &T); T--;) {
        
        scanf("%d", &N); M = S = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 1) man[M++] = PT(i, j);
                if (map[i][j] >= 2) stair[S++] = PT(i, j);
            }
        }
        
        ans = 1e9;
        dfs(0);
        
        static int tc = 0;
        printf("#%d %d\n", ++tc, ans);
    }
}
