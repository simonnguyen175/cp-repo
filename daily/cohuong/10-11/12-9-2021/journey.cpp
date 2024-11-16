#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int Tx, Ty, rem;
string s;
vector<char> cont;
int cnt[5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("journey.inp", "r") ){
        freopen("journey.inp", "r", stdin);
        freopen("journey.out", "w", stdout);
    }

    cin >> Tx >> Ty >> s;
    for (int i = 0; i < s.size(); i ++){
        if ( s[i] == 'U' ) Ty --;
        if ( s[i] == 'R' ) Tx --;
        if ( s[i] == 'D' ) Ty ++;
        if ( s[i] == 'L' ) Tx ++;
        if ( s[i] == '?' ) rem ++;
    }

    if ( Tx + Ty > rem ) { cout << "IMPOSSIBLE"; return 0; }

    // 0 la U, 1 la R, 2 la D, 3 la L
    if ( Tx > 0 ) cnt[1] += abs(Tx);
    if ( Tx < 0 ) cnt[3] += abs(Tx);
    if ( Ty > 0 ) cnt[0] += abs(Ty);
    if ( Ty < 0 ) cnt[2] += abs(Ty);

    if ( abs(Tx) + abs(Ty) < rem )
        if ( ( rem - abs(Tx) - abs(Ty) ) % 2 == 1 ) { cout << "IMPOSSIBLE"; return 0; }
        else{
            cnt[2] += ( rem - abs(Tx) - abs(Ty) )/2;
            cnt[0] += ( rem - abs(Tx) - abs(Ty) )/2;
        }

    for (int i = 1; i <= cnt[0]; i ++) cont.pb('U');
    for (int i = 1; i <= cnt[1]; i ++) cont.pb('R');
    for (int i = 1; i <= cnt[3]; i ++) cont.pb('L');
    for (int i = 1; i <= cnt[2]; i ++) cont.pb('D');

    for (int i = 0; i < s.size(); i ++)
        if ( s[i] == '?' ){
            s[i] = cont.back();
            cont.pop_back();
        }

    cout << s;

    return 0;
}
