#ifndef SHARPUNIT_H
#define SHARPUNIT_H

#include "Unit.h"

class SharpUnit : public Unit {
public:
    enum AccessModifierUnit {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATEPROTECTED,
        FILE,
        INTERNAL,
        PROTECTEDINTERNAL,
        ABSTRACT,
        SEALED,
        STATIC,
        CONST,
        NOMODIFIER
    };

    static const std::vector< std::string > ACCESS_MODIFIERS_UNIT;

public:
    SharpUnit(Flags mod, const std::string& name);

protected:
    Flags modifier;
    std::string m_name;
};

class SharpClassUnit : public SharpUnit {
public:
    explicit SharpClassUnit(Flags flag, const std::string& name);

    void add( const std::shared_ptr< Unit >& , Flags );
    std::string compile( unsigned int level = 0 ) const;

private:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class SharpMethodUnit : public SharpUnit {
public:
    SharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add( const std::shared_ptr< Unit >& , Flags = 0 ) ;
    std::string compile( unsigned int level = 0 ) const ;

private:
    std::string m_returnType;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class SharpPrintOperatorUnit : public Unit {
public:
    explicit SharpPrintOperatorUnit(const std::string& text);

    std::string compile( unsigned int level = 0 ) const ;

private:
    std::string m_text;
};

#endif // SHARPUNIT_H
