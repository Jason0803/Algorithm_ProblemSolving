#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    string a, b, output;
    int x, y;
    cin >> a >> b;
    int current, next, dist;
    if(a.length() > b.length()) {
        //cout << "a is longer !" << '\n';
        dist = a.length()-b.length();
        for(int i=0; i<dist; i++) {
            b.insert(0, "0");
        }
    } else if(a.length() < b.length()) {
        //cout << "b is longer !" << '\n';
        dist = b.length()-a.length();
        for(int i=0; i<dist; i++) {
            a.insert(0, "0");
        }
    }
    dist = a.length();
    //cout << "dist : " << dist << '\n';
    //cout << "a : " << a << " b : " << b << '\n';
    x = a[dist-1] - '0';
    y = b[dist-1] - '0';

    for(int i=1; i<=dist; i++) {
        x = a[dist-i] - '0';
        y = b[dist-i] - '0';
        //printf("x : %d, y : %d, next : %d\n", x, y, next);
        current = x+y+next;
        output.insert(0, to_string(current%10));
        next = current / 10;
    }
    if(next != 0) {
        output.insert(0, "1");
    }
    cout << output << '\n';
     /*
     123 + 987
     (3 + 7 + 0) / 10 --> 1 : next
     (3 + 7 + 0) % 10 --> 0 : current
     
     (2 + 8 + 1) / 10 --> next
     (2 + 8 + 1) % 10 --> current
     */
    return 0;
}
