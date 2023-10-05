#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

int findMin(vector<Process> &processes)
{
    int minArrival = 1e9;

    for (int i = 0; i < processes.size(); ++i)
    {
        if (minArrival < processes[i].arrival_time)
        {
            minArrival = processes[i].arrival_time;
        }
    }

    return minArrival;
}

void completionTime(vector<Process> &processes)
{

    cout<<"hello"<<endl;
    int n = processes.size();
    vector<int> ready_queue;
    vector<pair<int, int>>remainning_processes;
    vector<int> vis(n+1, 0);


    int clock = 0;
    
    int minArrival = findMin(processes);

    for(int i=0; i<n; ++i){
        if(processes[i].arrival_time = minArrival){
            ready_queue.push_back(processes[i].id);
            clock += processes[i].burst_time;
            vis[processes[i].id] = 1;
            break;
        }
    }

    cout<<ready_queue.size()<<endl;

    while (true)
    {

        for(int i=0; i<n; ++i){
            if(processes[i].arrival_time <= clock){
                if(vis[processes[i].id] == 0){
                    remainning_processes.push_back({processes[i].burst_time, processes[i].id});
                    vis[processes[i].id] = 1;
                }
            }
        }

        sort(remainning_processes.begin(), remainning_processes.end());

        for(int i=0; i<remainning_processes.size(); ++i){
            ready_queue.push_back(remainning_processes[i].second);
        }
        if(count(vis.begin(), vis.end(), 1) == 5){
            break;
        }
    }

    cout<<ready_queue.size()<<endl;

    cout<<"check"<<endl;
    for(auto i : ready_queue){
        cout<<i<<" ";
    }

    cout<<endl;
    



}

int main()
{
    vector<Process> processes = {
        {1, 3, 4, 0, 0, 0},
        {2, 5, 3, 0, 0, 0},
        {3, 0, 2, 0, 0, 0},
        {4, 5, 1, 0, 0, 0},
        {5, 4, 3, 0, 0, 0},
    };

    completionTime(processes);

    return 0;
}