#include <Factory.h>
#include <iostream>

std::string generateProgram(AbstractFactory* factory, const std::string name) {
    std::shared_ptr<ClassUnit> myClass = factory->createClass(ClassUnit::PRIVATE, name);
    myClass->add(factory->createMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(factory->createMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
    myClass->add(factory->createMethod("testFunc3", "void", MethodUnit::VIRTUAL), ClassUnit::PUBLIC);

    auto method = factory->createMethod("testFunc4", "void", 0);
    method->add(factory->createPrintOperator(R"(Hello, Class!\n)"), ClassUnit::PROTECTED);
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main() {
    AbstractFactory* factory;

    factory = new PlusPlusFactory;
    std::cout << generateProgram(factory, "PlusPlus");

    std::cout << std::endl;
    std::cout << std::endl;

    factory = new SharpFactory;
    std::cout << generateProgram(factory, "Sharp");

    std::cout << std::endl;
    std::cout << std::endl;

    factory = new JavaFactory;
    std::cout << generateProgram(factory, "Java");

    delete factory;
    return 0;
}
