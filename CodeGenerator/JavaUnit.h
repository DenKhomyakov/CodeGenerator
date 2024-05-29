#ifndef JAVAUNIT_H
#define JAVAUNIT_H

#include "Unit.h"

class JavaClassUnit : public ClassUnit {
public:
    explicit JavaClassUnit(Flags flag,const std::string& name);

    void add( const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class JavaMethodUnit : public MethodUnit {
public:

    JavaMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags);

    void add( const std::shared_ptr< Unit >& , Flags = 0 );
    std::string compile( unsigned int level = 0 ) const;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text);

    std::string compile( unsigned int level = 0 ) const ;
};

#endif // JAVAUNIT_H
