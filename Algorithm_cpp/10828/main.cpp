#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> st;
int N;
string cmd;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin  >> N;
    while(N--) {
        cin >> cmd;
        if(cmd == "push") {
            int n;
            cin >> n;
            st.push(n);
        } else if(cmd == "top") {
            if(st.empty()) cout << "-1\n";
            else cout << st.top() << '\n';
        } else if(cmd == "size") {
            cout << st.size() << '\n';
        } else if(cmd == "pop") {
            if(st.empty()) cout << "-1\n";
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if(cmd == "empty") {
            cout << st.empty() << '\n';
        }
    }
    return 0;
}
