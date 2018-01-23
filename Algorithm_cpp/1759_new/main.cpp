#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int l, c;
vector<char> a;
bool check(string password) {
    int ja = 0;
    int mo = 0;
    for(char c : password) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u')
            mo ++;
        else ja++;
    }
    return ja >= 2 && mo >= 1;
}
void solve(string password, int index) {
    if(password.length() == l) {
        if(check(password)) {
            cout << password << '\n';
        }
        return;
    }
    if(index == a.size()) return;
    solve(password+a[index], index+1);
    solve(password, index+1);
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin >> l >> c;
    a.resize(c);
    for(int i=0; i<c; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    solve("", 0);

    return 0;
}
