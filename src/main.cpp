//c++
#include <iostream>


int main(){
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    while (true)
    {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit"){
            return 0;
        }else{
            system(input.c_str());
        }

    }

    return 0;
}