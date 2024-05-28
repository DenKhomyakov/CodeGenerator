#include "SharpUnit.h"
#include <string_view>

/* CLASS UNIT */

SharpClassUnit::SharpClassUnit(Flags flag ,const std::string& name) : ClassUnit(flag, name) {
    if (flag != 0 && flag >= ACCESS_MODIFIERS_UNIT.size()) {
        modifier = AccessModifierUnit::PRIVATE;
    }
}

void SharpClassUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags flags) {
    int accessModifier = ClassUnit::INTERNAL;

    if( flags != 0 && flags >= ACCESS_MODIFIERS_UNIT.size() ) {
        accessModifier = flags;
    }

    m_fields[ flags ].push_back( unit );
}

std::string SharpClassUnit::compile(unsigned int level) const {
    std::string_view str(ACCESS_MODIFIERS_UNIT[static_cast<int>(modifier)]);
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

SharpMethodUnit::SharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) : MethodUnit(name, returnType, flags) {}

void SharpMethodUnit::add(const std::shared_ptr<Unit> & unit, Unit::Flags) {
    m_body.push_back(unit);
}

std::string SharpMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & CONST) {
        result += " const";
    }

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

/* PRINT OPERATOR UNIT */

SharpPrintOperatorUnit::SharpPrintOperatorUnit(const std::string &text) : PrintOperatorUnit(text) {}

std::string SharpPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}

