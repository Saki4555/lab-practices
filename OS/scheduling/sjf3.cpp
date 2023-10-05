#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid; // Process ID
    int at; // Arrival time
    int bt; // Burst time
    int ct; // Completion time
    int tat; // Turnaround time
    int wt; // Waiting time
};

// Comparison function for sorting processes based on burst time
bool compare(Process p1, Process p2) {
    return p1.bt < p2.bt;
}

void sjf(Process processes[], int n) {
    // Sort the processes based on burst time
    sort(processes, processes + n, compare);

    // Calculate the completion time, turnaround time, and waiting time for each process
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        current_time += processes[i].bt;
        processes[i].ct = current_time;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }

    // Print the completion time, turnaround time, and waiting time for each process
    cout << "P\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].at << "\t" << processes[i].bt << "\t"
            << processes[i].ct << "\t" << processes[i].tat << "\t" << processes[i].wt << endl;
    }

    // Calculate the average turnaround time and average waiting time for all processes
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += processes[i].tat;
        avg_wt += processes[i].wt;
    }
    avg_tat /= n;
    avg_wt /= n;

    // Print the average turnaround time and average waiting time
    cout << "Average Turnaround Time = " << avg_tat << endl;
    cout << "Average Waiting Time = " << avg_wt << endl;
}

int main() {
    // Example usage
    int n = 3;
    Process processes[n] = {
        {1, 1, 4},
        {2, 5, 8},
        {3, 6, 10},
       
    };
    sjf(processes, n);

    return 0;
}