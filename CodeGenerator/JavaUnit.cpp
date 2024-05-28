#include "JavaUnit.h"

/* CLASS UNIT */

JavaClassUnit::JavaClassUnit(Flags flag, const std::string &name) : ClassUnit(flag, name) {
    if (flag != 0 && flag >= ACCESS_MODIFIERS_UNIT.size()) {
        modifier = AccessModifierUnit::DEFAULT;
    }
}

void JavaClassUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags flags) {
    int accessModifier = ClassUnit::DEFAULT;

    if( flags < ACCESS_MODIFIERS_UNIT.size() ) {
        accessModifier = flags;
    }

    m_fields[ accessModifier ].push_back( unit );
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string_view str(ACCESS_MODIFIERS_UNIT[ modifier]);
    std::string result = generateShift( level ) + str.data() + " class " + m_name + " {\n";

    auto it = m_fields.begin();

    while( it != m_fields.end()) {
        for( const auto& f : it->second ) {
            result += ACCESS_MODIFIERS_UNIT[ it->first ];
            result += f->compile( level + 1 );
        }

        ++it;
    }

    result += generateShift( level ) + "};\n";
    return result;
}

/* METHOD UNIT */

JavaMethodUnit::JavaMethodUnit(const std::string &name, const std::string &returnType,  Unit::Flags flags ) : MethodUnit(name, returnType, flags) {}

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

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string &text) : PrintOperatorUnit(text) {}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}

