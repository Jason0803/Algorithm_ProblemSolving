#include <cstdio>
#include <vector>

using namespace std;
int main() {
    int n, q, input;
    scanf("%d", &n);
    vector<int> seq(n);
    
    scanf("%d", &q);
    if(q == 1) {
        scanf("%d", &input);
        if(input != 1){
            for(int i=0; i<n; i++)
                seq[i] = i+1;
            
            for(int i=0; i<input-1; i++)
                next_permutation(seq.begin(), seq.end());
        }
        for(int i=0; i<n; i++)
            printf("%d ", seq[i]);
        puts("");
    } else if(q == 2) {
        for(int i=0; i<n; i++)
            scanf("%d", &seq[i]);
        
        int count = 1;
        while(prev_permutation(seq.begin(), seq.end()))
            count++;
        printf("%d\n", count);
    }
    return 0;
}
