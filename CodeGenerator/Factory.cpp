#include "Factory.h"
#include "PlusPlusUnit.h"
#include "SharpUnit.h"
#include "JavaUnit.h"

std::string PlusPlusFactory::generateProgram() {
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

std::string JavaFactory::generateProgram() {
    JavaClassUnit myClass(JavaClassUnit::PRIVATE, "JavaClass" );

    myClass.add(
        std::make_shared <JavaMethodUnit >( "testFunc1", "void", JavaMethodUnit::FINAL | JavaMethodUnit::STATIC ),
        JavaUnit::PUBLIC
        );

    myClass.add(
        std::make_shared< JavaMethodUnit >( "testFunc2", "void", JavaMethodUnit::ABSTRACT ),
        JavaUnit::PRIVATE
        );

    myClass.add(
        std::make_shared< JavaMethodUnit >( "testFunc3", "void", JavaMethodUnit::VOLATILE),
        JavaUnit::PROTECTED
        );

    auto method = std::make_shared< JavaMethodUnit >( "testFunc4", "void", JavaMethodUnit::STATIC );
    method->add( std::make_shared< JavaPrintOperatorUnit >( R"(Hello, Java!\n)" ) );
    myClass.add( method, JavaMethodUnit::PROTECTED );

    return myClass.compile();
}

std::string SharpFactory::generateProgram() {
    SharpClassUnit myClass( SharpUnit::PRIVATE, "SharpClass" );

    myClass.add(
        std::make_shared< SharpMethodUnit >( "testFunc1", "void", SharpMethodUnit::CONST),
        SharpUnit::PUBLIC
        );

    myClass.add(
        std::make_shared< SharpMethodUnit >( "testFunc2", "void", SharpMethodUnit::STATIC ),
        SharpUnit::PRIVATE
        );

    myClass.add(
        std::make_shared< SharpMethodUnit >( "testFunc3", "void", SharpMethodUnit::CONST),
        SharpUnit::PUBLIC
        );

    auto method = std::make_shared< SharpMethodUnit >( "testFunc4", "void", SharpMethodUnit::STATIC );

    method->add( std::make_shared< SharpPrintOperatorUnit >( R"(Hello, Sharp!\n)" ) );
    myClass.add( method, SharpUnit::PROTECTED );

    return myClass.compile();
}
