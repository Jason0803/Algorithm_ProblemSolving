//  << SOCAR 사전과제>>
//  main.cpp
//  dfs 응용하여 각 칸 기준,
//  dr[], dc[] 이용하여 인접한 8개의 배열 탐색하여 MINE일 경우 count_mines[][] ++;
//  r = 0, c = 0 부터 r = 9, c = 9 까지 100칸 수행
//
//  Created by Soo Young Choi on 2/9/18.
//  Copyright © 2018 Jason Choi. All rights reserved.
//

#include <iostream>
#define MINE '*'
#define MAP_SIZE 105
using namespace std;
int R, C;
char map[MAP_SIZE+1][MAP_SIZE+1];
int count_mines[MAP_SIZE+1][MAP_SIZE+1];
int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

void init() {
    for(int i=0; i<MAP_SIZE; i++) {
        for(int j=0; j<MAP_SIZE; j++) {
            count_mines[i][j] = 0;
        }
    }
}
bool isSafe(int r, int c) {
    return (0 <= r && r < MAP_SIZE && 0 <= c && c < MAP_SIZE);
}
void dfs(int r, int c) {
    for(int k=0; k<8; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(!isSafe(nr, nc)) continue;
        if(map[nr][nc] == MINE) count_mines[r][c]++;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    while(true) {
        cin >> R >> C;
        if(R == 0 && C == 0) break;
        init();
        for(int i=0; i<R; i++)
            cin >> map[i];
        
        for(int r=0; r<R; r++)
            for(int c=0; c<C; c++)
                dfs(r,c);
        
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(map[i][j] == '.') cout << count_mines[i][j];
                else cout << MINE;
            }
            puts("");
        }
    }

    return 0;
}
