/* Exercise 0.10
 *
 * Rewrite the "Hello, world!" program so that a newline occurs everywhere
 * that whitespace is allowed in the program
 *
 * note: 
 * p. 21 states three entities that are not free-form
 *  - string literals
 *  - #include name
 *  - // comments
 */
#include <iostream>

int
main
(
)
{
    std::cout
    <<
    "Hello world!"
    <<
    std::endl;
    return 0;
}   
