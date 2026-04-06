#include <string>
#include <sstream>
#include <iomanip>
#include "hello.hpp"

Student::Student(std::string input_full_name, std::string input_student_ID) {
    int where_break = input_full_name.find(' ');
    first_name = input_full_name.substr(0, where_break);
    last_name = input_full_name.substr(where_break + 1);
    student_ID = input_student_ID;
}

std::string Student::get_first_name() const {
    return first_name;
}
std::string Student::get_last_name() const {
    return last_name;
}
std::string Student::get_student_ID() const {
    return student_ID;
}
std::string Student::get_full_name() const {
    return first_name + " " + last_name;
}

Assignment::Assignment(std::string input_assignment_name, double input_total_points) {
    assignment_name = input_assignment_name;
    total_points = input_total_points;
}

std::string Assignment::get_assignment_name() const {
    return assignment_name;
}
double Assignment::get_total_points() const {
    return total_points;
}

void Gradebook::add_student(std::string input_full_name, std::string input_student_ID) {
    students.push_back((Student(input_full_name, input_student_ID)));
}
void Gradebook::add_assignment(std::string input_assignment_name, double input_total_points) {
    assignments.push_back((Assignment(input_assignment_name, input_total_points)));
}
void Gradebook::enter_grade(std::string input_full_name, std::string input_assignment_name, double input_grade) {
    grades[input_full_name][input_assignment_name] = input_grade;
}

std::string Gradebook::report() const {
    std::stringstream ss;

    if (students.empty() || assignments.empty()) {
        ss << "No data available\n";
        return ss.str();
    }

    // Header
    ss << "Last_Name,First_Name,Student_Id";
    for (int i = 0; i < assignments.size(); i++) {
        ss << "," << assignments[i].get_assignment_name();
    }
    ss << ",Average\n";

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        ss << s.get_last_name() << "," << s.get_first_name() << "," << s.get_student_ID();

        double earned = 0;
        double possible = 0;

        for (int j = 0; j < assignments.size(); j++) {
            std::string a_name = assignments[j].get_assignment_name();

            if (grades.count(s.get_full_name()) &&
                grades.at(s.get_full_name()).count(a_name)) {

                double g = grades.at(s.get_full_name()).at(a_name);
                ss << "," << g;

                earned += g;
                possible += assignments[j].get_total_points();
                } else {
                    ss << ",none";
                }
        }

        // Average
        if (possible > 0) {
            double avg = earned / possible * 100;
            ss << "," << std::fixed << std::setprecision(3) << avg;
        } else {
            ss << ",none";
        }

        ss << "\n";
    }

    return ss.str();
}
std::string Gradebook::assignment_report(std::string input_assignment_name) const {
    std::stringstream ss;

    ss << "Last_Name,First_Name,Student_Id,Score\n";

    double total = 0;
    int count = 0;
    double max_points = 0;

    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i].get_assignment_name() == input_assignment_name) {
            max_points = assignments[i].get_total_points();
        }
    }

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        ss << s.get_last_name() << "," << s.get_first_name() << "," << s.get_student_ID();

        if (grades.count(s.get_full_name()) &&
            grades.at(s.get_full_name()).count(input_assignment_name)) {

            double g = grades.at(s.get_full_name()).at(input_assignment_name);
            ss << "," << g;

            total += g;
            count++;
            } else {
                ss << ",none";
            }

        ss << "\n";
    }

    if (count > 0) {
        ss << "\nAverage score: " << (total / count)
           << " / " << max_points << "\n";
    } else {
        ss << "\nAverage score: none\n";
    }

    return ss.str();
}