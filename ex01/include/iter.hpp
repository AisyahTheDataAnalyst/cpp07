/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:37:07 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 20:59:43 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// headers
# include <cstddef>		// size_t
# include <cctype>		// std::toupper(), std::tolower(), std::isdigit(), std::isalpha(), std::isalnum()
# include <iostream>	// std::cout, std::cerr, std::flush
# include <cstdlib>		// std::exit()
# include <string>		// std::string
# include <cstring>		// std::strlen()
# include <stdexcept>	// std::runtime_error("")
# include <exception>	// std::exception
# include "utils.hpp"

// colours
# define RED "\033[1;31m"
# define RESET "\033[0m"


//////////////////////////////
//		C O N S T S			//
//////////////////////////////

template <typename T>
void iter (const T *array, const size_t len, void(*function)(const T &))
{
	if (!array || len < 1 || !function)
		return ;
	for (size_t i = 0; i < len; ++i)
	{
		try
		{
			function(array[i]);
		}
		catch (std::exception &errMsg)
		{
			std::cerr << RED << errMsg.what() << '\n' << RESET;
		}
	}
}

template <typename T>
void printChar(const T c)
{
	std::cout << c << " " << std::flush;
}

template <typename T>
void charIsAlpha(const T c)
{
	if (!std::isalpha(static_cast<unsigned char>(c)))
		throw (std::runtime_error("There is a non-alphabet character"));
	std::cout << "All good!\n";
}

template <typename T>
// specifically for checking in string of numbers
void charIsDigit(const T c)
{
	if (!std::isdigit(static_cast<unsigned char>(c)))
		throw (std::runtime_error("There is a non-digit character"));
	std::cout << "All good!\n";
}

template <typename T>
void charIsAlnum(const T c)
{
	if (!std::isalnum(static_cast<unsigned char>(c)))
		throw (std::runtime_error("There is a non-alnum character"));
	std::cout << "All good!\n";
}

template <typename T>
void testIterConst(const std::string &title, const char *colour, const T *array, const size_t len)
{
	nonBorder(title, colour);
	std::cout << colour << "Original values   : ";
	iter(array, len, printChar);
	std::cout  << RESET << "\ncharIsDigit check:\n";
	iter(array, len, charIsDigit);
	std::cout << "\ncharIsAlpha check:\n";
	iter(array, len, charIsAlpha);
	std::cout << "\ncharIsAlnum check:\n";		
	iter(array, len, charIsAlnum);
	std::cout << std::endl;
}


//////////////////////////////////
//		N O N - C O N S T S		//
//////////////////////////////////

template <typename T>
void iter (T *array, size_t len, void(*function)(T &))
{
	if (!array || len < 1 || !function)
		return ;
	for (size_t i = 0; i < len; ++i)
		function(array[i]);
}

// function helpers (changes on non const T)

template <typename T>
void increment(T c)
{
	++c;
}

template <typename T>
void decrement (T c)
{
	--c;
}

template <typename T>
void lowercase(T c)
{
	c = std::tolower(static_cast<unsigned char>(c));
}

/*
	- input is lowercase - toupper() returns the int value corresponding to its uppercase equivalent
	- input is not lowercase letter (e.g., it's already uppercase, a digit, a symbol, or a control character), 
	toupper() returns the int value of the original character unchanged.
*/
template <typename T>
void uppercase(T c)
{
	c = std::toupper(static_cast<unsigned char>(c));
}

template <typename T>
void testIterNonConst(const std::string &title, const char *colour, T *array, size_t len)
{
	nonBorder(title, colour);
	std::cout << colour << "Original values   : ";
	iter(array, len, printChar);
	std::cout  << RESET << "\nIncremented values: ";
	iter(array, len, increment);
	iter(array, len, printChar);
	std::cout << "\nDecremented values: ";
	iter(array, len, decrement);
	iter(array, len, printChar);
	std::cout << "\nLowercasing values: ";		
	iter(array, len, lowercase);
	iter(array, len, printChar);
	std::cout << "\nUppercasing values: ";		
	iter(array, len, uppercase);
	iter(array, len, printChar);
	testIterConst("", colour, array, len);
	std::cout << std::endl;
}

#endif