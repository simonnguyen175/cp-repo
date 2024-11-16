#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    freopen("JumpXH.inp","r",stdin);
    freopen("JumpXH.out","w",stdout);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> n;
        int s=0, dem=0;
        for (int i=0; s < n; i+=1){
            s+=i+1;
            dem++;
        }
        if ( s == n ){
            cout << dem <<"\n";
            for (int i=1; i<=dem; i++)
                cout << 'T';
            cout <<"\n";
        }
        else{
            int e= s-n;
            if ( e == 1 ){
                cout <<dem+1<<"\n";
                for (int i=1; i<=dem; i++)
                    cout <<'T';
                cout << 'L';
            }
            else{
                cout << dem<<"\n";
                for (int i=1; i<=e-2; i++)
                    cout << 'T';
                    cout << 'L';
                for (int i=e+1; i<=dem+1; i++)
                    cout << 'T';
            }
            cout <<"\n";
        }
    }
}
