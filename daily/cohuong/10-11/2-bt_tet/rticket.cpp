#include <bits/stdc++.h>
using namespace std;

int l[4], c[4], n, s, t;
long long a[100001], len[100001];

int tknp(long long a[], int l, int r, long long x){
    int d=l, c=r, res=0;
    while ( d <= c ){
        int mid = (d+c)/2;
        if ( a[mid] >= x ){
            res = mid;
            c=mid-1;
        }
        else d=mid+1;
    }
    return res;
}

int main(){
    freopen("rticket.inp","r",stdin);
    freopen("rticket.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    for (int i=1; i<=3; i++) cin >> l[i];
    for (int i=1; i<=3; i++) cin >> c[i];
    cin >> n >> s >> t;
    if ( s > t ) swap(s,t);
    for (int i=2; i<= n; i++)
        cin >> a[i];
    fill(len+s+1, len+n+1, LLONG_MAX);
    for (int i=s+1; i<=t; i++){
        for (int j=1; j<=3; j++){
            int pos=tknp(a,s,i-1,a[i]-l[j]);
            if ( pos == 0 ) continue;
            len[i]=min(len[i],len[pos]+c[j]);
        }
    }
    cout << len[t];
    return 0;
}
