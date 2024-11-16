#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int n, a[N], ans=INT_MAX;
int ln=INT_MIN, nn=INT_MAX;
int MIN[N], MAX[N];

int tknp(int l, int r, int key, bool x){
    int d=l, c=r, res=0;
    if ( x ){
        while ( d <= c ){
            int mid=(d+c)/2;
            if ( MIN[mid] <= key ){
                res=mid;
                d=mid+1;
            }
            else c=mid-1;
        }
        return res;
    }
    else{
        while ( d <= c ){
            int mid=(d+c)/2;
            if ( MIN[mid] >= key ){
                res=mid;
                c=mid-1;
            }
            else d=mid+1;
        }
        return res;
    }
}

int main(){
    freopen("minmaxseq.inp","r",stdin);
    freopen("minmaxseq.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nn=min(a[i], nn);
        ln=max(a[i], ln);
    }
    if ( nn == ln ){
        cout << 1;
        return 0;
    }
    int nmin=0, nmax =0;
    for (int i=1; i<=n; i++){
        if ( a[i] == nn ) MIN[++nmin]=i;
        if ( a[i] == ln ) MAX[++nmax]=i;
    }
    //for (int i=1; i<=nmin; i++) cout << MIN[i] <<' '; cout <<'\n';
    //for (int i=1; i<=nmax; i++) cout << MAX[i] <<' '; cout <<'\n';
    for (int i=1; i<=nmax; i++){
        int pos1=tknp(1, nmin, MAX[i], 1);
        int pos2=tknp(1, nmin, MAX[i], 0);
        int tmp=min(MAX[i]-MIN[pos1]+1, MIN[pos2]-MAX[i]+1);
        if ( pos1 == 0 ) tmp=MIN[pos2]-MAX[i]+1;
        if ( pos2 == 0 ) tmp=MAX[i]-MIN[pos1]+1;
        //cout << pos1 << ' ' <<pos2 <<'\n';
        ans=min(ans, tmp);
    }
    cout << ans;
    return 0;
}
