#ifndef IR_CONVERTER_HPP
#define IR_CONVERTER_HPP

//  Converts from the BibooTax token representation to the 
//  BF IR Representation

#include <vector>

#include "tokens.hpp"

namespace BibooTax{

using BtTokenBuffer = std::vector<Token>;
using IrTokenBuffer = std::vector<IRToken>;

constexpr IRToken BtToIr(Token& src){
  switch(src){
    case Token::Skibidi:
      return IRToken::Greater;
    case Token::Nerizzler:
      return IRToken::Less;
    case Token::Shiori:
      return IRToken::Plus;
    case Token::Gyatt:
      return IRToken::Minus;
    case Token::ColonDee:
      return IRToken::Dot;
    case Token::BauBau:
      return IRToken::Comma;
    case Token::RockRock:
      return IRToken::LeftBracket;
    case Token::BibooTax:
      return IRToken::RightBracket;
  }
}

class IRConverter{
  public:
    IRConverter(BtTokenBuffer&& inputTokens)
      : m_inputTokens{std::move(inputTokens)}{}

    void Generate();
    
  private:
    BtTokenBuffer m_inputTokens;
    IrTokenBuffer m_outputTokens;
};

} // namespace BibooTax

#endif
