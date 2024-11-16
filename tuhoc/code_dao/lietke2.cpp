#include <bits/stdc++.h>
using namespace std;

int n;
char a[21];

bool check(){
    int tmp=0;
    for (int i=1; i<=2*n; i++){
        if ( tmp < 0 ) return false;
        if ( a[i] == ')' ) tmp--;
        else tmp++;
    }
    return true;
}

void in(){
    for (int i=1; i<=2*n; i++)
        cout << a[i] <<' ';
    cout <<'\n';
}

void xuli(){
    int mo=0, dong=0;
    for (int i=1; i<=2*n; i++)
        if ( a[i] == '(' ) mo++;
        else dong++;
    if ( mo == dong ){
        if ( check() ) in();
        else return;
    }
    else return;
}

void gen(int i){
    for (char j='('; j<= ')'; j++){
        a[i]=j;
        if ( i == 2*n ) xuli();
        else gen(i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
        cout.tie(0);
    cin >> n;
    gen(1);
    return 0;
}
