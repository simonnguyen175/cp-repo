#include<bits/stdc++.h>
using namespace std;

int n;
char s[21];

void xuli(){
    for (int i = 1; i <= n;i ++) cout<<s[i];
    cout<<endl;
}

void gen(int id){
	for (char i='A';i<='B';i++){
		if ( id > 1 && s[id-1] == (char)i && i=='B'){
			continue;
        }
        s[id] = (char)i;
		if ( id == n ){
            xuli();
		}
		else gen(id+1);
	}
}

int main(){
	cin >> n;
	gen(1);
}
