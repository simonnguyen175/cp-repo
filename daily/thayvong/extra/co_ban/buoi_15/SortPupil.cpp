#include <bits/stdc++.h>
using namespace std;

struct hocsinh{
    int Toan;
    int Tin;
    int Anh;
};

bool compair (hocsinh a, hocsinh b){
    int x= a.Toan + a.Tin + a.Anh;
    int y= b.Toan + b.Tin + b.Anh;
    if ( x == y ){
        if ( a.Toan > b.Toan ) return true;
        else{
            if ( a.Toan == b.Toan ){
                if ( a.Tin <= b.Tin ) return false;
                else return true;
            }
            else return false;
        }
    }
    else{
        if ( x < y ) return false;
        else return true;
    }
}

hocsinh ds[100001];
int n, x;

int main(){
    freopen("SortPupil.inp","r",stdin);
    freopen("SortPupil.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> ds[i].Toan >> ds[i].Tin >> ds[i].Anh;
    sort ( ds+1, ds+1+n, compair);
    for (int i=1; i<=n; i++){
        x = ds[i].Toan + ds[i].Tin + ds[i].Anh;
        cout << ds[i].Toan <<" "<<ds[i].Tin <<" "<<ds[i].Anh <<" "<<x<<"\n";
    }
    return 0;
}
