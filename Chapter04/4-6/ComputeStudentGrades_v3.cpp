#include <algorithm>
#include <iomanip>      // defines setprecision manipulator
#include <ios>          // defines streamsize
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;

int main(){
    vector<Student_info> students;
    Student_info record;          // temporary storage before pushing into students vector
    string::size_type maxlen = 0; // to store length of the longest name for padding. 
                                  //must be of string type to be used with max function

    // read and store all the students data.
    // Invariant: students contains all the student records read so far
    while (read(cin, record)){
        // find length of the longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // sort student records in alphabetical order
    sort(students.begin(), students.end(), compare);

    // output names and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        //write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]); // calculate student's grade first in case domain_error is thrown
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec); // restore precision
        } catch (domain_error e){
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}

