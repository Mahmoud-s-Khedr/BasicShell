//c++
#include <iostream>
//c
#include <unistd.h>
int main(){
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    while (true)
    {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        if(input.substr(0,4) == "echo"){
            system(input.c_str());
        }
        else if (input == "exit"){
            std::cout<<"Goodbye\n";
            return 0;
        }else{
            std::cout<<"Command not found\n";
        }

    }

    return 0;
}