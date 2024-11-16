#include<bits/stdc++.h>
using namespace std;
const int N = 45;

int n, m;
int a[N], chosen[N];
vector<ll> N1, N2;

void gen(int id){
    for (int i = 0; i <= 1; i ++){
        chosen[id] = i;
        if ( id == n/2 ){
            ll tmp = 0;
            for (int j = 1; j <= n/2; j ++)
                if ( chosen[j] ) tmp += a[j];
            N1.pb(tmp);
        }
        else if ( id == n ){
            ll tmp = 0;
            for (int j = n/2; j <= n; j ++)
                if ( chosen[j] ) tmp += a[j];
            N2.pb(tmp);
        }
        else gen(id + 1);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    gen(1); gen(n/2+1);

    sort(N1.begin(), N1.end());
    sort(N2.begin(), N2.end());

    return 0;
}
