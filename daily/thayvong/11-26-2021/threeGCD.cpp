#include<bits/stdc++.h>
using namespace std;

int X, Y;

int main(){
  if ( fopen("threeGCD.inp", "r") ){
    freopen("threeGCD.inp", "r", stdin);
    freopen("threeGCD.out", "w", stdout);
  }
  cin >> X >> Y;
  for (int d = Y; d >= 1; d --){
    int k = Y / d;
    if ( d * k >= X && d * (k-1) >= X && d * (k-2) >= X ){
      cout << d;
      return 0;
    }
  }
}
