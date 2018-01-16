#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> seq;

int calculate() {
    int sum = 0;
    for(int i=1; i<seq.size(); i++){
        sum += abs(seq[i] - seq[i-1]);
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    seq.resize(n);
    for(int i=0; i<n; i++){
        scanf("%d", &seq[i]);
    }
    sort(seq.begin(), seq.end());
    int result = 0;
    do {
        int temp = calculate();
        result = max(result, temp);
    } while(next_permutation(seq.begin(), seq.end()));
    
    printf("%d\n", result);
    return 0;
}
