/* Exercise 3-5
 * Write a program that will keep track of grades of several 
 * students at once. The program could keep two vectors in sync: 
 * The first should hold the student's names, and the second the final
 * grades that can be computed as input read. For now, you should
 * assume a fixed number of homework grades
 */

#include <iostream>
#include <ios> /* to define streamsize */
#include <iomanip> /* for the output manipulator setprecision */
#include <string>
#include <vector>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::vector;
using std::streamsize;

#define NUM_HW 3

int main(void){
    vector<string> nameList;
    vector<double> gradeList;
    bool done = false;

    while (!done){
        //ask for student's name
        cout << "Please enter your first name: ";
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;
        nameList.push_back(name);

        //ask for midterm and final exam grades
        cout << "Please enter your midterm and final grades: ";
        double midterm, final;
        cin >> midterm >> final;

        //ask for and read homework grades
        cout << "Enter all your homework grades: ";
        vector<double> homework;
        // a variable into which to read
        double x;
        int count = 0;
        double sum = 0;
        while (count < NUM_HW){
            cin >> x;
            sum += x;
            count++;
        }
        //calculate final grades to be inputted into the gradeList
        double finalgrade = 0.2 * midterm + 0.4 * final + 0.4 * sum/count;
        gradeList.push_back(finalgrade);

        cout << "More students? (Y/N) ";
        string s;
        cin >> s;
        if (s != "Y")
            done = true;
    }

    vector<string>::size_type size = nameList.size();
    int i;
    for (i = 0; i < size; i++){
        streamsize prec = cout.precision();
        cout << "Student: " << nameList[i] << ", " << "Grade: " << setprecision(3) << gradeList[i] << setprecision(prec) << endl;
    }


    return 0;
}
