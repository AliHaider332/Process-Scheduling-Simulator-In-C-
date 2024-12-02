#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

class PCB
{
protected:
    string Process;
    int Process_ID;
public:
    int Program_Count;
    float Priority;
    string Process_State;
    PCB* next;
    static vector<int> Check_Process_ID;
    static vector<float> Check_Process_Priority;
    static int check;
    PCB()
    {

        cout << "\n\tEnter the Process name: ";
        getline(cin, Process);
        cout << "\tEnter the Process_ID: ";
        cin >> Process_ID;


        while (true)
        {
            bool isDuplicate = false;
            for (int i = 0; i < Check_Process_ID.size(); i++)
            {
                if (Process_ID == Check_Process_ID[i])
                {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate)
            {
                cout << "\tSorry, this Process ID is already used. Please enter a unique Process ID: ";
                cin >> Process_ID;
            }
            else
            {
                Check_Process_ID.push_back(Process_ID);
                break;
            }
        }

        cout << "\tEnter the Program counter: ";
        cin >> Program_Count;

        cout << "\tEnter the Priority of the Process: ";
        cin >> Priority;
        while (true)
        {
            bool isDuplicate = false;
            for (int i = 0; i < Check_Process_Priority.size(); i++)
            {
                if (Priority == Check_Process_Priority[i])
                {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate)
            {
                cout << "\tSorry, this priority already exists. Please enter a different priority: ";
                cin >> Priority;
            }
            else
            {
                Check_Process_Priority.push_back(Priority);
                break;
            }
        }

        Process_State = "New State";
        next = nullptr;

        cin.ignore();  // Ignores the leftover newline from the previous input
    }


    void display()
    {
        if (check == 0)
        {
            cout << "\n\t--------------------------------------------------------------------------------------\n";
            cout << "\t| " << left << setw(20) << "Process"
                 << "\t| " << setw(10) << "Process ID"
                 << "\t| " << setw(15) << "Program Counter"
                 << "\t| " << setw(15) << "Priority"
                 << "\t| " << setw(15) << "Process State" << "|\n";
            check++;
        }
        cout << "\t--------------------------------------------------------------------------------------\n";

        cout << "\t| " << left << setw(20) << Process
             << "\t| " << setw(10) << Process_ID
             << "\t| " << setw(15) << Program_Count
             << "\t| " << setw(15) << Priority
             << "\t| " << setw(15) << Process_State << "|\n";

        cout << "\t--------------------------------------------------------------------------------------\n";
    }
};

vector<int> PCB::Check_Process_ID;
vector<float> PCB::Check_Process_Priority;
int PCB::check = 0;
// Create the First Come First Serve algorithm
void FCFS(PCB*& First)
{
    PCB* temp = new PCB();

    if (First == nullptr)
    {
        First = temp;
    }
    else
    {
        PCB* current = First;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
    }
}






//Create the Short Job First Algorithm
void Short_Job_First(PCB*& First)
{
    PCB* temp = new PCB();

    if (First == nullptr || temp->Program_Count < First->Program_Count)
    {

        temp->next = First;
        First = temp;
    }
    else
    {
        PCB* Pre = nullptr;
        PCB* Post = First;
        while (Post != nullptr && temp->Program_Count  >=  Post->Program_Count)
        {
            Pre = Post;
            Post = Post->next;
        }
        Pre->next = temp;
        temp->next = Post;
    }
}









// Create  The Priority Algorithm
void PRIORITY(PCB*& First)
{
    PCB* temp = new PCB();

    if (First == nullptr || temp->Priority > First->Priority)
    {
        temp->next = First;
        First = temp;
    }
    else
    {
        PCB* Pre = nullptr;
        PCB* Post = First;
        while (Post != nullptr && temp->Priority < Post->Priority)
        {
            Pre = Post;
            Post = Post->next;
        }
        Pre->next = temp;
        temp->next = Post;
    }
}






// Create the Round Robin Algorithm
void ROUND_ROBIN(queue<PCB*>&HOLDING_QUEUE)
{
       PCB* temp = new PCB();
       HOLDING_QUEUE.push(temp);

}
void ROUND_ROBIN_IMPLIMENT(queue<PCB*>&HOLDING_QUEUE,int&quantum)
{
    if(HOLDING_QUEUE.empty())
    {
        cout<<"\n\tNo Process is Present in the RAM:"<<endl;
        return;
    }
    queue<PCB*>QUEUE;
    while(!HOLDING_QUEUE.empty())
    {
        PCB* temp=HOLDING_QUEUE.front();
        HOLDING_QUEUE.pop();
        temp->Program_Count-=quantum*10;
        QUEUE.push(temp);
    }
    while(!QUEUE.empty())
    {
        PCB* temp=QUEUE.front();
        QUEUE.pop();
        if(temp->Program_Count>0)
        {
            HOLDING_QUEUE.push(temp);
        }

    }
    queue<PCB*>queue1;
    if (!HOLDING_QUEUE.empty())
    {
        HOLDING_QUEUE.front()->Process_State = "Running State";
        HOLDING_QUEUE.front()->display();// Display the first process in the queue
        queue1.push(HOLDING_QUEUE.front());
        HOLDING_QUEUE.pop(); // Remove the front process from the queue
    }

    int x = 2;  // To manage the display of the process states
    while (!HOLDING_QUEUE.empty())
    {
        if (x)
        {
            HOLDING_QUEUE.front()->Process_State = "Ready State";
            x--; // First two processes are in "Ready State"
        }
        HOLDING_QUEUE.front()->display();
        queue1.push(HOLDING_QUEUE.front());
        HOLDING_QUEUE.pop();
    }
    while(!queue1.empty())
    {
        HOLDING_QUEUE.push(queue1.front());
        queue1.pop();
    }

}






void Display_All(PCB* First,bool x)
{
    PCB* temp = First;
    if(x==0)
    {
    int processCount = 0;
    while (temp != nullptr)
    {
        processCount++;
        if (processCount == 1)
        {
            temp->Process_State = "Running State";
        }

        else if(processCount<4)
        {
            temp->Process_State = "Ready State";
        }

        temp->display();
        temp = temp->next;
    }
    }
    else if(x==1)
    {
        while(temp != nullptr)
        {
            temp->display();
            temp=temp->next;
        }
    }
}
void Major_Display(PCB* FIRST)
{
    string command;
    cout << "\n\tIf you want to see the execution of the Processes, enter YES/NO: ";
    cout<<"\t";
    getline(cin, command);
    if (command == "YES" || command == "yes")
    {
        Display_All(FIRST,0);
    }
}






// Create the Special condition Function
void Special(PCB*&FIRST)
{
    if(FIRST==nullptr)
    {
        return;
    }
    else if(FIRST->next==nullptr)
    {
        FIRST->Process_State="Waiting State";
        FIRST->display();
        return;
    }
    else if(FIRST->next->next==nullptr)
    {
        FIRST->next->Process_State="Running State";
        FIRST->next->display();
        FIRST->Process_State="Waiting State";
        FIRST->display();
    }
    else
    {
        FIRST->next->Process_State="Running State";
        FIRST->next->display();
        FIRST->next->next->Process_State="Ready State";
        FIRST->next->next->display();
        FIRST->Process_State="Waiting State";
        FIRST->display();
        Display_All(FIRST->next->next->next,1);
    }
}
void Intrupt(PCB*&FIRST)
{
    cout<<"\tEnter the requird entries for the Process:"<<endl;
    PCB* intrupt=new PCB;
    PCB* temp=FIRST;
    intrupt->next=temp->next;
    temp->next=intrupt;
    cout<<"\n\n\n";
    Display_All(FIRST,0);
}













int main()
{
    cout << "\tIf you want to execute the processes in First Come First Serve Algorithm, then Enter 1:\n";
    cout << "\tIf you want to execute the processes in Priority Algorithm, then Enter 2:\n";
    cout << "\tIf you want to execute the processes in Short Job First Algorithm, then Enter 3:\n";
    cout << "\tIf you want to execute the processes in Round Robin Algorithm, then Enter 4:\n";
    int check;
    cout<<"\t";
    cin>>check;
    cin.ignore();
    PCB* aFIRST = nullptr;

    if (check == 1)
    {
        while (true)
        {
            string command;
            cout << "\n\n\tTo Enter the Process type yes/YES: ";
            getline(cin, command);
            cout<<"\t";
            if (command == "YES" || command == "yes")
            {
                FCFS(FIRST);
            }
            else
            {
                break;
            }
        }
    }
    else if (check == 2 )
    {
        while (true)
        {
            string command;
            cout << "\n\n\tTo Enter the Process type yes/YES: ";
            cout<<"\t";
            getline(cin, command);
            if (command == "YES" || command == "yes")
            {
                PRIORITY(FIRST);
            }
            else
            {
                break;
            }
        }
    }
    else if (check == 3 )
    {
        while (true)
        {
            string command;
            cout << "\n\n\tTo Enter the Process type yes/YES: ";
            cout<<"\t";
            getline(cin, command);
            if (command == "YES" || command == "yes")
            {
                Short_Job_First(FIRST);
            }
            else
            {
                break;
            }
        }
    }
    else if (check == 4)
    {
        // Get quantum time for Round Robin
        queue<PCB*>HOLDING_QUEUE;
        int quantum;
        cout << "\n\tEnter the time quantum for Round Robin scheduling: ";
        cin >> quantum;
        cin.ignore();

        while (true)
        {
            string command;
            cout << "\n\n\tTo Enter the Process type yes/YES: ";
            getline(cin, command);
            if (command == "YES" || command == "yes")
            {
                ROUND_ROBIN(HOLDING_QUEUE);  // Simply add the all process
            }
            else
            {
                break;
            }
        }

        // Now perform Round Robin scheduling
        bool flag=true;
        string chack_point;
        while(flag)
        {
                ROUND_ROBIN_IMPLIMENT(HOLDING_QUEUE, quantum);
                cout<<"\tFor again output enter YES/yes:"<<endl;
                cout<<"\t";
                getline(cin, chack_point);
                if( chack_point=="YES" ||  chack_point=="yes")
                {
                    flag=true;
                }
                else
                {
                    flag=false;
                }
        }
        return 0;

    }

    Major_Display(FIRST);
    cout<<"\tFor more operation enter YES/yes:"<<endl;
    string check_input;
    cout<<"\t";
    getline(cin,check_input);
    if(check_input=="YES" || check_input=="yes")
    {
        int x;
        cout<<"\tIf the first process is gone for i/o enter 1:"<<endl;
        cout<<"\tIf you want to create the intrupt enter 2:"<<endl;
        cout<<"\t";
        cin>>x;
        cin.ignore();
        if(x==1)
        {
            Special(FIRST);
        }
        else
        {
            Intrupt(FIRST);
        }
    }
    return 0;
}
