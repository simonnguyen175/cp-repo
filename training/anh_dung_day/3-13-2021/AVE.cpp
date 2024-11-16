#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
using namespace std;
const ld eps=1e-12;
const int N=1e5+5;

int n, k;
ld a[N], s[N], c[N];

bool check(ld x, bool m){
    if ( m ){
        c[0]=LLONG_MAX;
        for (int i=1; i<=n; i++)
            c[i]=min(c[i-1], s[i]-i*x);
        for (int i=k; i<=n; i++)
            if ( c[i-k] <= s[i]-i*x ) return true;
        return false;
    }
    else{
        c[0]=0;
        for (int i=1; i<=n; i++)
            c[i]=max(c[i-1], s[i]-i*x);
        for (int i=k; i<=n; i++)
            if ( c[i-k] >= s[i]-i*x ) return true;
        return false;
    }
}

ld tknp(ld l, ld r, bool x){
    if (x){
        ld d=l, c=r, res;
        while ( d <= c ){
            ld mid=(d+c)/2;
            if ( check(mid,1) ){
                res=mid;
                d=mid+eps;
            }
            else c=mid-eps;
        }
        return res;
    }
    else{
        ld d=l, c=r, res;
        while ( d <= c ){
            ld mid=(d+c)/2;
            if ( check(mid,0) ){
                res=mid;
                c=mid-eps;
            }
            else d=mid+eps;
        }
        return res;
    }
}

int main(){
   // freopen("AVE.inp","r",stdin);
   // freopen("AVE.out","w",stdout);
    FASTio
    cin >> n >> k;
    cout << fixed << setprecision(6);
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    ld avemin = tknp(1, 1000000000, 0);
    ld avemax = tknp(1, 1000000000, 1);
    cout << avemin <<' '<<avemax;
    return 0;
}
