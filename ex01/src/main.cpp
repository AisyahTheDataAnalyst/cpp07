/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:36:47 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 16:29:59 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void border(const std::string &title, const char *colour)
{
	std::cout << colour
	<< "\n\n==============================================================\n"
	<< title << '\n'
	<< "=============================================================="
	<< RESET << std::flush; 
}

void nonBorder(const std::string &title, const char *colour)
{
	std::cout << colour << "\n\n" << title << RESET << std::endl; 
}


int main()
{
	{
		border("Non-constant template", BLUE);
		
		int a[] 		= {11, 22, 33};
		int b[]			= {-1, -2, -3};
		std::string c 	= "CcCc";
		// char *d 		= "dDdd";  // string literal = cannot ve modifiedconst char * = read-only
		char d[]		= "dDdd";  // local array = modifiable
		
		nonBorder("INCREMENTING", LIGHT_BLUE);
		std::cout << "Original values: ";
		iter(a, 3, printChar);
		std::cout << "\nIncremented values: ";
		iter(a, 3, increment);
		iter(a, 3, printChar);
		nonBorder("DECREMENTING", LIGHT_MAGENTA);
		std::cout << "Original values: ";
		iter(b, 3, printChar);
		std::cout << "\nDecremented values: ";
		iter(b, 3, decrement);
		iter(b, 3, printChar);
		nonBorder("UPPERCASING", LIGHT_GREEN);
		std::cout << "Original values: ";
		iter(&c[0], c.size(), printChar);
		std::cout << "\nUppercased values: ";
		iter(&c[0], c.size(), uppercase);
		iter(&c[0], c.size(), printChar);
		nonBorder("LOWERCASING", LIGHT_YELLOW);
		std::cout << "Original values: ";
		iter(d, std::strlen(d), printChar);
		std::cout << "\nLowercased values: ";
		iter(d, std::strlen(d), lowercase);
		iter(d, std::strlen(d), printChar);
		std::cout << std::endl;
	}
	{
		border("Constant template", PURPLE);
		
		const int a[] 		= {11, 22, 33};
		const int b[]		= {1, 2, 3};
		const std::string c = "567";
		const char *d 		= "A0f6";  // string literal = cannot ve modified = const char * = read-only
		// char d[]			= "dDdd";  // local array = modifiable
		
		try
		{
			nonBorder("ISNOTALPHA", LIGHT_BLUE);
			std::cout << "Original values: ";
			iter(a, 3, printChar);
			std::cout << "\nisNotAlpha check: ";
			iter(a, 3, isNotAlpha);
			std::cout << "All good!";
		}
		catch (std::exception &errMsg) 
		{
			std::cerr << errMsg.what();
		}

		try
		{
			nonBorder("ISNOTDIGIT", LIGHT_MAGENTA);
			std::cout << "Original values [1]: ";
			iter(b, 3, printChar);
			std::cout << "\nisNotDigitInt check [1]: ";
			iter(b, 3, isNotDigitInt);
			std::cout << "All good!";
			std::cout << "\nOriginal values [2]: ";
			iter(&c[0], c.size(), printChar);
			std::cout << "\nisNotDigitAscii check [2]: ";
			iter(&c[0], c.size(), isNotDigitAscii);
			std::cout << "All good!";
		}
		catch (std::exception &errMsg)
		{
			std::cerr << errMsg.what() << '\n';	
		}
		
		try
		{
			nonBorder("ISNOTALNUM", LIGHT_GREEN);
			std::cout << "Original values: ";
			iter(d, strlen(d), printChar);
			std::cout << "\nisNotAlnum check: ";
			iter(d, strlen(d), isNotAlnum);
			std::cout << "All good!" << std::endl;
		}
		catch (std::exception &errMsg)
		{
			std::cerr << errMsg.what() << '\n';
		}
	}
	return 0;
}