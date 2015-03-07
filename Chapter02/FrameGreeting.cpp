#include <iostream>
#include <string>

//state what standard library names are to be used
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]){
    // ask for the padding value
    cout << "Enter the padding value: ";
    int val;
    cin >> val;


    // ask for the person's name
    cout << "Please enter your first name: ";
    
    // read the name
    string name; 
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting
    const int pad = val;

    // the number of rows and columns to write
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // write a blank line to separate the output from the input
    cout << endl;

    // write rows rows of output
    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != cols) {
            // check is appropriate to write the greeting
            if (r == pad + 1 && c == pad + 1){
                cout << greeting;
                c += greeting.size();
            } else {

                //check is on the border
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }

    return 0;
}

/* Technique for reading loops
 * 1) When the loop terminates, the loop condition is now false.
 *    For example, the while loop has "r != rows" as its condition.
 *    Once the loops are done, the condition is false,
 *    so we know r = rows
 * 2) Loop Invariant: A statement about the loop that is true
 *    for every iteration. To ensure the loop invariant is valid,
 *    statement must be true at two points of the loop.
 *      i) Statement should be true before the beginning of every
 *         loop.
 *     ii) Statement should be true before reaching the end of
 *         the loop.
 *
 */
