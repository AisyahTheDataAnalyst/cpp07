/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:37:07 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 16:29:22 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// headers
# include <cstddef>		// size_t
# include <cctype>		// std::toupper(), std::tolower(), std::isdigit(), std::isalpha(), std::isalnum()
# include <iostream>	// std::cout, std::cerr
# include <cstdlib>		// std::exit()
# include <string>		// std::string
# include <cstring>		// std::strlen()
# include <stdexcept>	// std::runtime_error("")
# include <exception>	// std::exception

// colours
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BLACK       "\033[1;30m"
# define WHITE       "\033[1;37m"
# define LIGHT_RED   "\033[0;91m"
# define LIGHT_GREEN "\033[0;92m"
# define LIGHT_YELLOW "\033[0;93m"
# define LIGHT_BLUE  "\033[0;94m"
# define LIGHT_MAGENTA "\033[0;95m"
# define LIGHT_CYAN  "\033[0;96m"
# define GRAY        "\033[0;90m"
# define RESET "\033[0m"
# define RL_CYAN "\001\033[1;36m\002"
# define RL_COLOR "\001\033[0m\002"


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
void uppercase(T c)
{
	c = std::toupper(static_cast<unsigned char>(c));
}

template <typename T>
void lowercase(T c)
{
	c = std::tolower(static_cast<unsigned char>(c));
}

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
		// std::cout << array[i];
		function(array[i]);
	}
}

// function helper (read-only on consts T)

template <typename T>
void printChar(const T c)
{
	std::cout << c << " " << std::flush;
}

template <typename T>
void isNotAlpha(const T c)
{
	if (!std::isalpha(static_cast<unsigned char>(c)))
		throw (std::runtime_error("There is a non-alphabet character"));
}

template <typename T>
// specifically for checking in int * array
void isNotDigitInt(const T c)
{
	if (c < 0 || c > 9)
		throw (std::runtime_error("There is a non-digit int"));
}

template <typename T>
// specifically for checking in string of numbers
void isNotDigitAscii(const T c)
{
	if (!std::isdigit(static_cast<unsigned char>(c)))
		throw (std::runtime_error("There is a non-digit ascii character"));
}

template <typename T>
void isNotAlnum(const T c)
{
	if (!std::isalnum(static_cast<unsigned char>(c)))
		throw (std::runtime_error("There is a non-alnum character"));
}

#endif