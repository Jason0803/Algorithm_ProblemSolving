#include <iostream>
using namespace std;
int t, test_case, input, max_count, max_score;
int count_scores[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    for(int test_case = 1; test_case <= 10; test_case++) {
        cin >> t;
        max_count = -1;
        max_score = -1;
        
        for(int i=0; i<1000; i++) {
            cin >> input;
            count_scores[input]++;
        }
        
        for(int score = 1; score <= 100;  score++) {
            if(max_count <= count_scores[score]) {
                max_count = count_scores[score];
                max_score = score;
            }
            count_scores[score] = 0;
        }
        cout << "#" << t << " " << max_score << '\n';
    }
    return 0;
}
