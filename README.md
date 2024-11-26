# Process Scheduling Simulation in C++
This project is a simulation of various process scheduling algorithms implemented in C++. It provides a hands-on demonstration of how operating systems schedule processes using algorithms such as First Come First Serve (FCFS), Priority Scheduling, and Shortest Job First (SJF). The simulation allows users to interactively manage processes, simulate their execution, and view their state transitions in real-time.

****Features****


**Process Control Block (PCB)**
Each process is represented by a Process Control Block (PCB), which stores information like the Process ID, Process Name, Program Counter, Priority, and Process State.
Scheduling Algorithms:

**First Come First Serve (FCFS)**
Processes are scheduled in the order they are created.
Priority Scheduling: Processes are scheduled based on their priority values.

**Shortest Job First (SJF)**
Processes with the shortest execution time (Program Counter) are scheduled first.

**Priority Algorithm**
The project supports the dynamic creation of processes with unique Process IDs and Priorities.
The system checks for duplicate Process IDs and Priorities to prevent errors.

**Process State Transitions**
The simulation updates and displays the state of each process, including states like:
Running
Ready
Waiting

**Interrupt Handling**
A simulated interrupt allows you to add new processes to the queue mid-execution, mimicking real-time scheduling behaviors.



****Getting Started****


**Prerequisites**
To run this project on your local machine, ensure you have the following installed:

C++ compiler (GCC, MinGW, or any compatible compiler)
C++ IDE or text editor (e.g., Visual Studio Code, CLion, etc.)

**How to Run**
Once the you clone the repo and program runs, you'll be prompted with a menu to choose one of the following scheduling algorithms:

First Come First Serve (FCFS): Processes are scheduled in the order of their arrival.
Priority Scheduling: Processes are scheduled according to their assigned priority.
Shortest Job First (SJF): Processes are scheduled by their program count (execution time).
You can enter the details for each process (name, ID, program counter, and priority) interactively. After adding processes, you can choose to simulate their execution and view their transitions through different states such as Running, Ready, and Waiting.

**Example Output**
The program will display process information in a table format:

markdown
Copy code
--------------------------------------------------------------------------------------
| Process            | Process ID  | Program Counter | Priority      | Process State  |
--------------------------------------------------------------------------------------
| Process1           | 101         | 5               | 1.2           | Running State  |
--------------------------------------------------------------------------------------
| Process2           | 102         | 3               | 2.0           | Ready State    |
--------------------------------------------------------------------------------------
| Process3           | 103         | 7               | 0.8           | Waiting State  |
--------------------------------------------------------------------------------------
**Key Concepts**
Process Control Block (PCB): A data structure that stores all the information about a process, such as its ID, name, priority, and current state.

Scheduling Algorithms: These algorithms determine the order in which processes are executed by the CPU. They are crucial for efficient system resource management.

State Transitions: Processes change states as they move through their lifecycle, including when they are waiting for resources, running, or ready to execute.

**Code Structure**
PCB Class: Contains data members to store process information and methods to interact with processes.
Scheduling Functions: Includes the algorithms to schedule processes based on FCFS, Priority, and SJF.
Display Functions: For printing process details and their state transitions.
Main Function: Handles user input, process creation, and algorithm selection.
Contributing

**Report Bugs**
If you find any issues, please open an issue on the GitHub repository.
Submit Feature Requests: If you'd like to suggest new features, feel free to create an issue or a pull request.
Fork and Improve: Fork the repository, make your improvements, and submit a pull request.


**Acknowledgements**
C++ Standard Library: For providing useful features like vectors, strings, and input/output.
Open-source Community: For providing inspiration and guidance in implementing process scheduling algorithms.
Contact
If you have any questions or suggestions, feel free to reach out!

GitHub: AliHaider332
Email: [bhaialihaider332@gmail.com]


Thanks You!

