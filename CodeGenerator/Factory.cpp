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
