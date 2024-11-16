#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, s, t, tg;

int main(){
        cin>>t;
        for(ll h = 1; h <= t; h++){
            cin >> n >> s;
            tg = n*(n + 1)/ 2;
            if( tg % 2 == 0 && s % 2 != 0 ){
                cout<<0<<'\n';
                continue;
            }
            if( tg % 2 != 0 && s % 2 == 0 ){
                cout<<0<<'\n';
                continue;
            }
            if ( tg >= s ){
                cout<<1<<'\n';
                continue;
            }
            else cout<<0<<'\n';
        }
}
