#include <iostream>
#include <string>
using namespace std;
typedef struct _Point {
    int r, c;
} Point;
Point pk, ps;
int commands, map[9][9];
int dr[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};
string king, stone, command;
char col;
int row;
// for transformation
bool isOut(int r, int c){
    return (r < 1 || r > 8 || c < 1 || c > 8);
}
int str_to_int(string cmd) {
    if(cmd == "R") return 0;
    else if(cmd == "L") return 1;
    else if(cmd == "B") return 2;
    else if(cmd == "T") return 3;
    else if(cmd == "RT") return 4;
    else if(cmd == "LT") return 5;
    else if(cmd == "RB") return 6;
    else return 7;
}
int main() {
    cin >> king >> stone >> commands;
    // A : 65.
    pk.c = king[0] - 64;
    pk.r = king[1] -'0';
    ps.c = stone[0] - 64;
    ps.r = stone[1] -'0';
    while(commands--) {
        cin >> command;
        int cmd = str_to_int(command);
        int npr = pk.r + dr[cmd];
        int npc = pk.c + dc[cmd];
        if(isOut(npr, npc)) continue;

        if(npr == ps.r && npc == ps.c) {
            int nsr = ps.r + dr[cmd];
            int nsc = ps.c + dc[cmd];
            if(isOut(nsr, nsc)) continue;
            
            ps.r = nsr;
            ps.c = nsc;
        }
        
        pk.r = npr;
        pk.c = npc;
    }
    col = pk.c + 64;
    cout << col << pk.r << '\n';
    col = ps.c + 64;
    cout << col << ps.r << '\n';
    return 0;
}
