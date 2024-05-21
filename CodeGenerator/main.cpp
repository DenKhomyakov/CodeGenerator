#include "PlusPlusUnit.h"

using namespace std;

std::string generateProgram() {
    PlusPlusClassUnit myClass(PlusPlusClassUnit::PRIVATE, "PlusPlusClass" );

    myClass.add(
        std::make_shared< PlusPlusMethodUnit >( "testFunc1", "void", 0 ),
        PlusPlusClassUnit::PUBLIC
        );

    myClass.add(
        std::make_shared< PlusPlusMethodUnit >( "testFunc2", "void", PlusPlusMethodUnit::STATIC ),
        PlusPlusClassUnit::PRIVATE
        );

    myClass.add(
        std::make_shared< PlusPlusMethodUnit >( "testFunc3", "void", PlusPlusMethodUnit::VIRTUAL | PlusPlusMethodUnit::CONST ),
        PlusPlusClassUnit::PUBLIC
        );

    auto method = std::make_shared< PlusPlusMethodUnit >( "testFunc4", "void", PlusPlusMethodUnit::STATIC );

    method->add( std::make_shared< PlusPlusPrintOperatorUnit >( R"(Hello, Plus!\n)" ) );
    myClass.add( method, PlusPlusClassUnit::PROTECTED );

    return myClass.compile();
}

int main() {
    std::string generatedProgram = generateProgram();
    std::cout << generatedProgram << std::endl;

    return 0;
}
