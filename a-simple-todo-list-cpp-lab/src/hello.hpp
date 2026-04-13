#include <string>
#include <vector>

class TodoList {
private:
    struct Task {
        std::string description;
        bool completionStatus;
        std::vector<std::string> tags;
    };
    std::vector<Task> tasks;

    //helpers only
    //static bool isSameText(std::string first, std::string second);
    static bool hasTag(Task subjectTask, std::string subjectTag);

    //void prettyPrintTasks(std::vector<Task> subjectTasks, std::string title);
public:
    //TodoList();

    bool add(std::string subjectDescription);
    bool add(std::string subjectDescription, std::vector<std::string> subjectTags);
    //marking
    bool complete(std::string subjectDescription);
    //listing
    void complete();
    void all();
    void incomplete();
    void taggedWith(std::string subjectTag);
    void clear();
};
