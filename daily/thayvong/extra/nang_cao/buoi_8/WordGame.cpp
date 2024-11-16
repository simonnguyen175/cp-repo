#include <bits/stdc++.h>
using namespace std;

int n, k;
string st[100001];
string KhayA[100001], KhayB[100001], KhayC[100001];
int dema=0, demb=0, demc=0;
char t;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("wordgame.INP","r",stdin);
	freopen("wordgame.OUT","w",stdout);
    //INPUT & SETUP
    cin >> n >> k;
    for (int i=1; i<=n; i++)
            cin >> st[i];
    sort(st+1,st+1+n);
    for (int i=1; i<=n; i++){
            if ( st[i][0] == 'a' ){
                dema++;
                KhayA[dema]=st[i];
            }
            if ( st[i][0] == 'b' ){
                demb++;
                KhayB[demb]=st[i];
            }
            if ( st[i][0] == 'c' ){
                demc++;
                KhayC[demc]=st[i];
            }
    }

    /*for (int i=1; i<= dema; i++)
        cout << KhayA[i]<<" ";
    cout <<"\n";
    for (int i=1; i<= demb; i++)
        cout << KhayB[i]<<" ";
    cout <<"\n";
    for (int i=1; i<= demc; i++)
        cout << KhayC[i]<<" ";
    cout <<"\n";*/
    //SOLVE
    int la=0, lb=0, lc=0;
    for (int i=1; i<=k; i++){
        cin >> t;
        if ( t == 'a'){
            la++;
            if ( la > dema ) la-=dema;
            cout <<KhayA[la] <<"\n";
        }
        if ( t == 'b'){
            lb++;
            if ( lb > demb ) lb-=demb;
            cout <<KhayB[lb] <<"\n";
        }
        if ( t == 'c'){
            lc++;
            if ( lc > demc ) lc-=demc;
            cout << KhayC[lc] <<"\n";
        }
    }
    return 0;
}
