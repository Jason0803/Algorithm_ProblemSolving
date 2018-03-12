#include <iostream>
#include <string.h>
#include <vector>
#define MAX_SIZE 401
using namespace std;
int n, k, s;
int found[MAX_SIZE][MAX_SIZE];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n >> k;
    
    int u, v;
    while(k--) {
        cin >> u >> v;
        found[u][v] = -1;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(found[i][k] == found[k][j] && found[i][k] != 0) {
                    found[i][j] = found[i][k];
                }
            }
        }
    }
    cin >> s;
    for(int i=0; i<s; i++) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> u >> v;
        if(found[u][v] == -1) cout << "-1\n";
        else if(found[v][u] == -1) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
