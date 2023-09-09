#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(){
    long long resp = 0;
    scanf("%d %d", &N, &K);

    vector <int> V(N);

    for(int i=0; i<N; i++)
        scanf("%d", &V[i]);

    for(int i=1; i<N; i++)
        V[i] += V[i-1];

    for(int i=0; i<N; i++) {
        if(V[i]==K)
            resp++;
    }

    for(int i=0; i<N; i++) {
        int c = V[i];
        int alvo = c + K;

        auto a = lower_bound(V.begin() + i + 1, V.end(), alvo);
        auto b = upper_bound(V.begin() + i + 1, V.end(), alvo);

        if(*a == alvo) {
            resp += b-a;
        }
    }

    printf("%lld\n", resp);
    return 0;
}
