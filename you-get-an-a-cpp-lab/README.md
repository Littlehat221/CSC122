# Gradebook

This is a gradebook system in c++. You can manage students, their assignments, their grades for those assignments, and you can create reports.
## How to use

create a gradebook by doing Gradebook YourGradebookName;
add students by using YourGradebookName.add_student("StudentFirstName StudentLastName", "StudentID"); Make sure there is only a single space in the name string.
add assignments by using YourGradebookName.add_assignment("Quizname", MaxScore);
Enter grades for students by using YourGradebookName.enter_grade("StudentFirstName StudentLastName", "Quizname", theirScore);
generate a full report by using std::cout << gradebook.report();
generate an assignment report by using std::cout << gradebook.assignment_report("assignment name");