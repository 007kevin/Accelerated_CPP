/* Accelerated C++
 * Chapter 3.1 p 62
 *
 * Imagine a course in which each student's final exam counts for 40% of the final 
 * grade, the midterm exam counts for 20%, and the average homework grade makes up
 * the remaining 40%. Here is our first try at a program that helps students 
 * compute their final grades
 */

#include <iomanip> /* Notes: defines the manipulator setprecision: set number of significant bits in output. 
                    * although endl is an output manipulator, it is defined in iostream instead */ 
#include <ios> /* Notes: defines streamsize, which is the type io library uses to represent sizes */
#include <iostream> 
#include <string>

using std::cin;             using std::setprecision;
using std::cout;            using std::string;
using std::endl;            using std::streamsize;

int main(){
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final; /* Notes: Like the output operator <<, the input operator
                                returns its left operand as its result. Equivalent to 
                                cin >> midterm;
                                cin >> final; */

    //ask for the homework grades
    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";
    // the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    // a variable into which to read
    double x;

    /* invariant:
     * we have read count grades so far, and
     * sum is the sum of the first count grades
     */
    while (cin >> x){ /* The definition of istream defines the meaning of "cin" in the context
                         of a "while" or "if" statement (value of cin depends on success of last
                         read vaue. Furthermore, when arithmentic values are in the context of 
                         conditions, they are automatically converted to bool. */
        ++count;
        sum += x;
    }

    /* write the result.
     * We make a streamsize object 'prec' with the current pression of the cout stream before setting
     * the stream precision with the manipulator 'setprecision(3)' so that we can revert the precision
     * to what cout was before (good practice). */
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;

    /* note: could have equally written the following, but best practice to set the precision to 
     * part of the program intended
     *
     * streamsize prec = cout.precision(3) // set precision to 3, return the previous value
     * cout << "Your final grade is "
     *      << 0.2 * midtern + 0.3 * final + 0.4 * sum / count << endl;
     * cout.precision(prec); // reset precision to its original value
     */

    return 0;
}
