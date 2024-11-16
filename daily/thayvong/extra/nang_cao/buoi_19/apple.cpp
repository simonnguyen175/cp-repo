#include <bits/stdc++.h>
#define simon "apple"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e4+1;
const int oo=1e18;

string genApp, spGen;
int cost[256], cp[5001], ans;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> genApp >> spGen;
    cin >> cost['A'] >> cost['C'] >> cost['G'] >> cost['T'];
    cp[0]=cost[spGen[0]];
    for (int i=1; i<spGen.size(); i++)
        cp[i]=cp[i-1]+cost[spGen[i]];
    ans=cp[spGen.size()-1];

    //for (int i=0; i<spGen.size(); i++)
    //    cout << cp[i] <<' ';
    //cout <<'\n';

    for (int i=0; i<genApp.size(); i++){

        int pos=spGen.find(genApp[i]);
        if ( pos == -1 ) continue;
        int id=i-1, res=0;
        //cout << genApp[i] <<'\n';
        for (int j=pos-1; j>=0; j--){
            //cout << j <<' '<<id<<' ';
            if ( id < 0 ){
                res+=cp[j];
                break;
            }
            if ( genApp[id] == spGen[j] )
                id--;
            else
                res+=cost[spGen[j]];
            //cout << res <<'\n';
        }

        id=i+1;
        for (int j=pos+1; j<spGen.size(); j++){
            //cout << j <<' '<<id<<' ';
            if ( id == genApp.size() ){
                res+=cp[spGen.size()-1]-cp[j-1];
                break;
            }
            if ( genApp[id] == spGen[j] )
                id++;
            else{
                res+=cost[spGen[j]];
            }
            //cout << res <<'\n';
        }
        //cout << res <<'\n';
        ans=min(ans, res);
    }
    cout << ans;
    return 0;
}
