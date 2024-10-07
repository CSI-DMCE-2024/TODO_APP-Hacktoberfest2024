#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string title;
    std::string description;

    Task(const std::string& t, const std::string& d) : title(t), description(d) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& title, const std::string& description) {
        tasks.emplace_back(title, description);
        std::cout << "Task added: " << title << "\n";
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        for (const auto& task : tasks) {
            std::cout << "Title: " << task.title << "\n";
            std::cout << "Description: " << task.description << "\n";
            std::cout << "\n";
        }
    }
};

int main() {
    TaskManager taskManager;
    int option;
    
    do {
        std::cout << "Task Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;
        std::cin.ignore(); // Clear the newline from the input buffer

        if (option == 1) {
            std::string title, description;

            std::cout << "Enter task title: ";
            std::getline(std::cin, title);
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);

            taskManager.addTask(title, description);
        } else if (option == 2) {
            taskManager.displayTasks();
        }

    } while (option != 3);

    return 0;
}
