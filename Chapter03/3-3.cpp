/* Excercise 3-3
 * Write a program to count how many times each distinct word
 * appears appears in its input 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<string> strlist;
    vector<string>::size_type count = 0;
    string x;

    //invariant: count is the number of unique strings in the vector
    while (cin >> x){
        if (count == 0){
            strlist.push_back(x);
            ++count;
        }
        else{
            int i;
            //invariant: have compared i strings in the vector
            for (i = 0; i < count; i++)
                if (strlist[i] == x)
                    break;
            if (i == count){
                 strlist.push_back(x);
                 ++count;
            }
        }
    }    
    cout << count << " unique values found." << endl;

    return 0;
}
