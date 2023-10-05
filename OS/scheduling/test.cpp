#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>>ac;
    
    ac.push_back({5, 1});
    ac.push_back({10, 5});
    ac.push_back({4, 7});
    ac.push_back({20, 2});

    sort(ac.begin(), ac.end());

    for(auto i : ac){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}