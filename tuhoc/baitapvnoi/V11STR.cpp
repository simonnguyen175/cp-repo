#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll base = 70001;
const ll MOD = 1e9 + 7;

int np, nt;
int p[N], t[N];
ll Pow[N], HashP[N], HashT[N];

ll getHashT(int i, int j) {
    return (HashT[j] - HashT[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
}

ll getHashP(int i, int j){
    return (HashP[j] - HashP[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
}

void build(){
    Pow[0] = 1;
    for (int i = 1; i <= nt; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= np; i ++)
        HashP[i] = ( HashP[i - 1] * base + p[i] ) % MOD;

    for (int i = 1; i <= nt; i ++)
        HashT[i] = ( HashT[i - 1] * base + t[i] ) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> np >> nt;
    for (int i = 1; i <= np; i ++)
        cin >> p[i];
    for (int i = 1; i <= nt; i ++)
        cin >> t[i];

    build();

    for (int i = 1; i <= nt - np + 1; i ++){
        int d = i, c = i + np - 1, res = i - 1;

        while ( d <= c ){
            int mid = ( d + c ) / 2;
            if ( getHashT(i, mid) == HashP[mid - i + 1] ){
                res = mid;
                d = mid + 1;
            }
            else c = mid - 1;
        }

        if ( res == i + np - 1 ) {cout << i; return 0;}
        else if ( getHashT(res + 2, i + np - 1) == getHashP(res - i + 3, np) ){
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;

}
