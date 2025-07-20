#include <bits/stdc++.h>
using namespace std;

long long rand(long long l, long long r){
    long long res = 0;
    for (int i = 1; i <= 4; i++) res = (res << 15) ^ (rand() & ((1 << 15) - 1));
    return l + res % (r - l + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    srand(time(nullptr));

    

    return 0;
}
