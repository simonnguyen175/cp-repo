#include<bits/stdc++.h>


using namespace  std;
const int N = 1001;
const int S = 100;
int n, s, x, e;
vector<int>  adj[N];
int d[S][N], q[S][N];
// d[k][u] la so dinh toi da  nhan duoc khi bam k lan, dinh bat dau la u --> u[1], u[2], .. , u[e[u]]
// q[k][t] la so dinh toi do khi bam k lan tap bat dau la u[1], u[2], .., u[t]
int main(){
 
  freopen("TranSet.Inp","r",stdin);
  freopen("TranSet.Out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i = 1; i <= n; ++i)
  {
      cin >> e;
      for(int t = 0; t < e; ++t){
        cin >> x;
        adj[i].push_back(x);
      }
  }
  cin >> s;
  for(int u = 1; u <= n; u++) d[0][u] = 1;
  for(int numStep = 1; numStep <= s; ++numStep )  //s
    for(int vertex = 1; vertex <= n; ++vertex){   //n
         //d[numStep][vertex] = ??? = q[numStep - 1][e_x - 1]
         int e_x = adj[vertex].size();
         for(int t = 0; t < e_x; ++t)
             q[0][t] = t + 1;
         for(int Step = 1; Step < numStep; ++Step){ //s
             q[Step][0] = d[Step][adj[vertex][0]];
             for(int t = 1; t < e_x; ++t)            //m
             {
                 q[Step][t] = 0;
                 for(int k = 0; k <= Step; k++)      //s
                   q[Step][t] = max(q[Step][t], q[k][t-1] + d[Step - k][adj[vertex][t]]);
             }
        }
         d[numStep][vertex] = q[numStep - 1][e_x - 1];
  }
  int res = 0;
  for(int vertex = 1; vertex <= n; ++vertex)
     res = max(res, d[s][vertex]);
  cout<<res;

}
