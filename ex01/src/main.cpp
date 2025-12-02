/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:36:47 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/02 11:48:42 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


// ==================================================================
// |                       my own tests								|
// ==================================================================
#if 1
int main()
{
	{
		border("Non-constant template", YELLOW);
		
		int a[] 		= {1, 5, 7};
		size_t intArrSize = sizeof(a)/sizeof(a[0]);
		std::string b 	= "567";
		char c[]		= "A0f6";  // local array = modifiable
		// char *d 		= "dDdd";  
		
		// char * is not allowed to modify
		// - char* (modifiable pointer) ⇒ means “I promise I will modify this memory”.
		// - read-only memory (string literal) (the quoted text) = String literal ⇒ stored in read-only segment
		// - compiler warns coz to prevent accidental modification of read-only memory.

		// char [] is allowed in C++98 to modify
		// - this creates a new modifiable array and copies the characters from the string literal into it:
		// - "dDdd" is stored in read-only memory
		// - char d[] allocates a writable array on the stack: {'d','D','d','d','\0'}
		// - The literal is copied into the new array	

		testIterNonConst("INTERGER ARRAY", LIGHT_BLUE, a, intArrSize);
		testIterNonConst("STD::STRING", LIGHT_MAGENTA, &b[0], b.size());  // &b[0] -> char *. std::string is an obj, making it into char * makes it as a raw array
		testIterNonConst("CHAR []", LIGHT_GREEN, c, strlen(c));
		// testIterNonConst("CHAR *", LIGHT_GREEN, d, strlen(d));
	}
	{
		border("Constant template", YELLOW);
		
		const int a[] 		= {1, 5, 7};
		size_t intArrSize	= sizeof(a)/sizeof(a[0]);
		const std::string b = "567";
		const char *c 		= "A0f6";  // string literal = cannot be modified = const char * = read-only
		char d[]			= "dDdd";  // local array = modifiable
		
		testIterConst("CONST INTERGER ARRAY", LIGHT_BLUE, a, intArrSize);
		testIterConst("CONST STD::STRING", LIGHT_MAGENTA, b.c_str(), b.size()); // b.c_str() -> const char *. std::string is an obj, making it into const char * makes it as a raw array
		testIterConst("CONST CHAR *", LIGHT_GREEN, c, strlen(c));
		testIterConst("CHAR []", LIGHT_GREEN, d, strlen(d));
	}
	return 0;
}
#endif




// ===========================================================================
// |						evaluation sheet's given test                    |
// ===========================================================================
#if 0
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

/*
Expected answer:
0
1
2
3
4
42
42
42
42
42
*/

#endif






// // >> OLD MESSY INT MAIN <<
// int main()
// {
// 	{
// 		border("Non-constant template", BLUE);
		
// 		int a[] 		= {11, 22, 33};
// 		size_t intArrSize = sizeof(a)/sizeof(a[0]);
// 		std::string b 	= "bBbB";
// 		char c[]		= "cccC";  // local array = modifiable
// 		// char *d 		= "dDdd";  // string literal = cannot ve modifiedconst char * = read-only
		
// 		nonBorder("INTERGER ARRAY", LIGHT_BLUE);
// 		std::cout << "Original values   : ";
// 		iter(a, intArrSize, printChar);
// 		std::cout << "\nIncremented values: ";
// 		iter(a, intArrSize, increment);
// 		iter(a, intArrSize, printChar);
// 		std::cout << "\nDecremented values: ";
// 		iter(a, intArrSize, decrement);
// 		iter(a, intArrSize, printChar);
// 		std::cout << "\nLowercasing values: ";		
// 		iter(a, intArrSize, lowercase);
// 		iter(a, intArrSize, printChar);
// 		std::cout << "\nUppercasing values: ";		
// 		iter(a, intArrSize, uppercase);
// 		iter(a, intArrSize, printChar);
// 		std::cout << std::endl;

// 		nonBorder("STD::STRING", LIGHT_MAGENTA);
// 		std::cout << "Original values   : ";
// 		iter(&b[0], b.size(), printChar);
// 		std::cout << "\nIncremented values: ";
// 		iter(&b[0], b.size(), increment);
// 		iter(&b[0], b.size(), printChar);
// 		std::cout << "\nDecremented values: ";
// 		iter(&b[0], b.size(), decrement);
// 		iter(&b[0], b.size(), printChar);
// 		std::cout << "\nLowercasing values: ";		
// 		iter(&b[0], b.size(), lowercase);
// 		iter(&b[0], b.size(), printChar);
// 		std::cout << "\nUppercasing values: ";		
// 		iter(&b[0], b.size(), uppercase);
// 		iter(&b[0], b.size(), printChar);
// 		std::cout << std::endl;

// 		nonBorder("CHAR []", LIGHT_GREEN);
// 		std::cout << "Original values   : ";
// 		iter(c, strlen(c), printChar);
// 		std::cout << "\nIncremented values: ";
// 		iter(c, strlen(c), increment);
// 		iter(c, strlen(c), printChar);
// 		std::cout << "\nDecremented values: ";
// 		iter(c, strlen(c), decrement);
// 		iter(c, strlen(c), printChar);
// 		std::cout << "\nLowercasing values: ";		
// 		iter(c, strlen(c), lowercase);
// 		iter(c, strlen(c), printChar);
// 		std::cout << "\nUppercasing values: ";		
// 		iter(c, strlen(c), uppercase);
// 		iter(c, strlen(c), printChar);
// 		std::cout << std::endl;
// 	}
// 	{
// 		border("Constant template", PURPLE);
		
// 		const int a[] 		= {11, 22, 33};
// 		size_t intArrSize	= sizeof(a)/sizeof(a[0]);
// 		const std::string b = "567";
// 		const char *c 		= "A0f6";  // string literal = cannot ve modified = const char * = read-only
// 		// char d[]			= "dDdd";  // local array = modifiable

// 		nonBorder("ISNOTALPHA", LIGHT_BLUE);
// 		std::cout << "Original values: ";
// 		iter(a, intArrSize, printChar);
// 		std::cout << "\nisNotAlpha check: ";
// 		iter(a, intArrSize, charIsAlpha);

// 		nonBorder("ISNOTDIGIT", LIGHT_MAGENTA);
// 		std::cout << "Original values [1]: ";
// 		iter(&b[0], b.size(), printChar);
// 		std::cout << "\nisNotDigitInt check [1]: ";
// 		iter(&b[0], b.size(), charIsDigit);
// 		std::cout << "All good!";

// 		nonBorder("ISNOTALNUM", LIGHT_GREEN);
// 		std::cout << "Original values: ";
// 		iter(c, strlen(c), printChar);
// 		std::cout << "\nisNotAlnum check: ";
// 		iter(c, strlen(c), charIsAlnum);
// 		std::cout << "All good!" << std::endl;
// 	}
// 	return 0;
// }