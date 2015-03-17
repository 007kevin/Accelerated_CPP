/* Exercise 3-2:
 * Write a program to compute and print the quartiles (that is,
 * the quarter of the numbers with the largest values, the 
 * next highest quarter, and no on) of a set of integers.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]){
    std::cout << "Enter the integer values: ";
    std::vector<int> integerlist;

    int x;
    //invariant: integetlist contains all the integers read so far
    while (std::cin >> x)
        integerlist.push_back(x);
    
    typedef std::vector<int>::size_type vec_sz;
    vec_sz size = integerlist.size();
    vec_sz mid = size / 2;
    double median;
    double lowerQuartile;
    double  upperQuartile;

    sort(integerlist.begin(), integerlist.end());
    std::cout << std::endl;
    std::cout << "Ordered data: ";

    int i = 0;
    while (i != size)
        std::cout << integerlist[i++] <<  " ";
    std::cout << std::endl;
    
     median = size % 2 == 0 ? (integerlist[mid] + integerlist[mid - 1]) / 2 : 
                                    integerlist[mid];
     vec_sz lqmid = mid / 2;
     lowerQuartile = lqmid % 2 == 0 ? (integerlist[lqmid] + integerlist[lqmid - 1]) / 2 :
                                    integerlist[lqmid];

     vec_sz upmid = size - lqmid;
     upperQuartile = upmid % 2 == 0 ? (integerlist[upmid] + integerlist[upmid - 1]) / 2 :
                                    integerlist[upmid];

     std::cout << lowerQuartile << " " << median << " " << upperQuartile << std::endl;

    return 0;
}
