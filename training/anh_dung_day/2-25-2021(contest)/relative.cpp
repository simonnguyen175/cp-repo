#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
bool cs[1000001][11];
ll a[1000001], ma[11], ans=0;

void sub1(){
	for(int i=1; i<=n-1; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=0; k<=9; k++)
				if( cs[i][k] && cs[j][k] ){
					ans++;
					break;
				}
	cout << ans;
}


void sub2(){
    int sothu[3];
    int nn=0;
    for (int i=0; i<=9; i++)
        if ( ma[i] > 0 ){
            sothu[++nn]=i;
        }
    for (int i=1; i<=2; i++){
        ll tmp=ma[sothu[i]];
        ans+= tmp*(tmp-1)/2;
    }
    ll sotrung=0;
    for (int i=1; i<=n; i++){
        if ( cs[i][sothu[1]] && cs[i][sothu[2]] )
            sotrung++;
    }
    ans-=sotrung*(sotrung-1)/2;
    cout << ans;
}

void sub3(){
    int sothu[4];
    int nn=0;
    for (int i=0; i<=9; i++)
        if ( ma[i] > 0 ){
            sothu[++nn]=i;
        }
    for (int i=1; i<=3; i++){
        ll tmp=ma[sothu[i]];
        ans+= tmp*(tmp-1)/2;
    }
    int sotrung12=0, sotrung23=0, sotrung13=0, sotrung123=0 ;
    for (int i=1; i<=n; i++){
        if ( cs[i][sothu[1]] && cs[i][sothu[2]] )
            sotrung12++;
        if ( cs[i][sothu[2]] && cs[i][sothu[3]] )
            sotrung23++;
        if ( cs[i][sothu[1]] && cs[i][sothu[3]] )
            sotrung13++;
        if ( cs[i][sothu[1]] && cs[i][sothu[2]] && cs[i][sothu[3]] )
            sotrung123++;
    }
    ans -= sotrung12*(sotrung12-1)/2 + sotrung23*(sotrung23-1)/2 + sotrung13*(sotrung13-1)/2 - sotrung123*(sotrung123-1)/2;
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
  //  freopen("relative.inp","r",stdin);
  //  freopen("relative.out","w",stdout);
    //input_layma
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        ll x=a[i];
        while ( x > 0 ){
            cs[i][x%10]=1;
            x/=10;
        }
        for (int j=0; j<=9; j++)
            if ( cs[i][j] ) ma[j]++;
    }
    //solve
    if ( n <= 1000 ) {sub1(); return 0;}
    int SoCauTao=0;
    for (int i=0; i<=9; i++){
        if ( ma[i] > 0 ) SoCauTao++;
    }
    //sub2
    if ( SoCauTao == 2 ) {sub2(); return 0;}
    //sub3
    if ( SoCauTao == 3 ) {sub3(); return 0;}
    cout << "sub 4 em chua lam duoc";
    return 0;
}
