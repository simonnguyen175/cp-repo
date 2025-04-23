#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a[10];
    int n = 6;
    long long base = 1;

    for (int i = 1; i <= n; i ++){
        base *= i;
        a[i] = i;
    }

    cout << base << '\n';

    long long ans = 0;
    do{
        int ck = 1;
        for (int i = 1; i <= n; i ++)
            if ( a[i] == i ){
                cout << a[i] << ' ';
                ck = 0;
                break;
            }
        if ( ck == 0 ){
            for (int i = 1; i <= n; i ++)
                cout << a[i] << ' ';
            cout << '\n';
        }
        ans += ck;
    }while ( next_permutation(a + 1, a + 1 + n) );

    cout << fixed << setprecision(2) << (double) ans / base;

    return 0;
}
