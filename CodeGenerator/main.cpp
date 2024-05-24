#include <Factory.h>
#include <iostream>

int main() {
    AbstractFactory* factory;

    factory = new PlusPlusFactory;
    std::cout << factory->generateProgram();

    std::cout << '\n' ;
    std::cout << '\n' ;

    factory = new SharpFactory;
    std::cout << factory->generateProgram();

    std::cout << '\n' ;
    std::cout << '\n' ;

    factory = new JavaFactory;
    std::cout << factory->generateProgram();

    delete factory;
    return 0;
}
