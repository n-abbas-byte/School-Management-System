// console_utils.h
#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// Reset
const string RESET = "\033[0m";

// Text colors
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

// Bright text colors
const string BRIGHT_BLACK = "\033[90m";
const string BRIGHT_RED = "\033[91m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_BLUE = "\033[94m";
const string BRIGHT_MAGENTA = "\033[95m";
const string BRIGHT_CYAN = "\033[96m";
const string BRIGHT_WHITE = "\033[97m";

// Background colors
const string BG_BLACK = "\033[40m";
const string BG_RED = "\033[41m";
const string BG_GREEN = "\033[42m";
const string BG_YELLOW = "\033[43m";
const string BG_BLUE = "\033[44m";
const string BG_MAGENTA = "\033[45m";
const string BG_CYAN = "\033[46m";
const string BG_WHITE = "\033[47m";

// Text styles
const string BOLD = "\033[1m";
const string DIM = "\033[2m";
const string ITALIC = "\033[3m";
const string UNDERLINE = "\033[4m";
const string BLINK = "\033[5m";
const string REVERSE = "\033[7m";      // swaps foreground/background
const string STRIKETHROUGH = "\033[9m";

// Utility functions
void clear(){
    system("clear");
}

void printSuccess(string msg){
    cout << GREEN << msg << RESET << endl;
}

void printError(string msg){
    cout << RED << msg << RESET << endl;
}

void printWarning(string msg){
    cout << YELLOW << msg << RESET << endl;
}

void printHeader(string msg){
    cout << BOLD << CYAN << msg << RESET << endl;
}

void printInfo(string msg){
    cout << BLUE << msg << RESET << endl;
}

void pause(int seconds = 2){
    this_thread::sleep_for(chrono::seconds(seconds));
}

void exitProgram(){
    cout << CYAN << "Exiting program..." << RESET << endl;
    pause(1.5);
    cout << CYAN << "Thank you for using the Student Management System!" << RESET << endl;
    pause(1.8);
    printSuccess("Goodbye!");
    exit(0);
}

void Header(){
    clear();
    cout<< BOLD << BG_BLACK << BRIGHT_WHITE << R"(
           ______________________         _____________________________________       ______________________
          /                     /        /                                    /      /                     /
         /   __________________/        /     __________      _________      /      /   __________________/ 
        /   /                          /     /         /     /        /     /      /   /                    
       /   /                          /     /         /     /        /     /      /   /                     
      /   /____________________      /     /         /     /        /     /      /   /___________________   
     /                        /     /     /         /     /        /     /      /                       /   
    /___________________     /     /     /         /     /        /     /      /__________________     /    
                       /    /     /     /         /     /        /     /                         /    /     
                      /    /     /     /         /     /        /     /                         /    /      
  ___________________/    /     /     /         /_____/        /     /       __________________/    /       
 /                       /     /     /                        /     /       /                      /        
/_______________________/     /_____/                        /_____/       /______________________/         )" << RESET << endl;
  cout<< BOLD << BG_BLACK << BRIGHT_CYAN << ITALIC << "       School                                Management                            System                   " << RESET << endl;
  cout << BOLD << BRIGHT_WHITE << "____________________________________________________________________________________________________________" << RESET << endl;
  
}


#endif