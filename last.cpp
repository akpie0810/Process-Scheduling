#include<iostream>
#include<vector>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

// Round Robin Scheduling
void roundRobin(Process proc[], int n, int quantum) {
    vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) {
        remainingTime[i] = proc[i].burst_time;
    }
    int currentTime = 0, completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    proc[i].completion_time = currentTime;
                    remainingTime[i] = 0;
                    completed++;
                }
            }
        }
    }
}

// FCFS Scheduling
void fcfs(Process proc[], int n) {
    proc[0].completion_time = proc[0].burst_time;
    for (int i = 1; i < n; i++) {
        proc[i].completion_time = proc[i - 1].completion_time + proc[i].burst_time;
    }
}

// SJF Scheduling
void sjf(Process proc[], int n) {
    vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) {
        remainingTime[i] = proc[i].burst_time;
    }
    int currentTime = 0, completed = 0;
    while (completed < n) {
        int shortest = -1, minBurst = 9999;
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= currentTime && remainingTime[i] < minBurst && remainingTime[i] > 0) {
                minBurst = remainingTime[i];
                shortest = i;
            }
        }
        if (shortest == -1) {
            currentTime++;
            continue;
        }
        remainingTime[shortest]--;
        if (remainingTime[shortest] == 0) {
            completed++;
            proc[shortest].completion_time = currentTime + 1;
        }
        currentTime++;
    }
}

// Calculate Turnaround and Waiting Time
void calculateTimes(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
    }
}

// Display Table
void display(Process proc[], int n, string algo) {
    cout << "\n" << algo << " Scheduling Results:\n";
    cout << "----------------------------------------------------------\n";
    cout << "PID | Arrival | Burst | Completion | Turnaround | Waiting\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "   |    " << proc[i].arrival_time << "   |   " << proc[i].burst_time
             << "   |      " << proc[i].completion_time << "      |     "
             << proc[i].turn_around_time << "     |   " << proc[i].waiting_time << "\n";
    }
    cout << "----------------------------------------------------------\n";
}

int main() {
    int n, choice, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process proc[n];
    cout << "Enter Process Details (ID, Arrival Time, Burst Time):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " : ";
        cin >> proc[i].pid >> proc[i].arrival_time >> proc[i].burst_time;
    }

    cout << "\nSelect Scheduling Algorithm:\n";
    cout << "1. Round Robin\n2. FCFS\n3. SJF\nChoice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter Time Quantum: ";
            cin >> quantum;
            roundRobin(proc, n, quantum);
            break;
        case 2:
            fcfs(proc, n);
            break;
        case 3:
            sjf(proc, n);
            break;
        default:
            cout << "Invalid Choice!\n";
            return 0;
    }
    calculateTimes(proc, n);
    display(proc, n, (choice == 1 ? "Round Robin" : choice == 2 ? "FCFS" : "SJF"));
    return 0;
}
