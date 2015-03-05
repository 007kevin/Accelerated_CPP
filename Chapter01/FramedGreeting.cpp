#include <iostream>
#include <string>

int main(){
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');

    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}

/* notes:
 * - If the variable and value have different types, the implementation
 *   convert the initial value to the type of the variable.
 *
 * - Defining a variable with const will not change the value of the 
 *   variable for the rest it its lifetime, thus cannot say const to the 
 *   variable name.
 *
 * - By using paraentheses in the definition, we tell the implementation
 *   to construct the variable in a way that depends on the variable type.
 */
