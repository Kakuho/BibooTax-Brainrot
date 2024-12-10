#include "lexer.hpp"
#include <unordered_set>

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

void Lexer::Match(char ch){
  if(m_input[m_cursor] != ch){
    throw UndefinedSymbolException{};
  }
  else{
    m_cursor++;
  }
}

[[nodiscard]] char Lexer::ReadChar(){
  if(m_cursor < m_input.size()){
    return m_input[m_cursor++];
  }
  throw EOFException{};
}

void Lexer::GenerateTokens(){
  while(m_cursor < m_input.size()){
    char ch = ReadChar();
    if(IsWhiteSpace(ch)){
      ParseWhiteSpace();
      continue;
    }
    switch(ch){
      case 's':
        {
          Match('s');
            char ch2 = ReadChar();
            switch(ch2){
              case 'k':
                Match('k'); Match('i'); Match('b'); Match('i'); 
                Match('d'); Match('i');
                m_tokens.push_back(Token::Skibidi);
                break;
              case 'h':
                Match('h'); Match('i'); Match('o'); Match('r'); 
                Match('i');

                m_tokens.push_back(Token::Shiori);
                break;
              default:
                throw UndefinedSymbolException{};
            }
        }
        break;

      case 'n':
        Match('n'); Match('e'); Match('r'); Match('i'); 
        Match('z'); Match('z'); Match('l'); Match('e');
        Match('r');
        m_tokens.push_back(Token::Nerizzler);
        break;
      case 'g':
        Match('g'); Match('y'); Match('a'); Match('t'); 
        Match('t');
        m_tokens.push_back(Token::Gyatt);
        break;
      case ':':
        Match(':'); Match('D'); 
        m_tokens.push_back(Token::ColonDee);
        break;
      case 'b':
        {
          Match('b');
            char ch2 = ReadChar();
            switch(ch2){
              case 'a':
                Match('a'); Match('u'); Match('b'); Match('a'); 
                Match('u');
                m_tokens.push_back(Token::BauBau);
                break;
              case 'i':
                Match('b'); Match('o'); Match('o'); Match('t'); 
                Match('a'); Match('x');
                m_tokens.push_back(Token::BibooTax);
                break;
              default:
                throw UndefinedSymbolException{};
            }
        }
        break;
      case 'r':
        Match('o'); Match('c'); Match('k'); Match('r'); 
        Match('o'); Match('c'); Match('k');
        m_tokens.push_back(Token::RockRock);
        break;
      default:
        throw UndefinedSymbolException{};
    }
  }
}

void Lexer::ParseWhiteSpace(){
  static std::unordered_set<char> whitespaceLUT;
  while(whitespaceLUT.contains(m_input[m_cursor])){
    m_cursor++;
  }
}

} // namespace BibooTax
