/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:17:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 20:47:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

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

# include <iostream>	//std::cerr, std::cout, std::flush
# include <string>		//std::string

void border(const std::string &title, const char *colour);
void nonBorder(const std::string &title, const char *colour);

#endif