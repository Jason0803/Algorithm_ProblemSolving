#include <iostream>
#include <queue>
using namespace std;
int N;
queue<int> q;
int main() {
    cin >> N;
    for(int i=1; i<=N; i++) q.push(i);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << ' ';
        if(!q.empty()){
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}
