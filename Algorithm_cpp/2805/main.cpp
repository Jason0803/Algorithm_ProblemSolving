#include <iostream>
#include <vector>
using namespace std;
int n, m, mx, result;
long long sum;
int main() {
    cin >> n >> m;
    vector<int> trees(n);
    for(int i=0; i<n; i++){
        cin >> trees[i];
        if(mx < trees[i]) mx = trees[i];
    }
    int left = 1;
    int right = mx;
    
    while(left <= right) {
        sum = 0;
        int mid = (left+right)/2;
        for(int tree : trees) {
            if(tree > mid) {
                sum += tree - mid;
            }
        }
        if(sum >= m) {
            left = mid + 1;
            if(result < mid) result = mid;
        }
        else right = mid - 1;
    }
    cout << result << '\n';
    return 0;
}
