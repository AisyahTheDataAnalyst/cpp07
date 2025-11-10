/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:11:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 10:31:04 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>	// std::exception
# include <string>		// std::string
# include <iostream>	// std::cout

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

class Array
{
	private:
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		Array &operator[](const Array &other);
		~Array();
		size_t size() const;
		class OutOfBoundsException : public std::exception
		{
			public:
				char const *what() const;	
		};
};

#endif