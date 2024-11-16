#include <bits/stdc++.h>
using namespace std;

int n, x[1000001], y[1000001], l=0, r=0;
char huong;

int main(){
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    if ( x[2]-x[1] == 1 && y[2] == y[1] ) huong='R';
    if ( x[2]-x[1] == -1 && y[2] == y[1] ) huong='L';
    if ( x[2] == x[1] && y[2] == y[1]+1 ) huong='B';
    if ( x[2] == x[1] && y[2] == y[1]-1 ) huong='N';
    for (int i=3; i<=n; i++){
        if ( huong == 'R' ){
            if ( x[i]-x[i-1] == 1 && y[i] == y[i-1] ) huong='R';
            if ( x[i]-x[i-1] == -1 && y[i] == y[i-1] ) huong='L';
            if ( x[i] == x[i-1] && y[i] == y[i-1]+1 ) {huong='B'; l++;}
            if ( x[i] == x[i-1] && y[i] == y[i-1]-1 ) {huong='N'; r++;}
        }
        if ( huong == 'L' ){
            if ( x[i]-x[i-1] == 1 && y[i] == y[i-1] ) huong='R';
            if ( x[i]-x[i-1] == -1 && y[i] == y[i-1] ) huong='L';
            if ( x[i] == x[i-1] && y[i] == y[i-1]+1 ) {huong='B'; r++;}
            if ( x[i] == x[i-1] && y[i] == y[i-1]-1 ) {huong='N'; l++;}
        }
        if ( huong == 'B' ){
            if ( x[i]-x[i-1] == 1 && y[i] == y[i-1] ) {huong='R'; r++;}
            if ( x[i]-x[i-1] == -1 && y[i] == y[i-1] ) {huong='L'; l++;}
            if ( x[i] == x[i-1] && y[i] == y[i-1]+1 ) huong='B';
            if ( x[i] == x[i-1] && y[i] == y[i-1]-1 ) huong='N';
        }
        if ( huong == 'N' ){
            if ( x[i]-x[i-1] == 1 && y[i] == y[i-1] ) {huong='R'; l++;}
            if ( x[i]-x[i-1] == -1 && y[i] == y[i-1] ) {huong='L'; r++;}
            if ( x[i] == x[i-1] && y[i] == y[i-1]+1 ) huong='B';
            if ( x[i] == x[i-1] && y[i] == y[i-1]-1 ) huong='N';
        }
    }
    cout << r <<" "<<l;
    return 0;
}
