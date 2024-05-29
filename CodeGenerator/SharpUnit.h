#ifndef SHARPUNIT_H
#define SHARPUNIT_H

#include "Unit.h"

class SharpClassUnit : public ClassUnit {
public:
    explicit SharpClassUnit(Flags flag, const std::string& name);

    void add( const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class SharpMethodUnit : public MethodUnit {
public:
    SharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags);

    void add( const std::shared_ptr< Unit >& , Flags = 0 ) ;
    std::string compile( unsigned int level = 0 ) const ;
};

class SharpPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit SharpPrintOperatorUnit(const std::string& text);

    std::string compile( unsigned int level = 0 ) const ;
};

#endif // SHARPUNIT_H
