#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 727355608;

int s, a[5];
int st[N];
ll mu[N];

int main(){
    cin >> s;

    for (int i = 1; i <= 3; i ++)
        cin >> a[i];

    mu[0] = 1;
    for (int i = 1; i <= s; i ++)
        mu[i] = mu[i-1] * 4 % MOD;

    for (int i = 1; i <= 3; i ++)
        if ( a[i] >= 2 ){
            a[i] -= 2;
            st[1] = st[s] = i;
            break;
        }


    int sl = s - 2;
    for (int i = 2; i <= s/2; i ++){
        if ( sl - 2 > a[1] + a[2] + a[3] ){
            sl -= 2;
            continue;
        }
        else{
            for (int j = 1; j <= 3; j ++){
                if ( a[j] >= 2 ){
                    a[j] -= 2;
                    st[i] = st[s-i+1] = j;
                    break;
                }
            }
        }
    }

    if ( s % 2 )
        for (int i = 1; i <= 3; i ++)
            if ( a[i] >= 1 ){
                st[s/2+1] = i;
                a[i] --;
            }

    for (int i = 1; i <= 3; i ++)
        if ( a[i] > 0 ){
            cout << "Bedao!" << '\n';
            return 0;
        }


    ll ans = 0;
    for (int i = s, j = 0; i >= 1; i --, j ++){
        ans = ( ans + st[i] * mu[j] % MOD ) % MOD;
    }

    cout << ans;

    return 0;
}
