#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
#define HEDGE_HOG 'S'
#define STONE 'X'
#define WATER '*'
#define EMPTY '.'
#define CAVE 'D'
using namespace std;
#define MAX 50
int  r, s;
char map[MAX+1][MAX+1];
int  flood[MAX+1][MAX+1];
int  painter[MAX+1][MAX+1];
int  dr[] = {0, 0, 1, -1};
int  dc[] = {1, -1, 0, 0};
queue<pair<int, int> > Q;

int main() {
    memset( flood, -1, sizeof flood );
    memset( painter, -1, sizeof painter );
    
    scanf( "%d%d", &r, &s);
    for ( int i=0; i<r; ++i )
        scanf( "%s", map[i] );
    
    // s = HEDGE_HOG, d = CAVE
    int sx=-1, sy=-1, dx=-1, dy=-1;
    
    for ( int i=0; i<r; ++i ) {
        for ( int j=0; j<s; ++j ) {
            
            // 동굴과 고슴도치 위치 갱신
            if ( map[i][j] == HEDGE_HOG ) {
                sx = i; sy = j;
                map[i][j] = EMPTY;
            }
            
            if ( map[i][j] == CAVE ) {
                dx = i; dy = j;
            }
            // flood[][] == 1 : 물이 찰 곳,
            // flood[][] == 0 : 현재 물이 찬 곳
            // flood[][] == -1 : default
            if ( map[i][j] == WATER ) flood[i][j] = 0;
            if ( map[i][j] == EMPTY ) {
                // 길일 경우, 인접한 칸이 물인지 확인
                bool flooded = false;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if ( ni < 0 || ni >= r ) continue;
                    if ( nj < 0 || nj >= s ) continue;
                    if ( map[ni][nj] == WATER ) flooded = true;
                }
                if ( flooded ) {
                    Q.push( make_pair(i, j) );
                    flood[i][j] = 1;
                }
            }
        }
    }
    // flood
    while ( !Q.empty() ) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for ( int k=0; k<4; ++k ) {
            int nx = x + dr[k];
            int ny = y + dc[k];
            if ( nx < 0 || nx >= r ) continue;
            if ( ny < 0 || ny >= s ) continue;
            if ( flood[nx][ny] == -1 && map[nx][ny] != STONE && map[nx][ny] != CAVE ) {
                flood[nx][ny] = flood[x][y] + 1;
                Q.push( make_pair( nx, ny ) );
            }
        }
    }
    
    // painter
    painter[sx][sy] = 0;
    Q.push( make_pair( sx, sy ) );
    
    while ( !Q.empty() ) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for ( int k = 0; k < 4; ++k ) {
            int nx = x + dr[k];
            int ny = y + dc[k];
            if ( nx < 0 || nx >= r ) continue;
            if ( ny < 0 || ny >= s ) continue;
            if ( painter[nx][ny] == -1 && map[nx][ny] != STONE )
                if ( flood[nx][ny] > painter[x][y] + 1 || flood[nx][ny] == -1 ) {
                    painter[nx][ny] = painter[x][y] + 1;
                    Q.push(make_pair(nx, ny));
                }
        }
    }
    /*
     summary: 물이 갈 수 있는곳 (첫 부분부터 거리마다 +1
     --> 고슴도치 움직이며 현재 움직임 수+1 보다 물 움직임 수가 많으면 이동 가능
     */
    if ( painter[dx][dy] != -1 )
        printf( "%d\n", painter[dx][dy] );
    else
        printf( "KAKTUS\n" );
    
    return 0;
}

