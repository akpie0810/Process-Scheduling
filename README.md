# CPU Scheduling Algorithms

## Overview
This project implements three popular CPU scheduling algorithms:
1. **Round Robin (RR)**
2. **First Come First Serve (FCFS)**
3. **Shortest Job First (SJF)**

The program allows users to input process details (arrival time and burst time) and select a scheduling algorithm to compute process execution order, completion time, turnaround time, and waiting time.

## Features
- **Round Robin Scheduling** with user-defined time quantum.
- **First Come First Serve (FCFS)** scheduling.
- **Shortest Job First (SJF)** scheduling.
- **Formatted table output** for easy result analysis.
- **Turnaround Time & Waiting Time** calculation.

## How to Use
1. Compile the C++ program using:
   ```sh
   g++ scheduling.cpp -o scheduling
   ```
2. Run the executable:
   ```sh
   ./scheduling
   ```
3. Enter the number of processes.
4. Provide process details (Arrival Time & Burst Time).
5. Choose the scheduling algorithm:
   - `1` for Round Robin (Enter Time Quantum)
   - `2` for FCFS
   - `3` for SJF
6. View the formatted scheduling results.

## Example Input/Output
```
Enter The Number of Processes: 3
Enter The Process Details:
Process 1:
     Arrival Time:   0
     Burst Time:      5
Process 2:
     Arrival Time:   1
     Burst Time:      3
Process 3:
     Arrival Time:   2
     Burst Time:      8

Select Scheduling Algorithm:
1. Round Robin
2. First Come First Serve (FCFS)
3. Shortest Job First (SJF)
Enter choice: 1
Enter Time Quantum: 2

--------------------------------------------------------------------------------------------
|  Process   | Arrival Time | Burst Time | Completion Time |  TurnAround  |   Waiting Time  |
--------------------------------------------------------------------------------------------
|    1       |       0     |    5       |       10       |       10       |       5      |
|    2       |       1     |    3       |       6       |       5       |       2      |
|    3       |       2     |    8       |       16       |       14       |       6      |
-----------------------------------------------------------------------------------------------------------------
```

## Technologies Used
- **C++** for implementation
- **Standard I/O** for user interaction

## Future Enhancements
- Add **Priority Scheduling**
- Implement **Preemptive SJF**
- Provide a **graphical simulation**

## License
This project is open-source and free to use.

---
**Author:** Akanksha Pai

