/*
    author: Tran Van Nam
    Da Nang University of Science and Technology - Viet Nam
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, S; cin >> n >> S;
    for (int i = 1; i <= n; i++) cin >> a[i];

    bool ok = false;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] + a[j] == S) ok = true;

    cout << (ok ? "YES" : "NO");
    
    return 0^0;
}