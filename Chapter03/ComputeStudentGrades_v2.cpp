#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main(){
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    /* The vector type is defined using a language feature called template classes */
    vector<double> homework;
    double x;
    //invariant: homework contains all the homework grades read so far
    while (cin >> x)
        homework.push_back(x);

    /* Store vector size in local variable to avoid calling the vector size() method twice */
    /* Different implementations use different types to represent sizes, so we cannot write
     * appropriate type directly and remain implementation-independent. Hence, make use of the 
     * size_type that the library defines to represent container sizes */
    typedef vector<double>::size_type vec_sz; /* << Names defined via typedef have the same 
                                                 scope as any other names */
    vec_sz size = homework.size();
    if (size == 0){
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;

        return 1;
    }
    /* sort functions degined in <algorithm>, in non-decreasing (note how 'increasing' was not used
     * because some elements might be equal to one another */
    sort(homework.begin(), homework.end()); /* << sort function works in place; no new containers 
                                               created to hold results */

    vec_sz mid = size/2;
    double median;
    /* Observation: Elements of the vector object can be accessed via index */
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;

    return 0;
}

/* Interesting note on vector and sort:
 * Every standard-conforming C++ implementation must
 *      Implement vector so that appending a large number of elements to a vector
 *      is no worse than proportional to the number of elements
 *
 *      Implement sort to be no slower than nlog(n), where n is the number of elements
 *      being sorted
 */
