#ifndef STRUCTURE_H
#define STRUCTURE_H


    #include<iostream>
    #include<vector>
    #include "console_utils.h"
    using namespace std;
    
    class Person{
        protected:
            string name;
            int ID;
            string father_name;
            bool is_deleted;
        public:
            Person(string name, int id, string father_name){
                this->name = name;
                this->ID = id;
                this->father_name = father_name;
                this->is_deleted = false;
            }
            string getname(){
                return name; 
            }
            int getID(){
                return ID;
            }
            string getfather_name(){
                return father_name;
            }
            void virtual display(){}
        static vector<Person> persons;
        static void addPerson(Person person){
            persons.push_back(person);
        }
        static int total_persons(){
            return persons.size();
        }
    };

    class Student: public Person{
        private:
            vector<string> course;

            float gpa;

        public:
            Student(string name, int id, string father_name, vector<string>  course, float gpa): Person(name, id, father_name){
                this->course = course;
                this->gpa = gpa;
            }
            // static bool CheckStudent(int id){
            //     for(const auto& Student: students){
            //         if(Student->ID == id && !Student->is_deleted){
            //             return true;
            //         }
            //     }
            //     return false;
            // }
            static Student searchStudent(int id, bool& found){
                for(const auto& S: students){
                    if(S.ID == id && !S.is_deleted){
                        found = true;
                        return S;
                    }
                }
                found = false;
                return Student("", -1, "", {}, 0.0);
            }
            
            static void displayStudent(int id){
                bool found = false;
                Student student = searchStudent(id, found);
                if(found){
                    cout << "Student Name: " << student.name << endl;
                    cout << "Student ID: " << student.ID << endl;
                    cout << "Father's Name: " << student.father_name << endl;
                    cout << "Course: ";
                    for(const auto& c: student.course){
                        cout << c << " ";
                    }
                    cout << endl;
                    cout << "GPA: " << student.gpa << endl;
                }
                else {
                    printError("Student with ID " + to_string(id) + " not found.");
                }
            }
            void setname(string name){
                this->name = name;
            }
            void setID(int id){
                this->ID = id;
            }
            void setfather_name(string father_name){
                this->father_name = father_name;
            }
            void setcourse(vector<string> course){
                this->course = course;
            }
            void setgpa(float gpa){
                this->gpa = gpa;
            } 
            vector<string> getcourse(){
                return course;
            }
            float getgpa(){
                return gpa;
            }
            // add this to Student class in structure.h
            static Student* getStudentRef(int id, bool& found){
            for(auto& S : students){ 
            if(S.ID == id && !S.is_deleted){
                found = true;
                return &S;
                }
            }
            found = false;
            return nullptr;}

        static vector<Student> students;
        static void addStudent(Student student){
            students.push_back(student);
            addPerson(student);
        }
    };

    class Teacher: public Person{
        private:
            string subject;
            int experience;

        public:
            Teacher(string name, int id, string father_name, string subject, int experience): Person(name, id, father_name){
                this->subject = subject;
                this->experience = experience;
            }
            static bool CheckTeacher(int id){
                for(const auto& Teacher: teachers){
                    if(Teacher.ID == id && !Teacher.is_deleted){
                        return true;
                    }
                }
                return false;
            }
            void display(){
                if(!is_deleted){
                    cout << "Teacher Name: " << name << endl;
                    cout << "Teacher ID: " << ID << endl;
                    cout << "Father's Name: " << father_name << endl;
                    cout << "Subject: " << subject << endl;
                    cout << "Experience: " << experience << " years" << endl;
                }
                else {
                    printError("This teacher record has been deleted.");
                }
        }
        static vector<Teacher> teachers;
        static void addTeacher(Teacher teacher){
            teachers.push_back(teacher);
            addPerson(teacher);
        }
    };

    vector<Person> Person::persons;
    vector<Student> Student::students;
    vector<Teacher> Teacher::teachers;

#endif