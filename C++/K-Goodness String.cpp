#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++){
        int N, K;
        cin >> N >> K;
        string s; cin >> s;
        int diff = 0;
        for(int i=0; i<N-i-1; i++){
            if(s[i] != s[N-i-1]) diff++;
        }
        int answer = K - diff;
        if(answer < 0) answer = -answer;
        printf("Case #%d: %d\n",tc, answer);
    }
    return 0;
}
