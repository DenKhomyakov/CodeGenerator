#include "SharpUnit.h"
#include <string_view>

/* UNIT */

SharpUnit::SharpUnit(Flags flag, const std::string &name) : modifier(flag), m_name(name) {
    if(flag != 0 && flag >= ACCESS_MODIFIERS_UNIT.size()) {
        modifier = AccessModifierUnit::PRIVATE;
    }
}

const std::vector< std::string > SharpUnit::ACCESS_MODIFIERS_UNIT = { "public", "protected", "private", "private protected", "file",
                                                                   "internal", "protected internal", "abstract", "sealed" };


/* CLASS UNIT */

SharpClassUnit::SharpClassUnit(Flags flag ,const std::string& name) : SharpUnit(flag,name) {
    m_fields.resize(ACCESS_MODIFIERS_UNIT.size());
}

void SharpClassUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags flags) {
    if( flags != 0 && flags >= ACCESS_MODIFIERS_UNIT.size() ) {
        flags = AccessModifierUnit::PRIVATE;
    }

    m_fields[ flags ].push_back( unit );
}

std::string SharpClassUnit::compile(unsigned int level) const {
    std::string_view str(ACCESS_MODIFIERS_UNIT[static_cast<int>(modifier)]);
    std::string result = generateShift( level ) + str.data() + " class " + m_name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS_UNIT.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }

        for( const auto& f : m_fields[ i ] ) {
            result += ACCESS_MODIFIERS_UNIT[ i ];
            result += f->compile( level + 1 );
        }

        //result += "\n";
    }

    result += generateShift( level ) + "};\n";
    return result;
}

/* METHOD UNIT */

SharpMethodUnit::SharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) : SharpUnit(flags,name), m_returnType(returnType) {}

void SharpMethodUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags) {
    m_body.push_back(unit);
}

std::string SharpMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift( level );
    result += ACCESS_MODIFIERS_UNIT[modifier] + " ";
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }

    result += generateShift( level ) + "}\n";
    return result;
}

/* PRINT OPERATOR UNIT */

SharpPrintOperatorUnit::SharpPrintOperatorUnit(const std::string &text) : SharpUnit(0, ""), m_text(text) {}

std::string SharpPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}

