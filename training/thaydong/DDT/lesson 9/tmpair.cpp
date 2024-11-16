#include<bits/stdc++.h>
using namespace std;

int n;

int solve(int n){
    int res = 0;
    for (int i = 1; i <= sqrt(n); i ++)
        if ( n % i == 0 )
            if ( n/i == i ){
                if ( n/i == 2 ) res += i;
                else res += 2;
            }
            else{
                //cout << i << ' ' << n/i << '\n';
                if ( i == 2 ) res += 1;
                else res += 2;

                if ( i == 1 ) continue;

                if ( n/i == 2 ) res += 1;
                else res += 2;
            }
    return res;
}

int main(){
    cin >> n;
    cout << solve(n);
    return 0;
}
