/*
    author: Tran Van Nam
    Da Nang University of Science and Technology - Viet Nam
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, S; cin >> n >> S;
    for (int i = 1; i <= n; i++) cin >> a[i];

    bool ok = false;
    map <int, bool> mp;
    for (int i = 1; i <= n; i++){
        if (mp[S - a[i]]) ok = true;
        mp[a[i]] = true;
    }

    cout << (ok ? "YES" : "NO");
    
    return 0^0;
}