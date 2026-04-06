#include <string>
#include <vector>
#include <map>

//classes for class
class Student {
private:
    std::string first_name;
    std::string last_name;
    std::string student_ID;
public:
    Student(std::string input_full_name, std::string input_student_ID);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_student_ID() const;
    std::string get_full_name() const;
};

class Assignment {
private:
    std::string assignment_name;
    double total_points;
public:
    Assignment(std::string input_assignment_name, double input_total_points);

    std::string get_assignment_name() const;
    double get_total_points() const;
};
//time for ultimate class

class Gradebook {
private:
    std::vector<Student> students;
    std::vector<Assignment> assignments;

    //mapsception full name -> (assignment -> grade)
    std::map<std::string, std::map<std::string, double>> grades;
public:
    void add_student(std::string input_full_name, std::string input_student_ID);
    void add_assignment(std::string input_assignment_name, double input_total_points);
    void enter_grade(std::string input_full_name, std::string input_assignment_name, double input_grade);

    std::string report() const;
    std::string assignment_report(std::string input_assignment_name) const;


};
