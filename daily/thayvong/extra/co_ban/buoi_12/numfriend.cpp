#include <bits/stdc++.h>
using namespace std;

long long s[5000001];
int mv= 5e6;
long long ans=0, a, b;

int main(){
 //   freopen("numfriend.inp","r",stdin);
 //   freopen("numfriend.out","w",stdout);
    //INPUT
    cin >> a >> b;
    //SETUP&SOLVE
    long long t, e;
    for (int i=1; i<=mv; i++)
        s[i]=1;
    for (int i=2; i<=mv; i++){
        if ( s[i] == 1 ){
            t=1;
            while ( t * i <= mv ){
                e = t * i;
                s[e] = s[e]+i*s[t];
                t++;
            }
        }
    }
    for (int i=1; i<=mv; i++)
        s[i]-=i;
    for (int i=a; i<=b; i++){
        if ( s[s[i]] == i && s[i] <= b && i != s[i]) {
                ans++;
        }
    }
    //OUTPUT
    cout << ans/2;
    return 0;
}
