#include <iostream>
using namespace std;
const int MAX_TASKS = 100;
const int MAX_DESCRIPTION_LENGTH = 100;
class Task {
public:
    Task() 
	{
        description[0] = '\0';
        completed = false;  }
    void setDescription(const char desc[]) {
        int i = 0;
        while (i < MAX_DESCRIPTION_LENGTH - 1 && desc[i] != '\0') {
            description[i] = desc[i];
            ++i;}
        description[i] = '\0'; 
    }
    const char* getDescription() const {
        return description;
    }
    bool isCompleted() const {
        return completed;
    }
    void markCompleted() {
        completed = true;
    }
private:
    char description[MAX_DESCRIPTION_LENGTH];
    bool completed;
};
void addTask(Task tasks[], int &taskCount) {
    if (taskCount >= MAX_TASKS) {
    cout << "Task list is full! Cannot add more tasks.\n";
    return;
    }
    cout << "Enter the task description: ";
    char description[MAX_DESCRIPTION_LENGTH];
    cin.ignore(); 
    cin.getline(description, MAX_DESCRIPTION_LENGTH);
    tasks[taskCount].setDescription(description);
    taskCount++;
    cout << "Task added successfully.\n";
}
void viewTasks(const Task tasks[], int taskCount) {
    cout << "\nTasks:\n";
    for (int i = 0; i < taskCount; ++i) {
	cout << i + 1 << ". " << tasks[i].getDescription()
	<< (tasks[i].isCompleted() ? " [Completed]" : " [Pending]") << "\n";
    }
}

void markTaskCompleted(Task tasks[], int taskCount) {
    viewTasks(tasks, taskCount);
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].markCompleted();
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(Task tasks[], int &taskCount) {
    viewTasks(tasks, taskCount);
    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}
int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);
    return 0;
}
