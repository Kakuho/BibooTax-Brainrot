#ifndef LEXER_HPP
#define LEXER_HPP

// Lexer shall assume that its input is a contigous array,
// it shall produce an output which is an IR of bf

#include <vector>
#include <cstdint>
#include <unordered_set>

#include "tokens.hpp"

namespace BibooTax{

using TokenBuffer = std::vector<Token>;

class Lexer{
    struct EOFException{};
    struct UndefinedSymbolException{};
  public:
    Lexer(const std::vector<char>& input);
    Lexer(std::vector<char>&& input);

    // ------------------------------------------------------ //
    //  Operational
    // ------------------------------------------------------ //

    void Match(char ch);

    [[nodiscard]] char ReadChar();
    void GenerateTokens();

    [[nodiscard]] bool IsWhiteSpace(char ch) const;
    void ParseWhiteSpace();

    void DestructiveWriteBinaryInputIR(std::vector<char>&& charbuffer){
      m_input = std::move(charbuffer);
    }
    std::vector<Token>&& DestructiveReadTokens()
    { return std::move(m_tokens); }

  private:
    std::size_t m_cursor;
    std::vector<char> m_input;
    TokenBuffer m_tokens;    // used as output
};

} // namespace BibooTax

#endif
