/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 06:47:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/02 00:15:42 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

# include <iostream>	//std::cout
# include <string>		//std::string

// >>>SWAP CANNOT OVERWRITE CONSTS<<<
// template <typename T>
// void swap(const T& a, const T& b)
// {
// 	T temp;
	
// 	temp = a;
// 	a = b;
// 	b = temp;
// }

template <typename T>
void swap(T& a, T& b)
{
	T temp;
	
	temp = a;
	a = b;
	b = temp;
}

// no need to make a different version of non-const for max/min
// this version is usable for both const & non-const objs & mix const objs

template <typename Z>
const Z& min(const Z& a, const Z& b)
{
	if (a < b)
		return a;
	return b;
}

template <typename A>
const A& max(const A& a, const A& b)
{
	if (a > b)
		return a;
	return b;
}

#endif