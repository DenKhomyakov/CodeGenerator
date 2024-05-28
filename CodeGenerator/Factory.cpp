#include "Factory.h"
#include "PlusPlusUnit.h"
#include "SharpUnit.h"
#include "JavaUnit.h"

std::shared_ptr<ClassUnit> PlusPlusFactory::createClass(unsigned int flag, const std::string& name) {
    return std::make_shared<PlusPlusClassUnit>(flag, name);
}

std::shared_ptr<MethodUnit> PlusPlusFactory::createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<PlusPlusMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> PlusPlusFactory::createPrintOperator(const std::string& text) {
    return std::make_shared<PlusPlusPrintOperatorUnit>(text);
}

std::shared_ptr<ClassUnit> SharpFactory::createClass(unsigned int flag, const std::string& name) {
    return std::make_shared<SharpClassUnit>(flag, name);
}

std::shared_ptr<MethodUnit> SharpFactory::createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<SharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> SharpFactory::createPrintOperator(const std::string& text) {
    return std::make_shared<SharpPrintOperatorUnit>(text);
}

std::shared_ptr<ClassUnit> JavaFactory::createClass(unsigned int flag, const std::string& name) {
    return std::make_shared<JavaClassUnit>(flag, name);
}

std::shared_ptr<MethodUnit> JavaFactory::createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> JavaFactory::createPrintOperator(const std::string& text) {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}

/*
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

    method->add( std::make_shared< PlusPlusPrintOperatorUnit >( R"(Hello, PlusPlus!\n)" ) );
    myClass.add( method, PlusPlusClassUnit::PROTECTED );

    return myClass.compile();
}

std::string JavaFactory::generateProgram() {
    JavaClassUnit myClass(JavaClassUnit::PUBLIC, "JavaClass" );

    myClass.add(
        std::make_shared <JavaMethodUnit >( "testFunc1", "void", JavaMethodUnit::FINAL | JavaMethodUnit::STATIC ),
        JavaClassUnit::PUBLIC
        );

    myClass.add(
        std::make_shared< JavaMethodUnit >( "testFunc2", "void", JavaMethodUnit::ABSTRACT ),
        JavaClassUnit::PRIVATE
        );

    myClass.add(
        std::make_shared< JavaMethodUnit >( "testFunc3", "void", JavaMethodUnit::VOLATILE),
        JavaClassUnit::PUBLIC
        );

    auto method = std::make_shared< JavaMethodUnit >( "testFunc4", "void", JavaMethodUnit::STATIC );
    method->add( std::make_shared< JavaPrintOperatorUnit >( R"(Hello, Java!\n)" ) );
    myClass.add( method, JavaClassUnit::PROTECTED );

    return myClass.compile();
}

std::string SharpFactory::generateProgram() {
    SharpClassUnit myClass( SharpClassUnit::PUBLIC, "SharpClass" );

    myClass.add(
        std::make_shared< SharpMethodUnit >( "testFunc1", "void", SharpMethodUnit::CONST),
        SharpClassUnit::PUBLIC
        );

    myClass.add(
        std::make_shared< SharpMethodUnit >( "testFunc2", "void", SharpMethodUnit::STATIC ),
        SharpClassUnit::PRIVATE
        );

    myClass.add(
        std::make_shared< SharpMethodUnit >( "testFunc3", "void", SharpMethodUnit::CONST),
        SharpClassUnit::PUBLIC
        );

    auto method = std::make_shared< SharpMethodUnit >( "testFunc4", "void", SharpMethodUnit::STATIC );

    method->add( std::make_shared< SharpPrintOperatorUnit >( R"(Hello, Sharp!\n)" ) );
    myClass.add( method, SharpClassUnit::PROTECTED );

    return myClass.compile();
}
*/
