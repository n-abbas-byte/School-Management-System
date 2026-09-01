#include <iostream>
#include "console_utils.h"
#include "structure.h"

// Declaration of functions:
void ViewTeacher();
void UpdateTeacher();
void DeleteTeacher();
void ViewAllTeachers();
void EnterNewTeacher();

// Definition of functions:
void ViewTeacher() {
    printWarning("This part is under development");
    pause(2);
    cout<< WHITE << "Returning to Teacher Menu..." << RESET << endl;
    pause(1.5);
}

void UpdateTeacher() {
    printWarning("This part is under development");
    pause(2);
    cout<< WHITE << "Returning to Teacher Menu..." << RESET << endl;
    pause(1.5);
}

void DeleteTeacher() {
    printWarning("This part is under development");
    pause(2);
    cout<< WHITE << "Returning to Teacher Menu..." << RESET << endl;
    pause(1.5);
}

void ViewAllTeachers() {
    cout << YELLOW << "Total Teachers: " << Teacher::total_teachers() << RESET << endl;
    if(Teacher::teachers.empty()){
        printInfo("No teachers found.");
    }
    else{
        for(auto& teacher: Teacher::teachers){
            teacher.display();
            cout << "----------------------------------------" << endl;
        }
    }
    printInfo("Press Enter to return to the Teacher Menu...");
    cin.ignore();
    cin.get();
    pause(2);
    cout<< WHITE << "Returning to Teacher Menu..." << RESET << endl;
    pause(1.5); 
}

void EnterNewTeacher() {
    Header();
    cout << BOLD << BRIGHT_CYAN << "Enter New Teacher" << RESET << endl;
    string input;
    Teacher new_teacher("", 0, "", {}, 0.0);
    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, input);
    new_teacher.setname(input);
    cout << "Enter Teacher ID: ";
    try {
        cin >> input;
        new_teacher.setID(stoi(input));
    } catch (const std::exception& e) {
        printError("Invalid input for Teacher ID.");
        return;
    }
    cout << "Enter Father's Name: ";
    cin.ignore();
    getline(cin, input);
    new_teacher.setfather_name(input);
    cout << "Enter Subject: ";
    getline(cin, input);
    new_teacher.setsubject(input);
    cout << "Enter Experience (in years): ";
    try {
        getline(cin, input);
        new_teacher.setexperience(stoi(input));
    } catch (const std::exception& e) {
        printError("Invalid input for Experience.");
        return;
    }
    Teacher::addTeacher(new_teacher);
    printSuccess("Teacher added successfully!\nPress Enter to return to the Teacher Menu...");
    cin.ignore();
    cin.get();
    pause(2);
    cout<< WHITE << "Returning to Teacher Menu..." << RESET << endl;
    pause(1.5);
}