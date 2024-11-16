#include<iostream>
using namespace std;

int main(){
    string n;
    cin >> n;

    for (int i = 0; i < n.size(); i ++)
    for (int j = 1; j < n.size(); j ++){
        if ( n[j] < n[j-1] )
            swap(n[j], n[j-1]);
    }

    cout << n;

    return 0;
}
