/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 06:47:34 by aimokhta          #+#    #+#             */
/*   Updated: 2025/11/10 09:29:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void border(std::string title, const char *colour)
{
	std::cout 
	<< colour 
	<< "\n==========================================================\n"
	<< title
	<< "\n==========================================================" 
	<< RESET << std::endl;
}

int main()
{
	// >>> !!! SWAP CANNOT OVERWRITE CONSTS !!! <<<
	// {
	// 	border("Swap [const std::string]", CYAN);
	// 	const std::string a = "HELLO";
	// 	const std::string b = "Morning";

	// 	std::cout 
	// 	<< "Before swapping\n"
	// 	<< "a: " << a << '\n'
	// 	<< "b: " << b << '\n';
	// 	swap(a, b);
	// 	std::cout
	// 	<< "After swapping\n"
	// 	<< "a: " << a << '\n' 
	// 	<< "b: " << b << std::endl;
	// }
	
	{
		border("Swap [std::string]", CYAN);
		std::string a = "HELLO";
		std::string b = "Morning";

		std::cout 
		<< "Before swapping\n"
		<< "a: " << a << '\n'
		<< "b: " << b << '\n';
		swap(a, b);
		std::cout
		<< "After swapping\n"
		<< "a: " << a << '\n' 
		<< "b: " << b << std::endl;
	}
	{
		border("Swap [int]", CYAN);
		int a = 33;
		int b = 55;

		std::cout 
		<< "Before swapping\n"
		<< "a: " << a << '\n'
		<< "b: " << b << '\n';
		swap(a, b);
		std::cout
		<< "After swapping\n"
		<< "a: " << a << '\n' 
		<< "b: " << b << std::endl;
	}
	{
		border("Min & Max [int]", PURPLE);
		int a = 100;
		int b = 200;
		std::cout 
		<< "a = " << a << '\n'
		<< "b = " << b << '\n'
		<< "max = " << max(a, b) << '\n'
		<< "min = " << min(a, b) << std::endl; 
	}
	{
		border("Min & Max [const int]", PURPLE);
		const int a = 500;
		const int b = 300;
		std::cout 
		<< "const a = " << a << '\n'
		<< "const b = " << b << '\n'
		<< "max = " << max(a, b) << '\n'
		<< "min = " << min(a, b) << std::endl; 
	}
	{
		border("Min & Max [char]", PURPLE);
		char a = 'a';
		char b = 'z';
		std::cout 
		<< "a = '" << a << "'\n"
		<< "b = '" << b << "'\n"
		<< "max = " << max(a, b) << '\n'
		<< "min = " << min(a, b) << std::endl; 
	}
	{
		border("Min & Max [const char]", PURPLE);
		const char a = '!';
		const char b = '~';
		std::cout 
		<< "const a = '" << a << "'\n"
		<< "const b = '" << b << "'\n"
		<< "max = " << max(a, b) << '\n'
		<< "min = " << min(a, b) << std::endl; 
	}
	return 0;
}