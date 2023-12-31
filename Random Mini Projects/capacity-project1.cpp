/***
Basic Student Grade Management System:
Math, English, Science
0. Exit the program
1. Add a student to the System
     - Ask for name
     - Ask for the grades

2. Modify a student's info

3. Show a student's report card

4. Show all students' report card

Inside report card:
    average grade, total grade / 300
    the score for each subject: A,B,C,D,E,F
    the overall score: A--F

A particular student
Name
Math   50 (E)
English  80 (A)
Science  70 (B)
Total:   200
Percentage: 65% (C)

ID     Student Name        Math    English   Science     Percentage
0         Daniel Ilozor     60       80        90           73
1
2
...
**/

#include <iostream>
using namespace std;

const int max_size = 100000;
string full_name[max_size];
float math_score[max_size];
float english_score[max_size];
float science_score[max_size];
int numStudents = 0;

int getId(){
    int id;
    cout << "Enter the ID of the student: ";
    cin >> id;
    if(id < 0 or id >= numStudents){
        cout << "This id is invalid\n";
        return -1;
    }
    cout << "\n";
    return id;
}

void print_menu(){
    cout << "\n";
    cout << "Welcome to our Grade System\n";
    cout << "0. Exit\n";
    cout << "1. Add a student to the System\n";
    cout << "2. Modify a student's info\n";
    cout << "3. Show a student's report card\n";
    cout << "4. Show all students' report card\n";
    cout << "\n";
}

void add_student(){
    cout << "\nThis is to add a student\n";
    cout << "Enter the student's full name: ";

    cin.ignore(); getline(cin, full_name[numStudents]);

    cout << "Enter the student's math score: ";
    cin >> math_score[numStudents];
    cout << "Enter the student's english score: ";
    cin >> english_score[numStudents];
    cout << "Enter the student's science score: ";
    cin >> science_score[numStudents];

    cout << "The ID of this student is #" << numStudents << "\n";
    numStudents++;
}

bool modify_student(){
    cout << "\nThis is to modify a student\n";

    int id = getId();
    if(id==-1) return false;


    char option;

    cout << "Do you want to change the student's full name? Respond with y/n/e (yes/no/exit): ";
    cin >> option;
    if(option == 'y'){
        cout << "Enter the new full name of the student: ";
        cin.ignore(); getline(cin, full_name[id]);
    }
    else if(option!='n') return false;

    cout << "Do you want to change the student's math score? Respond with y/n/e (yes/no/exit): ";
    cin >> option;
    if(option == 'y'){
        cout << "Enter the new math score of the student: ";
        cin >> math_score[id];
    }
    else if(option!='n') return true;

    cout << "Do you want to change the student's english score? Respond with y/n/e (yes/no/exit): ";
    cin >> option;
    if(option == 'y'){
        cout << "Enter the new english score of the student: ";
        cin >> english_score[id];
    }
    else if(option!='n') return true;

    cout << "Do you want to change the student's science score? Respond with y/n/e (yes/no/exit): ";
    cin >> option;
    if(option == 'y'){
        cout << "Enter the new science score of the student: ";
        cin >> science_score[id];
    }
    else if(option!='n') return true;

    return true;
}

float getScore(int id){
    return math_score[id]+english_score[id]+science_score[id];
}

string grade_letter(float score){
    if(score>=90) return "A*";
    if(score>=80) return "A";
    if(score>=70) return "B";
    if(score>=60) return "C";
    if(score>=50) return "D";
    if(score>=40) return "E";
    return "F";
}

void show_report_card(){
    if(numStudents==0){
        cout << "\nThere are no students in this system\n";
        return;
    }

    cout << "\nThis is to show a student's report card\n\n";
    int id = getId();
    if(id==-1) return;

    cout << "Student's Full Name: " << full_name[id] << "\n";
    cout << "Student's Math Score: " << math_score[id] << " (" << grade_letter(math_score[id]) << ")\n";
    cout << "Student's English Score: " << english_score[id] << " (" << grade_letter(english_score[id]) << ")\n";
    cout << "Student's Science Score: " << science_score[id] << " (" << grade_letter(science_score[id]) << ")\n";
    float total_score = getScore(id);
    cout << "Student's Total Score: " << total_score << "\n";
    cout << "Student's Percentage: " << total_score/3 << "%" << " (" << grade_letter(total_score/3) << ")\n";
}

void show_all_report_cards(){
    if(numStudents==0){
        cout << "\nThere are no students in this system\n";
        return;
    }

    cout << "\nThis is to show all students' report cards\n\n";

    cout << "ID\tStudent Name\tMath\tEnglish\tScience\tPercentage\n";
    for(int i = 0; i < numStudents; i++){
        cout << i << "\t";
        cout << full_name[i] << "\t";
        cout << math_score[i] << "\t";
        cout << english_score[i] << "\t";
        cout << science_score[i] << "\t";
        float average = getScore(i)/3;
        cout << average << " ";
        cout << "(" << grade_letter(average) << ")";
        cout << "\n";
    }
}

int main()
{
    while(true){
        print_menu();
        int option;
        cout << "Enter your choice: ";
        cin >> option;

        if(option==0){
            cout << "Thanks for visiting. See you next time!\n";
            return 0;
        }
        else if(option==1){
            add_student();
        }
        else if(option==2){
            if(modify_student())
                cout << "Student info has successfully been modified\n";
        }
        else if(option==3){
            show_report_card();
        }
        else if(option==4){
            show_all_report_cards();
        }
        else{
            cout << "Your choice is not valid. Try again!\n";
        }
    }
}
