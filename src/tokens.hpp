#ifndef TOKENS_HPP
#define TOKENS_HPP

// Encapsulation for the grammar terminals and IR terminals

#include <cstdint>

namespace BibooTax{

enum class Token : std::uint8_t {
  Skibidi,
  Nerizzler,
  Shiori,
  Gyatt,
  ColonDee,
  BauBau,
  RockRock,
  BibooTax
};

enum class IRToken : std::uint8_t {
  Greater,
  Less,
  Plus,
  Minus,
  Dot,
  Comma,
  LeftBracket,
  RightBracket
};

}

#endif 
