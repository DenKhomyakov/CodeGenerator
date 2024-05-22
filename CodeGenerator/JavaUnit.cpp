#include "JavaUnit.h"

/* UNIT */

JavaUnit::JavaUnit(Flags mod, const std::string &name) : modifier(mod), m_name(name) {
    if(modifier != 0 && modifier >= ACCESS_MODIFIERS_UNIT.size()) {
        modifier = AccessModifierUnit::DEFAULT;
    }
}

const std::vector< std::string > JavaUnit::ACCESS_MODIFIERS_UNIT = {"public", "protected", "private", ""};

/* CLASS UNIT */

JavaClassUnit::JavaClassUnit(Flags flag, const std::string &name) : JavaUnit(flag, name) {
    m_fields.resize(ACCESS_MODIFIERS_UNIT.size());
}

void JavaClassUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags flags) {
    int accessModifier = PRIVATE;

    if( flags < ACCESS_MODIFIERS_UNIT.size() ) {
        accessModifier = flags;
    }

    m_fields[ accessModifier ].push_back( unit );
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string_view str(ACCESS_MODIFIERS_UNIT[ modifier]);
    std::string result = generateShift( level ) + str.data() + " class " + m_name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS_UNIT.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }

        for( const auto& f : m_fields[ i ] ) {
            result += ACCESS_MODIFIERS_UNIT[ i ];
            result += f->compile( level + 1 );

        }

        // result += "\n";
    }

    result += generateShift( level ) + "};\n";
    return result;
}

/* METHOD UNIT */

JavaMethodUnit::JavaMethodUnit(const std::string &name, const std::string &returnType,  Unit::Flags flags ) : JavaUnit(flags, name),m_returnType(returnType) {}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift( level );

    if (modifier & FINAL) {
        result += "final ";
    } if (modifier & STATIC) {
        result += "static ";
    } else if ( modifier & ABSTRACT) {
        result += "abstract ";
    } else if (modifier & VOLATILE) {
        result += "volatile ";
    }

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }

    result += generateShift( level ) + "}\n";
    return result;
}

void JavaMethodUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags) {
    m_body.push_back(unit);
}

/* PRINT OPERATOR UNIT */

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string &text) : m_text(text) {}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}

