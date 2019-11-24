// Copyright (c) 2018, 2019 Marko Mahnič
// License: MPL2. See LICENSE in the root of the project.

#pragma once

#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace helputil {

enum EFlag { KEEPEMPTY = true };

std::vector<std::string_view> splitLines( std::string_view text, bool keepEmpty = false );
bool strHasText( std::string_view line, std::string_view text );
bool strHasTexts( std::string_view line, std::vector<std::string_view> texts );

template<typename P, typename F>
std::string getTestHelp( P&& parser, F&& formatter )
{
   std::stringstream strout;
   formatter.format( parser.getDefinition(), strout );
   return strout.str();
}

}   // namespace helputil