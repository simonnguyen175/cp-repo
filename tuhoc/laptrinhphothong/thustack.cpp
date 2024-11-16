#include <bits/stdc++.h>
using namespace std; 

int main(){
	stack<int> a; 
	for (int i=1; i<=5; i++)
		a.push(i); 
	if (a.full()) cout<<"DM"; 
	while ( !a.empty()){
		cout << a.top() <<"  "; 
		a.pop();
	}
	return 0; 	
}
