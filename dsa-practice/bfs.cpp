#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;

vector<int> g[N];
bool vis[N];
//int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop();
        cout<< curr_v<<" ";
        for(int child : g[curr_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                //level[child] = level[curr_v]+1;
            }
        }
    }
    cout<<endl;
    
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; ++i){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    return 0;
}