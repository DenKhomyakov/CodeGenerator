#ifndef JAVAUNIT_H
#define JAVAUNIT_H

#include "Unit.h"

class JavaUnit : public Unit {
public:
    enum AccessModifierUnit {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT,
    };

    static const std::vector< std::string > ACCESS_MODIFIERS_UNIT;

public:
    JavaUnit(Flags mod, const std::string& name);

protected:
    Flags modifier;
    std::string m_name;
};

class JavaClassUnit : public JavaUnit {
public:
    explicit JavaClassUnit(Flags flag,const std::string& name);

    virtual void add( const std::shared_ptr< Unit >& , Flags ) override;
    virtual std::string compile( unsigned int level = 0 ) const  override;

private:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class JavaMethodUnit : public JavaUnit {
public:
    enum Modifier{
        STATIC = 1 << 1,
        FINAL = 1 << 2,
        ABSTRACT = 1 << 3,
        VOLATILE = 1 << 4
    };

    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add( const std::shared_ptr< Unit >& , Flags = 0 );
    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_returnType;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class JavaPrintOperatorUnit : public Unit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text);

    std::string compile( unsigned int level = 0 ) const ;

private:
    std::string m_text;
};

#endif // JAVAUNIT_H
