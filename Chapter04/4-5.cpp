/*  Exercise 4-5 Write a function that reads words from an input stream and stores
 *  them in a vector. Use that function to write programs that count the number of
 *  words in the input, and to count how many times each work occurred
 */

#include <iostream>
#include <vector>
#include <iomanip> // defines setprecision manipulator
#include <ios>     // defines streamsize
#include <string>
#include <algorithm>

using std::cout;        using std::endl;
using std::setw;        using std::vector;
using std::cin;         using std::string;
using std::istream;

struct Word_info {
    string word;
    vector<string>::size_type count;
};

/* insert: will insert only unique words into list, else increment count */
istream& insert(istream& in, vector<Word_info>& list, vector<string>::size_type& max){
    string w;
    if (in >> w){
        vector<Word_info>::size_type i;
        for (i = 0; i != list.size(); i++){
            if (list[i].word == w){
                list[i].count++;
                break;        
            }
        }
        if (i == list.size()){
            if (w.size() > max)
                max = w.size();
            Word_info newRecord;
            newRecord.word = w;
            newRecord.count = 1;
            list.push_back(newRecord);
        }
    }
    return in;
}

int main(){
    vector<Word_info> uniquelist;
    vector<Word_info>::size_type i, count;
    vector<string>::size_type maxlen = 0;
    
    while (insert(cin, uniquelist, maxlen))
        ;

    count = uniquelist.size();
    
    for (i = 0; i < count; i++){
        cout << uniquelist[i].word << setw(maxlen - uniquelist[i].word.size() + 2) // calculate proper width
             << uniquelist[i].count << endl;
    }
    cout.width(0); //reset field width

    return 0;

}
