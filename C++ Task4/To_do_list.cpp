#include<iostream>
#include<string>
using namespace std;
const int max_tasks=100;
struct Task{
    string description;
    bool isDone;
};

int main(){
    Task tasks[max_tasks];
    int numTasks=0;
    while (true)
    {
        cout<<"To-Do List Application"<<endl;
        cout<<"1.Add Task  "<<endl;
        cout<<"2.View Tasks  "<<endl;
        cout<<"3.Mark Task as completed  "<<endl;
        cout<<"4.Remove Task   "<<endl;
        cout<<"5.Quit  "<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            if(numTasks < max_tasks){
                cout<<"Enter Task Description : ";
                cin.ignore();
                getline(cin,tasks[numTasks].description);
                tasks[numTasks].isDone=false;
                numTasks++;
                cout<<"Task Added."<<endl;
            }
            else{
                cout<<"Task List is Full.Cannot add more tasks."<<endl;
            }
        }
        else if(choice==2){
            cout<<"Tasks : "<<endl;
            for(int i=0;i<numTasks;i++){
                cout<<(i+1)<<". ";
                cout<<tasks[i].description;
                if(tasks[i].isDone){
                    cout<<"   [Completed]"<<endl;
                }
                else{
                    cout<<"   [Pending]"<<endl;
                }
            }
        }
        else if(choice==3){
            cout<<"Enter the task number to be marked as done : ";
            int task_number;
            cin>>task_number;
            if(task_number>0 && task_number<=numTasks){
                tasks[task_number-1].isDone=true;
                cout<<"Task number "<<task_number<<" is marked as done"<<endl;
            }
            else{
                cout<<"Invalid task number."<<endl;

            }
        }
        else if(choice==4){
            cout<<"Enter the task number to be marked as done : ";
            int task_number;
            cin>>task_number;
            if(task_number>0 && task_number<=numTasks){
                for(int i=task_number-1;i<numTasks;i++){
                    tasks[i]=tasks[i+1];
                }
                cout<<"Task number "<<task_number<<" is removed from the list."<<endl;
                numTasks--;
            }
            else{
                cout<<"Invalid task number."<<endl;

            }
        }
        else if(choice==5){
            cout<<"Thank you..."<<endl;
            break;
        }
        else{
            cout<<"Invalid choice select from choice (1-4)."<<endl;
        }
    }
    return 0;
}