#include <bits/stdc++.h>
using namespace std;

string s;
int n,k,a1,a2,b1,b2;
string d[1000000];

void Dao(int d, int c, int l ,int r){
    for (int i=d; i<=(d+c)/2; i++)
        swap(s[i],s[c-(i-d)]);
    for (int i=l; i<=(l+r)/2; i++)
        swap(s[i],s[r-(i-l)]);
}

int main(){
    freopen("swap.inp","r",stdin);
    freopen("swap.out","w",stdout);
    //INPUT
    cin >> n >> k;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    //SETUP
    s="";
    for (int i=1; i<=n; i++)
        s+= (char) i;
    s=' '+s;
    string temp=s;
    memset(d, 0, sizeof d);
    int j=0;
    d[0] =s;
    //SOLVE
    for (int i=1; i<=k; i++){
        Dao(a1,a2,b1,b2);
        j++;
        if ( s == temp ) break;
        d[j]=s;
    }
    if ( j == k ){
        for (int i=1; i<=n; i++)
            cout << (int) s[i] <<"\n";
    }
    else{
        k%=j;
        for (int i=1; i<=n; i++)
            cout << (int) d[k][i] <<"\n";
    }
    return 0;
}
