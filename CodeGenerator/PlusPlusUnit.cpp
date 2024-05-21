#include "PlusPlusUnit.h"

/* UNIT */

PlusPlusUnit::PlusPlusUnit(Flags mod, const std::string& name) : modifier(mod), m_name(name) {
    if(modifier != 0 && modifier >= ACCESS_MODIFIERS_UNIT.size()) {
        modifier = AccessModifierUnit::PROTECTED;
    }
}

const std::vector< std::string > PlusPlusUnit::ACCESS_MODIFIERS_UNIT = { "public", "protected", "private" };

/* CLASS UNIT */

PlusPlusClassUnit::PlusPlusClassUnit( Flags flag, const std::string &name ) : PlusPlusUnit(flag, name) {
    m_fields.resize( ACCESS_MODIFIERS_UNIT.size() );
}

void PlusPlusClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    int accessModifier = PRIVATE;

    if( flags < ACCESS_MODIFIERS_UNIT.size() ) {
        accessModifier = flags;
    }

    m_fields[ accessModifier ].push_back( unit );
}

std::string PlusPlusClassUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level ) + "class " + m_name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS_UNIT.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }

        result += ACCESS_MODIFIERS_UNIT[ i ] + ":\n";

        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }

        result += "\n";
    }

    result += generateShift( level ) + "};\n";
    return result;
}

/* METHOD UNIT */

PlusPlusMethodUnit::PlusPlusMethodUnit( const std::string &name, const std::string &returnType,  Unit::Flags flags ) :
   PlusPlusUnit(flags, name), m_returnType( returnType ) {}

void PlusPlusMethodUnit::add( const std::shared_ptr< Unit >& unit, Flags ) {
    m_body.push_back( unit );
}

std::string PlusPlusMethodUnit::compile( unsigned int level ) const {
    std::string result = generateShift( level );

    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }

    result += m_returnType + " ";
    result += m_name + "()";

    if( m_flags & CONST ) {
        result += " const";
    }

    result += " {\n";

    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }

    result += generateShift( level ) + "}\n";
    return result;
}

/* PRINT OPERATOR UNIT */

PlusPlusPrintOperatorUnit::PlusPlusPrintOperatorUnit(const std::string &text) : m_text(text) {}

std::string PlusPlusPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}








































