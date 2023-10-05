#include<bits/stdc++.h>
using namespace std;

const int N=1e5+3;
const int INF=1e9;
 vector<pair<int,int>>g[N];
 vector<int>dist(N),parent(N);
 vector<bool>vis(N);
 int sum=0;
 int n,m;
 void prims(int source){
   // for(int i=1;i<n;i++){
      //  dist[i]=INF;
  //  }
   vector<int>dist(N,INF);
     set<pair<int,int>>st;
     //(wt,vertex)
     st.insert({0,source});
     dist[source]=0;
     while(!st.empty()){
         auto x=*st.begin();
         st.erase(x);
         vis[x.second]=true;
         int v=x.second;
         int u=parent[x.second];
         int w=x.first;
         cout<<v<<" "<<u<<" "<<w<<endl;
           sum+=w;
         for(auto child:g[v]){
            int child_v=child.first;
            int w =child.second;
            if(vis[child_v])continue;

            if(w<dist[child_v]){
                st.erase({dist[child_v],child_v});
                dist[child_v]=w;
                st.insert({dist[child_v],child_v});
                parent[child_v]=v;
            }
         }
     }

 }
int main(){

     cin>>n>>m;
     for(int i=0;i<m;i++){
         int u,v,w;
         cin>>u>>v>>w;
         g[u].push_back({v,w});
          g[v].push_back({u,w});
     }
     prims(0);
     cout<<sum;


}
