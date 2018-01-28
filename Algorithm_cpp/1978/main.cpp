#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    bool not_prime[1001];
    not_prime[1] = true;

    for(int i=2; i<=1000; i++)
        for(int j=i*i; j<=1000; j+=i)
            not_prime[j] = true;
    
    int n, input;
    cin >> n;
    int count = 0;
    while(n--) {
        cin >> input;
        if(!not_prime[input]) count++;
    }
    cout << count << '\n';
    return 0;
}
