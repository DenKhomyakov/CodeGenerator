#ifndef PLUSPLUSUNIT_H
#define PLUSPLUSUNIT_H

#include "Unit.h"

class PlusPlusClassUnit : public ClassUnit {
public:
    explicit PlusPlusClassUnit( Flags flag, const std::string &name );

    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0 ) const;
};

class PlusPlusMethodUnit : public MethodUnit {
public:
    PlusPlusMethodUnit( const std::string &name, const std::string &returnType,  Unit::Flags flags );

    void add( const std::shared_ptr< Unit >& unit, Flags = 0 );
    std::string compile( unsigned int level = 0 ) const;
};

class PlusPlusPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit PlusPlusPrintOperatorUnit(const std::string &text);

    std::string compile(unsigned int level = 0) const;
};

#endif // PLUSPLUSUNIT_H
