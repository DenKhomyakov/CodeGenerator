#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>

class Unit {
public:
    using Flags = unsigned int;

public:
    Unit(Flags flag, const std::string &name ): modifier(flag), m_name(name) {}
    virtual ~Unit() = default;

    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }

    virtual std::string compile( unsigned int level = 0 ) const = 0;

protected:
    virtual std::string generateShift( unsigned int level ) const {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;

        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }

        return result;
    }

    Flags modifier;
    std::string m_name;
};

class ClassUnit : public Unit {
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
        DEFAULT
    };

    static const std::vector< std::string > ACCESS_MODIFIERS_UNIT;

    ClassUnit(Flags flag, const std::string &name ): Unit(flag,name) {}

protected:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::map< unsigned int, Fields > m_fields;
};

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        VOLATILE = 1 << 5
    };

    MethodUnit(const std::string &name, const std::string &returnType,  Unit::Flags flags): Unit(flags,name), m_returnType(returnType) {}

protected:
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class PrintOperatorUnit : public Unit {
public:
    PrintOperatorUnit(const std::string& text): Unit(0,""), m_text(text) {}

protected:
    std::string m_text;
};




#endif // UNIT_H
