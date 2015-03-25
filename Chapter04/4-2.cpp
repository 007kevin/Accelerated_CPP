/* Exercise 4-2 
 * Write a program to calculate the squares of int values up to
 * 100. The program should write two columns: The first lists the value; the
 * second contains the square of the value. Use setw to manage the output so 
 * that the values line up in columns
 */
#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

#define LIMIT 100

using std::setw;        using std::string;
using std::streamsize;  using std::to_string;
using std::cout;        using std::endl;

int main(){
    // First get the size of the largest digit for proper padding
    string::size_type size = std::to_string(LIMIT*LIMIT).size();

    for (int i = 1; i <= LIMIT; i++){
        cout << setw(3) << i << setw(size + 1) << i*i
             << cout.width(0) // reset field width value
             << endl;
    }
    return 0;
}

/* Note: had to compile with 'g++ -std=c++11' in order to use the std::to_string function */
