#include <iostream>  
#include <vector>   
#include <string>   
#include <algorithm> 


class TaskManager {
private:
    
    std::vector<std::string> activeTasks;
    std::vector<std::string> deletedTasks;

public:
    
    void addTask(const std::string& task) {
        activeTasks.push_back(task); 
    }

    
    void deleteTask(const std::string& task) {
        
        auto it = std::find(activeTasks.begin(), activeTasks.end(), task);
        if (it != activeTasks.end()) { 
            deletedTasks.push_back(task); 
            activeTasks.erase(it); 
            std::cout << "Task '" << task << "' deleted.\n";
        } else {
            std::cout << "Task '" << task << "' not found.\n"; 
        }
    }

    
    void showDeletedTasks() const {
        if (deletedTasks.empty()) { 
            std::cout << "No deleted tasks.\n";
            return;
        }

        std::cout << "Deleted Tasks:\n";
        for (size_t i = 0; i < deletedTasks.size(); ++i) { 
            std::cout << (i + 1) << ": " << deletedTasks[i] << '\n'; 
        }
    }

   
    void undoDelete(int index) {
       
        if (index < 1 || index > static_cast<int>(deletedTasks.size())) {
            std::cout << "Invalid index for undo.\n";
            return;
        }

        std::string task = deletedTasks[index - 1]; 
        activeTasks.push_back(task); 
        deletedTasks.erase(deletedTasks.begin() + (index - 1)); 
        std::cout << "Task '" << task << "' restored.\n";
    }
};


int main() {
    TaskManager taskManager; 
    
    
    taskManager.addTask("Task 1");
    taskManager.addTask("Task 2");
    taskManager.addTask("Task 3");

    
    taskManager.deleteTask("Task 2");

    
    taskManager.showDeletedTasks();

   
    int index;
    std::cout << "Enter the index of the task to undo: ";
    std::cin >> index; 
    taskManager.undoDelete(index); 

    return 0; 
    }
#include <iostream>  
#include <vector>   
#include <string>   
#include <algorithm> 


class TaskManager {
private:
    
    std::vector<std::string> activeTasks;
    std::vector<std::string> deletedTasks;

public:
    
    void addTask(const std::string& task) {
        activeTasks.push_back(task); 
    }

    
    void deleteTask(const std::string& task) {
        
        auto it = std::find(activeTasks.begin(), activeTasks.end(), task);
        if (it != activeTasks.end()) { 
            deletedTasks.push_back(task); 
            activeTasks.erase(it); 
            std::cout << "Task '" << task << "' deleted.\n";
        } else {
            std::cout << "Task '" << task << "' not found.\n"; 
        }
    }

    
    void showDeletedTasks() const {
        if (deletedTasks.empty()) { 
            std::cout << "No deleted tasks.\n";
            return;
        }

        std::cout << "Deleted Tasks:\n";
        for (size_t i = 0; i < deletedTasks.size(); ++i) { 
            std::cout << (i + 1) << ": " << deletedTasks[i] << '\n'; 
        }
    }

   
    void undoDelete(int index) {
       
        if (index < 1 || index > static_cast<int>(deletedTasks.size())) {
            std::cout << "Invalid index for undo.\n";
            return;
        }

        std::string task = deletedTasks[index - 1]; 
        activeTasks.push_back(task); 
        deletedTasks.erase(deletedTasks.begin() + (index - 1)); 
        std::cout << "Task '" << task << "' restored.\n";
    }
};


int main() {
    TaskManager taskManager; 
    
    
    taskManager.addTask("Task 1");
    taskManager.addTask("Task 2");
    taskManager.addTask("Task 3");

    
    taskManager.deleteTask("Task 2");

    
    taskManager.showDeletedTasks();

   
    int index;
    std::cout << "Enter the index of the task to undo: ";
    std::cin >> index; 
    taskManager.undoDelete(index); 

    return 0; 
    }
