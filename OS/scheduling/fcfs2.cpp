
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


bool compareByArrivalTime(const Process &a, const Process &b)
{
    return a.arrival_time < b.arrival_time;
}

bool compareById(const Process &a, const Process &b)
{
    return a.id < b.id;
}

void calculateCompletionTime(vector<Process> &processes)
{

    int n = processes.size();

    processes[0].completion_time = processes[0].burst_time;

    for (int i = 1; i < n; ++i)
    {
        if (processes[i].arrival_time >= processes[i - 1].completion_time)
        {
            processes[i].completion_time = processes[i].arrival_time + processes[i].burst_time;
        }

        else
        {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        }
    }
}

void calculateTurnAroundTime(vector<Process> &processes)
{

    int n = processes.size();

    for (int i = 0; i < n; ++i)
    {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}


void calculateWaitingTime(vector<Process> & processes){

    int n = processes.size();

    for (int i = 0; i < n; ++i)
    {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
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

    sort(processes.begin(), processes.end(), compareByArrivalTime);


    calculateCompletionTime(processes);
    calculateTurnAroundTime(processes);
    calculateWaitingTime(processes);


    sort(processes.begin(), processes.end(), compareById);

    for (int i = 0; i < processes.size(); ++i)
    {
        // cout<<processes[i].id<<endl;
        cout<<"____________________________________________________________"<<endl;
        cout << "completion-time : " << processes[i].completion_time << " turn-arond-time :" << processes[i].turnaround_time << " waiting-time :" << processes[i].waiting_time<<endl;
        cout<<"_____________________________________________________________"<<endl;
       
    }

    return 0;
}
