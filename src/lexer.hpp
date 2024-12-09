#ifndef LEXER_HPP
#define LEXER_HPP

// Lexer shall assume that its input is a contigous array,
// it shall produce an output which is an IR of bf

#include <vector>
#include <cstdint>

#include "tokens.hpp"

namespace BibooTax{

class Lexer{
    struct EOFException{};
  public:
    Lexer(const std::vector<char>& input);
    Lexer(std::vector<char>&& input);

    // ------------------------------------------------------ //
    //  Operational
    // ------------------------------------------------------ //

    [[nodiscard]] char ReadChar();
    void GenerateTokens();

    void DestructiveWriteBinaryInputIR(std::vector<char>&& charbuffer){
      m_input = std::move(charbuffer);
    }
    std::vector<Token>&& DestructiveReadTokens()
    { return std::move(m_tokens); }

  private:
    std::size_t m_cursor;
    std::vector<char> m_input;
    std::vector<Token> m_tokens;    // used as output
};

}

#endif
