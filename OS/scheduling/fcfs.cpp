#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = current_time - processes[i].arrival_time;
    }
}

int main() {
    vector<Process> processes = {
        {1, 0, 6, 0, 0},
        {2, 2, 4, 0, 0},
        {3, 4, 2, 0, 0},
        {4, 6, 3, 0, 0},
    };
    
    fcfs(processes);
    
    double avg_waiting_time = 0;
    double avg_turnaround_time = 0;
    
    for (int i = 0; i < processes.size(); i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
        cout << "Process " << processes[i].id << ": "
             << "waiting time = " << processes[i].waiting_time << ", "
             << "turnaround time = " << processes[i].turnaround_time << endl;
    }
    
    avg_waiting_time /= processes.size();
    avg_turnaround_time /= processes.size();
    
    cout << "Average waiting time = " << avg_waiting_time << endl;
    cout << "Average turnaround time = " << avg_turnaround_time << endl;
    
    return 0;
}
