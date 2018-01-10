#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N, target, input, sum;
    vector<int> list;
    scanf("%d %d", &N, &target);
    
    while(N--){
        scanf("%d", &input);
        list.push_back(input);
    }
    
    sort(list.begin(), list.end());
    sum = 0;

    return 0;
}
