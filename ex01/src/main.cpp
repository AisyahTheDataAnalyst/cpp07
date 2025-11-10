/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:36:47 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 19:49:54 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	{
		border("Non-constant template", BLUE);
		
		int a[] 		= {11, 22, 33};
		size_t intArrSize = sizeof(a)/sizeof(a[0]);
		std::string b 	= "bBbB";
		char c[]		= "cccC";  // local array = modifiable
		// char *d 		= "dDdd";  // string literal = cannot ve modifiedconst char * = read-only

		testIterNonConst("INTERGER ARRAY", LIGHT_BLUE, a, intArrSize);
		testIterNonConst("STD::STRING", LIGHT_MAGENTA, &b[0], b.size());
		testIterNonConst("CHAR []", LIGHT_GREEN, c, strlen(c));
	}
	{
		border("Constant template", PURPLE);
		
		const int a[] 		= {11, 22, 33};
		size_t intArrSize	= sizeof(a)/sizeof(a[0]);
		const std::string b = "567";
		const char *c 		= "A0f6";  // string literal = cannot ve modified = const char * = read-only
		// char d[]			= "dDdd";  // local array = modifiable
		
		testIterConst("INTERGER ARRAY", LIGHT_BLUE, a, intArrSize);
		testIterConst("STD::STRING", LIGHT_MAGENTA, &b[0], b.size());
		testIterConst("CHAR []", LIGHT_GREEN, c, strlen(c));
	}
	return 0;
}


// >> OLD MESSY INT MAIN <<
// int main()
// {
// 	{
// 		border("Non-constant template", BLUE);
		
// 		int a[] 		= {11, 22, 33};
// 		size_t intArrSize = sizeof(a)/sizeof(a[0]);
// 		std::string b 	= "bBbB";
// 		char c[]		= "cccC";  // local array = modifiable
// 		char *d 		= "dDdd";  // string literal = cannot ve modifiedconst char * = read-only
		
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
// 		iter(a, 3, printChar);
// 		std::cout << "\nisNotAlpha check: ";
// 		iter(a, 3, charIsAlpha);

// 		nonBorder("ISNOTDIGIT", LIGHT_MAGENTA);
// 		std::cout << "Original values [1]: ";
// 		iter(b, 3, printChar);
// 		std::cout << "\nisNotDigitInt check [1]: ";
// 		iter(b, 3, charIsDigit);
// 		std::cout << "All good!";
// 		std::cout << "\nOriginal values [2]: ";
// 		iter(&c[0], c.size(), printChar);
// 		std::cout << "\nisNotDigitAscii check [2]: ";
// 		iter(&c[0], c.size(), charIsDigit);
// 		std::cout << "All good!";

// 		nonBorder("ISNOTALNUM", LIGHT_GREEN);
// 		std::cout << "Original values: ";
// 		iter(d, strlen(d), printChar);
// 		std::cout << "\nisNotAlnum check: ";
// 		iter(d, strlen(d), charIsAlnum);
// 		std::cout << "All good!" << std::endl;
// 	}
// 	return 0;
// }