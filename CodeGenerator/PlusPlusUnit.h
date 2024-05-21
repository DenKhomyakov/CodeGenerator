#ifndef PLUSPLUSUNIT_H
#define PLUSPLUSUNIT_H

#include "Unit.h"

class PlusPlusUnit : public Unit {
public:
    enum AccessModifierUnit {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const std::vector< std::string > ACCESS_MODIFIERS_UNIT;

    PlusPlusUnit(Flags mod, const std::string& name);

protected:
    Flags modifier;
    std::string m_name;
};

class PlusPlusClassUnit : public PlusPlusUnit {
public:
    explicit PlusPlusClassUnit( Flags flag, const std::string &name );

    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0 ) const;

private:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class PlusPlusMethodUnit : public PlusPlusUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

    PlusPlusMethodUnit( const std::string &name, const std::string &returnType,  Unit::Flags flags );

    void add( const std::shared_ptr< Unit >& unit, Flags = 0 );
    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class PlusPlusPrintOperatorUnit : public Unit {
public:
    explicit PlusPlusPrintOperatorUnit(const std::string &text);

    std::string compile(unsigned int level = 0) const;

private:
    std::string m_text;

};

#endif // PLUSPLUSUNIT_H
