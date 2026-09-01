#include <iostream>
#include "console_utils.h"
#include "structure.h"

// Declaration of functions:
void ViewStudent();
void UpdateStudent();
void DeleteStudent();
void ViewAllStudents();
void EnterNewStudent();
void DELETEDSTUDENT();

// Definition of functions:

void ViewStudent() {
    clear();
    Header();
    cout << BOLD << BRIGHT_CYAN << "View Student" << RESET << endl;
    cout << "Enter Student ID: ";
    int id;
    cin >> id;
    Student::displayStudent(id);
    printSuccess("Press Enter to return to the Student Menu...");
    cin.ignore();
    cin.get();
}

void EnterNewStudent(){
    Header();
    Student new_student("", 0, "", {}, 0.0);
    cout << "Enter Student Name: ";
    cin.ignore();
    string s;
    getline(cin, s);
    new_student.setname(s);
    cout << "Enter Student ID: ";
    int id;
    try {
        cin >> id;
        new_student.setID(id);
    } catch (const std::exception& e) {
        printError("Invalid input for Student ID.");
        return;
    }
    cout << "Enter Father's Name: ";
    cin.ignore();
    getline(cin, s);
    new_student.setfather_name(s);
    cout << "Enter number of courses: ";
    int num_courses;
    cin >> num_courses;
    vector<string> courses;
    for (int i = 0; i < num_courses; ++i) {
        cout << "Enter course " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, s);
        courses.push_back(s);
    }
    new_student.setcourse(courses);
    cout << "Enter GPA: ";
    float gpa;
    cin >> gpa;
    new_student.setgpa(gpa);
    Student::addStudent(new_student);
    printSuccess("Student added successfully!\nPress Enter to return to the Student Menu...");
    cin.ignore();
    cin.get();
}

void UpdateStudent(){
    Header();
    cout << BOLD << BRIGHT_CYAN << "Update Student" << RESET << endl;
    cout<<"Enter student id: ";
    int id;
    cin>>id;
    bool found = false;
    Student* student = Student::getStudentRef(id, found);
    if(found){
    printWarning("Student to be updated:\n");
    Student::displayStudent(id);
    printInfo("\nEnter new details for the student (leave blank to keep current value):");
    cin.ignore();
    string input;
    cout << "Enter new name: ";
    getline(cin, input);
    if (!input.empty()) {
        student->setname(input);
    }
    cout << "Enter new ID: ";
    getline(cin, input);
    if (!input.empty()) {
        student->setID(stoi(input));
    }
    cout << "Enter new father's name: ";
    getline(cin, input);
    if (!input.empty()) {
        student->setfather_name(input);
    }
    cout << "Enter new GPA: ";
    getline(cin, input);
    if (!input.empty()) {
        student->setgpa(stof(input));
    }
    printSuccess("Student updated successfully!\nPress Enter to return to the Student Menu...");
    cin.ignore();
    cin.get();

    }
    else{
        printError("Student with ID " + to_string(id) + " not found.");
        printInfo("Press Enter to return to the Student Menu...");
        cin.ignore();
        cin.get();
    }
}

void DeleteStudent(){
    Header();
    cout << BOLD << BRIGHT_CYAN << "Delete Student" << RESET << endl;
    cout << "Enter Student ID to delete: ";
    int id;
    cin >> id;
    bool found = false;
    Student* student = Student::getStudentRef(id, found);
    if(found){
        student->deletePerson();
        printSuccess("Student deleted successfully!\nPress Enter to return to the Student Menu...");
        cin.ignore();
        cin.get();
    }
    else{
        printError("Student with ID " + to_string(id) + " not found.");
        printInfo("Press Enter to return to the Student Menu...");
        cin.ignore();
        cin.get();
    }
}

void ViewAllStudents(){
    Header();
    cout << BOLD << BRIGHT_CYAN << "View All Students" << RESET << endl;
    cout << YELLOW << "Total Students: " << Student::total_students() << RESET << endl;
    if(Student::students.empty()){
        printInfo("No students found.");
    }
    else{
        for(auto& student: Student::students){
                Student::displayStudent(student.getID());
                cout << "----------------------------------------" << endl;
        }
    }
    printInfo("Press Enter to return to the Student Menu...");
    cin.ignore();
    cin.get();
}

void DELETEDSTUDENT(){
    Header();
    cout << BOLD << BRIGHT_CYAN << "View Deleted Students" << RESET << endl;
    bool any_deleted = false;
    for(auto& student: Student::students){
        if(student.status()){
            any_deleted = true;
            Student::displayStudent(student.getID());
            cout << "----------------------------------------" << endl;
        }
    }
    if(!any_deleted){
        printInfo("No deleted students found.");
    }
    printInfo("Press Enter to return to the Student Menu...");
    cin.ignore();
    cin.get();
}