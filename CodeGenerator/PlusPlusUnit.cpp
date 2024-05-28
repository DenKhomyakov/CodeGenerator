#include "PlusPlusUnit.h"

/* CLASS UNIT */

PlusPlusClassUnit::PlusPlusClassUnit( Flags flag, const std::string &name ) : ClassUnit(flag, name) {
    if (flag != 0 && flag >= ACCESS_MODIFIERS_UNIT.size()) {
        modifier = AccessModifierUnit::PRIVATE;
    }
}

void PlusPlusClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    int accessModifier = ClassUnit::PRIVATE;

    if( flags < ACCESS_MODIFIERS_UNIT.size() ) {
        accessModifier = flags;
    }

    m_fields[ accessModifier ].push_back( unit );
}

std::string PlusPlusClassUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level ) + "class " + m_name + " {\n";

    auto it = m_fields.begin();

    while( it != m_fields.end()) {
        if( it->second.empty()) {
            continue;
        }

        result += ACCESS_MODIFIERS_UNIT[ it->first ] + ":\n";

        for( const auto& f : it->second ) {

            result += f->compile( level + 1 );
        }

        result += "\n";
        ++it;
    }

    result += generateShift( level ) + "};\n";
    return result;
}

/* METHOD UNIT */

PlusPlusMethodUnit::PlusPlusMethodUnit( const std::string &name, const std::string &returnType,  Unit::Flags flags ) :
    MethodUnit(name, returnType, flags) {}

void PlusPlusMethodUnit::add( const std::shared_ptr< Unit >& unit, Flags ) {
    m_body.push_back( unit );
}

std::string PlusPlusMethodUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );

    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    } else if( m_flags & CONST ) {
        result += " const";
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

/* PRINT OPERATOR UNIT */

PlusPlusPrintOperatorUnit::PlusPlusPrintOperatorUnit(const std::string &text) : PrintOperatorUnit(text) {}

std::string PlusPlusPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}
