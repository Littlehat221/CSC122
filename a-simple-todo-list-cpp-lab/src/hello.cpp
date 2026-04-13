#include "hello.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>

/*
bool isSameText(std::string first, std::string second);
bool TodoList::hasTag(Task subjectTask, std::string subjectTag) {
    for (int i = 0; i < subjectTask.tags.size();i++) {
        if (subjectTask.tags[i] == subjectTag) {
            return true;
        }
    }
    return false;
}
void prettyPrintTasks(std::vector<Task> subjectTasks, std::string title);
TodoList();
bool TodoList::add(std::string subjectDescription) {
    std::vector<std::string> noTags;
    return add()
}
*/
bool TodoList::add(std::string subjectDescription, std::vector<std::string> subjectTags) {
    if (subjectDescription == "") {
        std::cout << "Cannot add a blank task\n";
        return false;
    }
    for (int i = 0; i < tasks.size();i++) {
        if (!tasks[i].completionStatus && tasks[i].description == subjectDescription) {
            std::cout << "Cannot add a duplicate incomplete task for: " << tasks[i].description << '\n';
            return false;
        }
    }
    Task task;
    task.description = subjectDescription;
    task.completionStatus = false;
    task.tags = subjectTags;

    tasks.push_back(task);
    return true;
}
bool TodoList::add(std::string subjectDescription) {
    std::vector<std::string> noTags;
    return add(subjectDescription, noTags);
}
//marking
bool TodoList::complete(std::string subjectDescription) {
    if (subjectDescription == "") {
        std::cout << "Cannot complete a blank task.\n";
        return false;
    }
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].description == subjectDescription) {
            if (tasks[i].completionStatus) {
                std::cout << "Task already completed: " << subjectDescription << '\n';
                return false;
            }
            tasks[i].completionStatus = true;
            return true;
        }
    }
    std::cout << "Task not found: " << subjectDescription << '\n';
    return false;
}
//listing
void TodoList::complete() {
    std::cout << "Completed tasks:\n";
    bool atLeastOne = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].completionStatus) {
            atLeastOne = true;
            std::cout << "- " << tasks[i].description << '\n';
        }
    }
    if (!atLeastOne) {
        std::cout << "No completed tasks.\n";
    }
}
void TodoList::all() {
    std::cout << "All tasks:\n";

    if (tasks.empty()) {
        std::cout << "The todo list is empty.";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "- [" << (tasks[i].completionStatus ? 'X' : ' ') << "] "
                  << tasks[i].description;

        if (!tasks[i].tags.empty()) {
            std::cout << " (";
            for (int j = 0; j < tasks[i].tags.size(); j++) {
                std::cout << tasks[i].tags[j];
                if (j + 1 < tasks[i].tags.size()) {
                    std::cout << ", ";
                }
            }
            std::cout << ")";
        }
        std::cout << '\n';
    }
}
void TodoList::incomplete() {
    std::cout << "Incomplete tasks:\n";

    bool atLeastOne = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (!tasks[i].completionStatus) {
            atLeastOne = true;
            std::cout << "- " << tasks[i].description << '\n';
        }
    }
    if (!atLeastOne) {
        std::cout << "No incomplete tasks.\n";
    }
}
void TodoList::taggedWith(std::string subjectTag) {
    if (subjectTag == "") {
        std::cout << "Cannot search with a blank tag.\n";
        return;
    }

    std::cout << "Tasks tagged with \"" << subjectTag << "\":\n";

    bool atLeastOne = false;
    for (std::size_t i = 0; i < tasks.size(); i++) {
        if (hasTag(tasks[i], subjectTag)) {
            atLeastOne = true;
            std::cout << "- " << tasks[i].description << '\n';
        }
    }

    if (!atLeastOne) {
        std::cout << "No tasks found.\n";
    }
}
void TodoList::clear() {
    tasks.clear();
}
bool TodoList::hasTag(Task subjectTask, std::string subjectTag) {
    for (int i = 0; i < subjectTask.tags.size(); i++) {
        if (subjectTask.tags[i] == subjectTag) {
            return true;
        }
    }
    return false;
}