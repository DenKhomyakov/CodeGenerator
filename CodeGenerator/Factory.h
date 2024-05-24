#ifndef FACTORY_H
#define FACTORY_H

#include <string>

class AbstractFactory {
public:
    AbstractFactory() = default;
    virtual std::string generateProgram() = 0;
    virtual ~AbstractFactory() = default;
};

class PlusPlusFactory : public AbstractFactory {
public:
    PlusPlusFactory() = default;
    std::string generateProgram() override;
    ~PlusPlusFactory() = default;
};

class JavaFactory : public AbstractFactory {
public:
    JavaFactory() = default;
    std::string generateProgram() override;
    ~JavaFactory() = default;
};

class SharpFactory : public AbstractFactory {
public:
    SharpFactory() = default;
    std::string generateProgram() override;
    ~SharpFactory() = default;
};

#endif // FACTORY_H
