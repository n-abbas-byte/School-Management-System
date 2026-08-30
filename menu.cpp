#include<iostream>
#include "console_utils.h"
#include "structure.h"
#include "student.cpp"
using namespace std;

// Declaration of functions:
void Stud_menu();
void Teach_menu();
void Basic_menu();

// Definition of functions:

void Stud_menu(){
    Header();
    cout<< WHITE <<"1. View Student" << endl << "2. Update Student" << endl << "3. Delete Students" << endl << "4. Veiw all students \n5. Enter a new student\n6. Go back\nEnter your choice: " << RESET;
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
    else if (choice == 5){
        EnterNewStudent();
        return Stud_menu();
        }
    else if (choice == 6){
        return Basic_menu();
    }
    else if (choice == 3 || choice == 4){
        printWarning("This part is under development");
        pause(2);
        cout<< WHITE << "Returning to Student Menu..." << RESET << endl;
        pause(1.5);
        return Stud_menu();
    }
    else{
        printWarning("Invalid choice, choose from 1, 2, 3, 4 or 5. Please try again.");
        pause(2);
        return Stud_menu();
    }
}
void Teach_menu(){
    printWarning("This part is under development");
    pause(2);
    Basic_menu();
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