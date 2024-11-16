#include<bits/stdc++.h>
#define ll long long
#define ci vector<pair<char, ll>>
#define pb push_back
#define fi first
#define se second
using namespace std;

string type, x, y;
ll p, c;
ll s[1005];

ci Combine(ci a, ci b){
    if ( a[a.size()-1].fi == b[0].fi ){
        a[a.size()-1].se += b[0].se;
        for (int i = 1; i <= b.size()-1; i ++)
            a.pb(b[i]);
        return a;
    }
    else{
        for (auto it : b) a.pb(it);
        return a;
    }
}

ll tknp(ll l, ll r, ll x){
    ll d = l, c = r, res = -1;

    while ( d <= c ){
        ll mid = ( d + c ) / 2;
        if ( s[mid] >= x ){
            res = mid;
            c = mid - 1;
        }
        else d = mid + 1;
    }

    return res;
}

ci Copy(ci a, ll p, ll c){
    ci res;
    s[0] = a[0].se;
    for (int i = 1; i <= a.size()-1; i ++)
        s[i] = s[i-1] + a[i].se;

    ll id = tknp(0, a.size()-1, p);

    res.pb({a[id].fi, s[id]-p+1});

    ll len = s[id]-p+1;

    while ( len < c ){
        id ++;
        res.pb({a[id].fi, a[id].se});
        len += a[id].se;
    }

    res[res.size()-1].se -= len - c;

    return res;
}

ci prep(string x){
    ci res;
    char c = x[0]; ll sl = 0;
    for (int i = 1; i < x.size(); i ++){
        if ( x[i] >= '0' && x[i] <= '9' )
            sl = sl*10 + (x[i]-'0');
        else{
            res.pb({c, sl});
            c = x[i];
            sl = 0;
        }
    }
    res.pb({c, sl});
    return res;
}

ll len(string x){
    ll res = 0, sl = 0;
    for (int i = 1; i < x.size(); i ++){
        if ( x[i] >= '0' && x[i] <= '9' )
            sl = sl*10 + (x[i]-'0');
        else{
            res += sl;
            sl = 0;
        }
    }
    res += sl;
    return res;
}

void print(ci x){
    for (auto it : x) cout << it.fi << it.se;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("rlestr.inp", "r", stdin);
    freopen("rlestr.out", "w", stdout);

    while ( cin >> type ){
        if ( type == "@1" ){
            cin >> x >> y;
            ci a = prep(x), b = prep(y);
            ci res = Combine(a, b);
            cout << "@1: "; print(res);
            cout << '\n';
        }

        if ( type == "@2" ){
            cin >> x >> p >> c;
            ci a = prep(x), b = prep(x);
            if ( p == 1 ){
                if ( c == len(x) ) cout << "@2: \n";
                else{
                    b = Copy(b, p+c, len(x)-(p+c)+1);
                    cout << "@2: "; print(b);
                    cout << '\n';
                }
            }
            else{
                ci res;
                a = Copy(a, 1, p-1);
                if ( p + c - 1 == len(x) ){
                    res = a;
                }
                else{
                    b = Copy(b, p+c, len(x)-(p+c)+1);
                    res = Combine(a, b);
                }
                cout << "@2: "; print(res);
                cout << '\n';
            }
        }

        if ( type == "@3" ){
            cin >> x >> p >> c;
            ci res = Copy(prep(x), p, c);
            cout << "@3: "; print(res);
            cout << '\n';
        }

        if ( type == "@4" ){
            cin >> x >> y >> p;
            ci a = prep(x), b = prep(y);

            if ( p == 1 ){
                cout << "@4: "; print(Combine(b, a));
                cout << '\n';
                continue;
            }

            if ( p == len(x) + 1 ){
                cout << "@4: "; print(Combine(a, b));
                cout << '\n';
                continue;
            }


            ci l = Copy(a, 1, p-1), mid = b, r = Copy(a, p, len(x)-p+1);
            cout << "@4: "; print(Combine(Combine(l, mid), r));
            cout << '\n';
        }
    }

    return 0;
}

