#include<bits/stdc++.h>
using namespace std;

struct Process
{
   int id, at, bt, tat, wt, ct;
};

bool compareByAt(const Process &a, const Process &b){
        return a.at < b.at;
}

bool compareById(const Process &a, const Process &b){
        return a.id < b.id;
}

void completionTime (vector<Process> &processes){
    int n = processes.size();

    processes[0].ct = processes[0].at + processes[0].bt;

    for(int i=1; i<n; ++i){
        if(processes[i].at >= processes[i-1].ct){
            processes[i].ct = processes[i].at + processes[i].bt;
        }

        else{
            processes[i].ct = processes[i-1].ct + processes[i].bt;
        }
    }
}

void turnAroundTime(vector<Process> &processes){
    int n = processes.size();

    for(int i=0; i<n; ++i){
        processes[i].tat = processes[i].ct - processes[i].at;
    }
}
void waitingTime(vector<Process> &processes){
    int n = processes.size();

    for(int i=0; i<n; ++i){
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}

int main(){

    vector<Process> processes = {
        {1, 3, 4, 0, 0, 0},
        {2, 5, 3, 0, 0, 0},
        {3, 0, 2, 0, 0, 0},
        {4, 5, 1, 0, 0, 0},
        {5, 4, 3, 0, 0, 0},
    };

    sort(processes.begin(), processes.end(), compareByAt);

    completionTime(processes);
    turnAroundTime(processes);
    waitingTime(processes);

    sort(processes.begin(), processes.end(), compareById);


    for(int i=0; i<processes.size(); ++i){
        cout<<"P"<<processes[i].id << " | tat : " << processes[i].tat << " | wt : "<<processes[i].wt<<endl;
    }


    return 0;
}