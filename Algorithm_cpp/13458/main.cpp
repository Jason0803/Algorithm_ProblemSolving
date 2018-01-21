#include <cstdio>
#include <vector>
#define MAX 1000000
using namespace std;

//int result[MAX+1];
int main() {
    int n, b, c;
    long long sum = 0;
    scanf("%d", &n);
    vector<int> place(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &place[i]);
    }
    scanf("%d %d", &b, &c);
    int temp, count;
    for(int i=0; i<place.size(); i++) {
        /*
        if(result[place[i]] != 0) {
            sum += result[place[i]];
            continue;
        }
        */
        temp = place[i] - b;
        count = 1;
        if(temp > 0) {
            count += temp / c;
            if(temp % c != 0) count++;
        }
        sum += count;
        //result[place[i]] = count;
    }
    printf("%lld\n", sum);
    return 0;
}
