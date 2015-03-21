/* Exercise 3-4
 * Write a program to report the length of the longest and 
 * shortest string in its input
 */

#include <iostream>
#include <string>

int main(){
    std::string x, longest, shortest;
    longest = shortest = "";
    std::string::size_type llength, slength;
    llength = slength = 0;

    
    while (std::cin >> x){
        if (x.size() > longest.size())
            llength = (longest = x).size();

        if (shortest == "" || x.size() < shortest.size())
            slength = (shortest = x).size();
                
    }
    
    /* note: this will print only the first encounters of 
     * the longest and shortest strings
     */
    std::cout << "The longest string and size: " << longest
                << " " << llength << std::endl;
    std::cout << "The shortest string and size: " << shortest 
                << " " << slength << std::endl;
    return 0;
}
