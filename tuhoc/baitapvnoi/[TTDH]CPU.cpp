#include<bits/stdc++.h>
using namespace std;

int n, ans=INT_MAX;
string s[20];
pair<string, string> opt[20];
bool b[20];

int xungnhip(string a, string b){
    int res=0;
    for (int i=0; i<a.size(); i++)
        if ( a[i] == b[i] ) res++;
        else res+=2;
    return res;
}

void xuli(){
    int time=0;
    //for (int i=1; i<=n; i++) cout << opt[i].first <<' '<<opt[i].second<<'\n';
    //cout << '\n';
    for (int i=1; i<=n; i++)
        time=max(xungnhip(opt[i].first, opt[i].second), time);
    ans=min(ans, time);
}

void gen(int i){
    for (int j=1; j<2*n; j++)
    for (int k=j+1; k<=2*n; k++){
        if ( b[j] || b[k] ) continue;
        opt[i].first=s[j]; b[j]=1;
        opt[i].second=s[k]; b[k]=1;
        if ( i == n ) xuli();
        else gen(i+1);
        b[j]=0; b[k]=0;
    }
}

int main(){
    cin >> n;
    for (int i=1; i<=2*n; i++)
        cin >> s[i];
    gen(1);
    cout << ans;
    return 0;
}
