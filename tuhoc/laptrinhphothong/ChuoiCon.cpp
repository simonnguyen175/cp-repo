#include <bits/stdc++.h>
using namespace std;

int n, m, x, y ;
string  A,B;
string  F[251][251] ;

string Max(string Ax,string Bx){
    string  T1,T2 ;
    if ( Ax == "") return Bx;
    if ( Bx == "") return Ax;
    T1=Ax; T2=Bx;
    while ( T1.size() < T2.size() ) T1='0'+T1;
    while ( T2.size() < T1.size() ) T2='0'+T2;
    if ( T1 > T2 ) return Ax;
    else return Bx;
}

int main(){
    freopen("ChuoiCon.inp", "r",stdin);
    freopen("ChuoiCon.out", "w",stdout);

    cin >> A >> B;
    n = A.size();
    m = B.size();
    A=' '+A;
    B=' '+B;

    int  i,j;
    x=0; y=1;
    for (i=0; i<= n; i++) F[x][i]="";
    F[y][0]="";
    for (i=1; i<=n; i++){
        for (j=1; j<=m; j++)
            if ( A[i] == B[j] )
                F[y][j] = F[x][j-1] + B[j];
            else
                F[y][j] = Max(F[y][j-1],F[x][j]);
        x=1-x; y=1-y;
    }

    while ( F[x][m][0] == '0' && F[x][m].size() > 1 ) F[x][m].erase(0,1);
    cout << F[x][m];
    return 0;
}
