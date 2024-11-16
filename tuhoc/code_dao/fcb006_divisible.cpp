#include<bits/stdc++.h>
using namespace std;

long long cnt(long long l, long long r, int x){
    if ( l == 0 ) return r/x + 1; 
    else return r/x - (l-1)/x; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        long long l, r;
        cin >> l >> r; 
        cout << cnt(l, r, 4) + cnt(l, r, 7) + cnt(l, r, 11) 
                - cnt(l, r, 4*7) - cnt(l, r, 7*11) - cnt(l, r, 11*4) 
                + cnt(l, r, 4*7*11) << '\n';      
    }

    return 0; 
}