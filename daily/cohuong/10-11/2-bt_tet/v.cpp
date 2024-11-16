#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll c, a, b, d[12], nl, nr;
string s;
pair<ll, ll> l[1000001], r[1000001];

// so chu so
ll scs(ll x){
    ll tmp=0;
    while ( x > 0 ){tmp++; x/=10;}
    return tmp;
}

// kiem tra co chu so ko thoa man
bool check(ll x){
    while ( x > 0 ){
        if ( !d[x%10] ) return false;
        x/=10;
    }
    return true;
}

ll tknp(ll d, ll c, ll du, ll y, ll x, bool t){
    ll res =0;
    if ( !t ){
        while ( d < c ){
            ll mid=(d+c)/2;
            if ( r[mid].first  == du ){
                if (y+r[mid].second <= x ){
                    res=mid;
                    d=mid+1;
                }
                else c=mid-1;
            }
            else{
                if ( r[mid].first > du ) c=mid-1;
                else d=mid+1;
            }
        }
    }
    else{
        while ( d < c ){
            ll mid=(d+c)/2;
            if ( r[mid].first == du ){
                res=mid;
                c=mid-1;
            }
            else{
                if ( r[mid].first > du ) c=mid-1;
                else d=mid+1;
            }
        }
    }
    return res;
}

//so boi cua c thoa man dk <= x
ll SoBoi(ll x){
    ll n=scs(x);
    ll res =0;
    if ( n <= 6 ){
        for (ll i=1; i<=x; i++)
            if ( check(i) && i % c == 0 ) res++;
    }
    else{
        // cac so < 1e6
        for (ll i=1; i<1000000; i++)
            if ( check(i) && i % c == 0 ) res++;
        // tao mang trai
        nl=0;
        for (ll i=10; i<=1000000; i++){
            if ( i*100000 > x ) break;
            if ( check(i) ){
                nl++;
                l[nl].second=i*100000;
                l[nl].first=(i*100000)%c;
            }
        }
        // tao mang phai
        nr=0;
        if ( d[0] ){
            for (ll i=1; i<=100000; i++)
                if ( check(i) ){
                    nr++;
                    r[nr].second=i;
                    r[nr].first=i%c;
                }
        }
        else{
            for (ll i=10000; i<=100000; i++)
                if ( check(i) ){
                    nr++;
                    r[nr].second=i;
                    r[nr].first=i%c;
                }
        }
        for (int i=1; i<=nl; i++) cout << l[i].second <<' '; cout << '\n';
        cout <<'\n' << res <<'\n';
        sort(l+1, l+1+nl);
        sort(r+1, r+1+nr);
        for (int i=1; i<=nl; i++){
            ll du=(c-l[i].first) % c;
            ll dd=tknp(1, nr, du, l[i].second, x, 1);
            ll cc=tknp(1, nr, du, l[i].second, x, 0);
            cout << l[i].second<<' '<<l[i].first << ' '<< r[dd].second << ' '<< r[cc].second <<'\n';
            cout << r[dd].first<< ' '<<r[cc].first <<'\n';
            cout << dd <<' '<<cc<<'\n';
            if ( dd ==0 || cc ==0 ) continue;
            res+=cc-dd+1;
            if (l[i].second % c == 0) res++;
            //cout << res <<'\n';
        }

    }
    return res;
}

void input(){
    cin >> c >> a >> b >> s;
    memset(d, 0, sizeof d);
    for (int i=0; i<s.size(); i++)
        d[s[i]-'0']=1;
}

void output(){
    SoBoi(b);
    //cout << SoBoi(b) - SoBoi(a-1);
}

int main(){
    freopen("v.inp","r",stdin);
    freopen("v.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    input();
    output();
    return 0;
}
