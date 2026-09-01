#include<iostream>
#include "console_utils.h"
#include "structure.h"
#include "student.cpp"
#include "teachers.cpp"
using namespace std;

// Declaration of functions:
void Stud_menu();
void Teach_menu();
void Basic_menu();

// Definition of functions:

void Stud_menu(){
    Header();
    cout<< BRIGHT_CYAN << ITALIC << "Student Menu" << RESET << endl;
    cout << YELLOW << "Total Students: " << Student::total_students() << RESET << endl;
    cout<< WHITE <<"1. View Student" << endl << "2. Update Student" << endl << "3. Delete Students" << endl << "4. Veiw all students \n5. Enter a new student\n6.Show all deleted students\n7. Go back\nEnter your choice: " << RESET;
    int choice;
    cin >> choice;
    if (choice == 1){
        ViewStudent();
        return Stud_menu();
    }
    if (choice == 2){
        UpdateStudent();
        return Stud_menu();
    }
    else if (choice == 3){
        DeleteStudent();
        return Stud_menu();
    }
    else if (choice == 4){
        ViewAllStudents();
        return Stud_menu();
    }

    else if (choice == 5){
        EnterNewStudent();
        return Stud_menu();
        }
    else if (choice == 6){
        DELETEDSTUDENT();
        return Stud_menu();
    }
    else if (choice == 7){
        Basic_menu();
    }
    else{
        printWarning("Invalid choice, choose from 1, 2, 3, 4 or 5. Please try again.");
        pause(2);
        return Stud_menu();
    }
}
void Teach_menu(){
    Header();
    cout<< BRIGHT_CYAN << ITALIC << "Teacher Menu" << RESET << endl;
    cout << YELLOW << "Total Teachers: " << Teacher::total_teachers() << RESET << endl;
    cout<< WHITE <<"1. View Teacher" << endl << "2. Update Teacher" << endl << "3. Delete Teacher" << endl << "4. Veiw all Teachers \n5. Enter a new Teacher\n6. Go back\nEnter your choice: " << RESET;
    int choice;
    cin >> choice;
    if (choice == 1){
        ViewTeacher();
        return Teach_menu();
    }
    if (choice == 2){
        UpdateTeacher();
        return Teach_menu();
    }
    else if (choice == 3){
        DeleteTeacher();
        return Teach_menu();
    }
    else if (choice == 4){
        ViewAllTeachers();
        return Teach_menu();
    }
    else if (choice == 5){
        EnterNewTeacher();
        return Teach_menu();
    }
    else if (choice == 6){
        Basic_menu();
    }
    else{
        printWarning("Invalid choice, choose from 1, 2, 3, 4 or 5. Please try again.");
        pause(2);
        return Teach_menu();
    }
}

void Basic_menu(){
    Header();
    cout << ITALIC << "1. Student Menu" << endl
    << "2. Teacher Menu" << endl
    << "3. Exit" << endl
    << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        Stud_menu();
    } 
    else if ( choice == 2 ){
        Teach_menu();
    }
    else if (choice == 3) {
        exitProgram();
    }
    else {
        printWarning("Invalid choice, choose from 1, 2, or 3. Please try again.");
        pause(2);
        return Basic_menu();
    }
}


int main(){
    Basic_menu();
}


//  Soft deletion pr kam krna ha, using a status variable in the structure class, and then filtering out the deleted records when displaying the data.