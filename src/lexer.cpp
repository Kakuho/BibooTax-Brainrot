#include "lexer.hpp"

namespace BibooTax{

Lexer::Lexer(const std::vector<char>& input):
  m_cursor{0},
  m_input{input}
{
  m_tokens.reserve(1000);
}

Lexer::Lexer(std::vector<char>&& input):
  m_cursor{0},
  m_input{std::move(input)}
{
  m_tokens.reserve(1000);
}

//------------------------------------------------------ //
//  Lexer Operations
//------------------------------------------------------ //

[[nodiscard]] char Lexer::ReadChar(){
  if(m_cursor < m_input.size()){
    return m_input[m_cursor++];
  }
  throw EOFException{};
}

void Lexer::GenerateTokens(){
  while(m_cursor < m_input.size()){
  }
}

}
