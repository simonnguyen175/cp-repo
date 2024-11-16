#include<bits/stdc++.h>
using namespace std;
const int oo = 1e9;

int A, B, C, a, b, c, d, T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> A >> B >> C >> a >> b >> c >> d >> T;
    int res = oo;
    for (int i = 1; i <= 3; i ++){
        if ( abs(T-a)%d == 0 ){
            if ( T <= a ){
                if ( (a-T)/d <= (B-b)/d + (C-c)/d )
                    res = min(res, (a-T)/d);
            }else if ( T <= A && (T-a)/d <= b/d + c/d )
                res = min(res, (T-a)/d);
        }
        if ( i == 1 ) swap(A, B), swap(a, b);
        if ( i == 2 ) swap(A, C), swap(a, c);
    }

    cout << ( res == oo ? -1 : res );

    return 0;
}
