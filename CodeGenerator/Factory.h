#ifndef FACTORY_H
#define FACTORY_H

#include "Unit.h"
#include "PlusPlusUnit.h"
#include "SharpUnit.h"
#include "JavaUnit.h"
#include <string>

class AbstractFactory {
public:
    AbstractFactory() = default;
    virtual ~AbstractFactory() = default;

    virtual std::shared_ptr<ClassUnit> createClass(unsigned int flag, const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) = 0;
};

class PlusPlusFactory : public AbstractFactory {
public:
    PlusPlusFactory() = default;
    ~PlusPlusFactory() = default;

    std::shared_ptr<ClassUnit> createClass(unsigned int flag, const std::string& name) override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override;

};

class SharpFactory : public AbstractFactory {
public:
    SharpFactory() = default;
    ~SharpFactory() = default;

    std::shared_ptr<ClassUnit> createClass(unsigned int flag, const std::string& name) override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override;
};

class JavaFactory : public AbstractFactory {
public:
    JavaFactory() = default;
    ~JavaFactory() = default;

    std::shared_ptr<ClassUnit> createClass(unsigned int flag, const std::string& name) override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override;
};

#endif // FACTORY_H
