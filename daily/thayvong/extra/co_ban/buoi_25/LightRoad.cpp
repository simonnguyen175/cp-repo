#include <bits/stdc++.h>
#define simon "LightRoad"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=5e4+1;
const int oo=1e18;

struct kq{
    float s;
    int l;
    int r;
};

int n, d[300];
string s;
kq ans;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    cin >> s;
    s=' '+s;
    ans.s=INT_MAX;

    for (int t=1; t<=26; t++){
        // khoi tao
        //cout << t <<'\n';
        if ( t > n ) break;
        int num=0, id=1, res=0, l ,r;
        for (char i='a'; i<='z'; i++) d[i]=0;

        // xuli
        for (int i=1; i<=n; i++){
            d[s[i]]++; if ( d[s[i]] == 1 ) num++;
            while ( num > t ){
                d[s[id]]--;
                if ( d[s[id]] == 0 ) num--;
                id++;
            }
            //cout << id <<' '<<i<<' '<<num<<'\n';
            if ( num == t )
                if ( res < i-id+1 ){
                    l=id; r=i;
                    res=i-id+1;
                }
        }
        // cap nhat
        if ( ans.s > (float) t/res ){
            ans.s=(float) t/res;
            ans.l=l;
            ans.r=r;
            //cout << "cap nhat:"<<' '<<ans.s <<' '<<ans.l <<' '<<ans.r<<'\n';
        }
    }

    cout << ans.l << ' ' <<ans.r;
    return 0;
}
