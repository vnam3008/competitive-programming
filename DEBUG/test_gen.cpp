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

    long long n = rand(1, 100000);

    string s = "";

    for(int i = 1; i <= n; i++){
        int t = rand(0, 61);

        if(t < 26) s += char('a' + t);
        else if(t < 52) s += char('A' + t - 26);
        else s += char('0' + t - 52);
    }

    cout << s;

    return 0;
}