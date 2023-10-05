#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int, int>>a;
    for(int i=0; i<n; ++i){
        int x,y;
        cin>>x>>y;
        a.push_back({y,x});
    }
    sort(a.begin(), a.end());

   int i=0;
   cout<<"("<<a[i].second<<" "<<a[i].first<<")"<<endl;
   for(int j=1; j<n; ++j){
    if(a[j].second >= a[i].first){
         cout<<"("<<a[j].second<<" "<<a[j].first<<")"<<endl;
          i=j;
    }
   }

    return 0;

}