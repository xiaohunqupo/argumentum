// Copyright (c) 2018, 2019 Marko Mahnič
// License: MPL2. See LICENSE in the root of the project.

#include <cppargparse/argparse-s.h>

#include <algorithm>
#include <gtest/gtest.h>

using namespace argparse;
using namespace testing;

// A negative number looks like a short option.  The parser should detect if the
// argument is really an option or a negative number.  Rules when an argument
// looks like a negative number:
//   - if an option is active the argument is a number
//   - if a positional parameter is expecting an argument and the argument's
//   first digit does not represent a short option, the argument is a number

TEST( NegativeNumberTest, shouldDistinguishNegativeNumbersFromOptions )
{
   auto parser = argument_parser{};
   int i;
   parser.add_argument( i, "--num" ).nargs( 1 );

   auto res = parser.parse_args( { "--num", "-5" } );
   EXPECT_TRUE( static_cast<bool>( res ) );
   EXPECT_EQ( -5, i );
}

TEST( NegativeNumberTest, shouldDistinguishNegativeNumbersFromOptionsInPositionalParams )
{
   auto parser = argument_parser{};
   int i;
   int j;
   parser.add_argument( i, "--num" ).nargs( 1 );
   parser.add_argument( j, "number" ).nargs( 1 );

   auto res = parser.parse_args( { "--num", "-5", "-6" } );
   EXPECT_TRUE( static_cast<bool>( res ) );
   EXPECT_EQ( -5, i );
   EXPECT_EQ( -6, j );
}
