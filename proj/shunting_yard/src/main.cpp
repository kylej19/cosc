#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>

#include "adhoc.h"

int main()
{
  struct sOperator
  {
    uint8_t precedence = 0;
    uint8_t arguments = 0;
  };

  std::unordered_map<char, sOperator> mapOps;
  mapOps['/'] = { 4, 2 };
  mapOps['*'] = { 3, 2 };
  mapOps['+'] = { 2, 2 };
  mapOps['-'] = { 1, 2 };

  std::string sExpression = "1+2*4-3";

  struct sSymbols
  {
    std::string symbol "";

    enum class Type : uint8_t
      {
	Unknown,
	Literal_Numeric,
	Operator,
      } type = Type::unknown;

    sOperator op;
  };

  std::deque<sSymbol> stkHolding;
  std::deque<sSymbol> stkOutput;

  for (const char c : sExpression)
    {
      if (std::isdigit(c))
	{
	  // push literals straight to output, they are already in order
	  stkOutput.push_back({ std::string(1,c),sSymbol::Type::Literal_Numeric });
	}
      else if (mapOps.contains(c))
	{
	  // symbol is operator
	  const auto& new_op = mapOps[c];

	  while (!stkHolding.empty())
	    {
	      // ensure holding stack front is an operator (it might not be later...)
	      if (stkHolding.front().type == sSymbol::Type::Operator)
		{
		  const auto& holding_stack_op = stkHolding.front().op;

		  if (holding_stack_op.precedence >= new_op.precedence)
		    {
		      stkOutput.push_back(stkHolding.front());
		      stkHolding.pop_front();
		    }
		  else
		    break;
		}
	    }

	  // push the new operator onto the holding stack
	  stkHolding.push_front({ std::string(1,c), sSymbol::Type::Operator, new_op });
	}
      else
	{
	  std::cout << "Bad Symbol: '" << std::string(1, c) << "'\n";
	  return 0;
	} 
    }

  return 0;
}
