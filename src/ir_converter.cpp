#include "ir_converter.hpp"

namespace BibooTax{

void IRConverter::Generate(){
  for(auto& token: m_inputTokens){
    m_outputTokens.push_back(BtToIr(token));
  }
}

} // namespace BibooTax
