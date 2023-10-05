#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
    int pid; // Process ID
    int at; // Arrival time
    int tat; // Turn around time
    int bt; // Burst time
    int wt; // Waiting time
    int rt; // Remaining time
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Process const& p1, Process const& p2) {
        return p1.rt > p2.rt;
    }
};

void roundRobin(Process processes[], int n, int quantum) {
    // Create a priority queue of processes to be executed
    priority_queue<Process, vector<Process>, Compare> pq;

    // Calculate the total burst time and remaining time for each process
    int total_bt = 0;
    for (int i = 0; i < n; i++) {
        processes[i].rt = processes[i].bt;
        total_bt += processes[i].bt;
        pq.push(processes[i]);
    }

    int current_time = 0;
    while (!pq.empty() && current_time < total_bt) {
        // Get the process at the front of the queue
        Process current_process = pq.top();
        pq.pop();

        // Execute the process for the given time quantum
        int executed_time = min(current_process.rt, quantum);
        current_time += executed_time;
        current_process.rt -= executed_time;

        // Update the waiting time and turnaround time for all the processes
        for (int i = 0; i < n; i++) {
            if (processes[i].pid != current_process.pid && processes[i].at <= current_time && processes[i].rt > 0) {
                processes[i].wt += executed_time;
            }
        }

        // If the current process still has remaining time, add it back to the queue
        if (current_process.rt > 0) {
            pq.push(current_process);
        }
    }

    // Calculate the waiting time and turnaround time for each process
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].bt + processes[i].wt;
        total_wt += processes[i].wt;
        total_tat += processes[i].tat;
    }

    // Print the average waiting time and average turnaround time
    cout << "Average Waiting Time = " << (float)total_wt / (float)n << endl;
    cout << "Average Turnaround Time = " << (float)total_tat / (float)n << endl;
}

int main() {
    // Example usage
    int n = 6;
    Process processes[n] = {
        {1, 0, 7, 7},
        {2, 1, 4, 4},
        {3, 2, 15, 15},
        {4, 3, 11, 11},
        {5, 4, 20, 20},
        {6, 4, 9, 9},
    };
    int quantum = 2;
    roundRobin(processes, n, quantum);

    return 0;
}