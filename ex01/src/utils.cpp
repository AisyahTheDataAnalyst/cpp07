/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:18:01 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 19:31:15 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void border(const std::string &title, const char *colour)
{
	std::cout << colour
	<< "\n\n==============================================================\n"
	<< title << '\n'
	<< "==============================================================\n"
	<< RESET << std::flush; 
}

void nonBorder(const std::string &title, const char *colour)
{
	std::cout << colour << "\n" << title << RESET << std::endl; 
}