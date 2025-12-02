/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:11:19 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/02 11:03:39 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void border(const std::string &title, const char *colour)
{
	std::cout 
	<< colour 
	<< "\n==========================================================\n"
	<< title
	<< "\n==========================================================" 
	<< RESET << std::endl;
}


#include <cstdlib> // std::rand()
int main()
{
	// ==================================================================
	// |                       my own tests								|
	// ==================================================================
	# if 1
	{
		try 
		{
			border("Test 1: Instances Creation", YELLOW);
			// unsigned int n = -5; // 
			// std::cout << "unsigned int = " << n << std::endl;
			std::cout << "hi\n";
			// Array<int> intNegative(-5); // might throws std::bad_alloc
			// // intNegative becomes 4294967291 (on 32-bit unsigned)
			// // UINT_MAX = 4,294,967,295
			std::cout << "hi\n";

			Array<int> intEmpty;
			Array<int> intFive(5);

			Array<std::string> strEmpty;
			Array<std::string> strThree(3);

			std::cout
			<< BLUE << "\nSizes of each instances\n" << RESET
			// << "intInvalid = " << intNegative.size() << '\n'
			<< "intEmpty = " << intEmpty.size() << '\n'
			<< "intFive  = " << intFive.size() << '\n'
			<< "strEmpty = " << strEmpty.size() << '\n'
			<< "strThree = " << strThree.size() << std::endl;
		}
		
		// In practice, new T[n] will throw std::bad_alloc well before you reach SIZE_MAX, 
		// because your system doesn’t have exabytes of RAM.
		// UINT_MAX = 4GB
		// SIZE_MAX = 16EB or 16 exabytes 
		catch (std::bad_alloc &e)
		{
			std::cerr << RED << "Allocation failed: " << e.what() << '\n' << RESET;
		}
		catch (std::exception &errMsg)
		{
			std::cerr << RED << errMsg.what() << '\n' << RESET;
		}
	}
	{
		try
		{
			border("Test 2: Copy Constructor & Copy Assignment Operator", YELLOW);
			
			// ---copy constructor---
			Array<int> intFive(5);
			Array<int> intCopy(intFive);
			
			Array<std::string> strThree(3);
			Array<std::string> strCopy(strThree);
			
			std::cout
			<< RESET_BOLD "Sizes of each instances\n\n" << RESET
			<< GREEN << "[Copy Constructors]\n" << RESET
			<< "intFive           : " << GREEN << intFive.size() << RESET << '\n'
			<< "intCopy(intFive)  : " << GREEN << intCopy.size() << RESET << '\n'
			<< "strThree          : " << GREEN << strThree.size() << RESET << '\n'
			<< "strCopy(strThree) : " << GREEN << strCopy.size() << RESET << '\n' << std::endl;
			
			
			// ---copy assigment operator---
			Array<int> intZero;
			Array<int> intTen(10);
			
			Array<std::string> strZero;
			Array<std::string> strTwelve(12);
				
			std::cout 
			<< BLUE << "[Copy Assignment Operators]\n" << RESET
			<< "intTen              : " << BLUE << intTen.size() << RESET << '\n'
			<< "intZero             : " << BLUE << intZero.size() << RESET << '\n'
			<< "strTwelve           : " << BLUE << strTwelve.size() << RESET << '\n'
			<< "strZero             : " << BLUE << strZero.size() << RESET << '\n';
			
			intZero = intTen;
			strZero = strTwelve;
			
			std::cout
			<< "intZero = intTen    : " << BLUE << intZero.size() << RESET << '\n'
			<< "strZero = strTwelve : " << BLUE << strZero.size() << RESET << std::endl;
			
			// Array<int> intCopyStr(strThree); // compiler didnt allow different T types in copying
			// Array<long> longCopyInt(intFive); // compiler didnt allow different T types in copying
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		try
		{
			border("Test 3: subscript operator [] on non-const instances", YELLOW);
			
			// =============================
			//     non-const std::string 
			// =============================			
			Array<std::string> alpha(3);
			std::cout << CYAN << "std::string object with size 3 created!\n" << RESET << std::endl;
			
			// ---------1st time---------
			std::cout << CYAN << "Overwrited elements in each index, 1st time (a,b,c)\n" << RESET;
			alpha[0] = "a";
			alpha[1] = "b";
			alpha[2] = "c";
			
			for (size_t i = 0; i < alpha.size(); ++i)
				std::cout << "element at index " << i << " = " << CYAN << alpha[i] << RESET << '\n'; 
			std::cout << std::endl;

			// ---------2nd time---------
			std::cout << CYAN << "Overwrited elements in each index, 2nd time (z,y,x)\n" << RESET;
			alpha[0] = "z";
			alpha[1] = "y";
			alpha[2] = "x";
			
			for (size_t i = 0; i < alpha.size(); ++i)
				std::cout << "element at index " << i << " = " << CYAN << alpha[i] << RESET << '\n'; 
			std::cout << std::endl;


			
			// =============================
			//        non-const int 
			// =============================
			Array<int> intArr(3);
			std::cout << GREEN << "int object with size 3 created!\n" << RESET << std::endl;
			
			// ---------1st time---------
			std::cout << GREEN << "Overwrited elements in each index, 1st time\n" << RESET;
			intArr[0] = 1;
			intArr[1] = 22;
			intArr[2] = 333;
			
			for (size_t i = 0; i < intArr.size(); ++i)
				std::cout << "element at index " << i << " = " << GREEN << intArr[i] << RESET << '\n'; 
			std::cout << std::endl;

			// ---------2nd time---------
			std::cout << GREEN << "Overwrited elements in each index, 2nd time\n" << RESET;
			intArr[0] = 246;
			intArr[1] = 369;
			intArr[2] = 4812;
			
			for (size_t i = 0; i < intArr.size(); ++i)
				std::cout << "element at index " << i << " = " << GREEN << intArr[i] << RESET << '\n'; 
			std::cout << std::endl;
			
			size_t indexOOB = 3;
			std::cout << PURPLE << "Testing overwriting on index " << indexOOB << " (out of bound): \n" << RESET;
			alpha[indexOOB] = "g";
			std::cerr << "Should not reach this text, even if using std::cerr\n";
			std::cout << "element at index " << indexOOB << " = " << alpha[indexOOB] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		try
		{
			border("Test 4: subscript operator [] on const instances", YELLOW);
			// =============================
			//            non-const 
			// =============================
			Array<std::string> alpha(3);
			std::cout << CYAN << "non-const std::string object named [alpha] with size 3 created!\n" << RESET << std::endl;
			
			for (size_t i = 0; i < alpha.size(); ++i)
				std::cout << "Reading alpha's element at index " << i << " = (" << CYAN << alpha[i] << RESET << ")\n"; 
			std::cout << std::endl;
						
			std::cout << CYAN << "Overwrited elements in each index of non-const obj (a,b,c)\n" << RESET;
			alpha[0] = "a";
			alpha[1] = "b";
			alpha[2] = "c";
			
			for (size_t i = 0; i < alpha.size(); ++i)
				std::cout << "Reading alpha's element at index " << i << " = (" << CYAN << alpha[i] << RESET << ")\n"; 
			std::cout << std::endl;

			// =============================
			//            const 
			// =============================
			Array<std::string> const constAlpha(alpha);
			std::cout << GREEN << "Copy constructor on [alpha] and create a const std::string object named [constAlpha]\n" << RESET;
			
			// const obj cannot be overwrited
			// std::cout << "Overwrite elements in each index\n" << RESET;
			// constAlpha[0] = "z";
			// constAlpha[1] = "y";
			// constAlpha[2] = "x";
			
			// const obj can be read only
			for (size_t i = 0; i < constAlpha.size(); ++i)
				std::cout << "Reading constAlpha's element at index " << i << " = (" << GREEN << constAlpha[i] << RESET << ")\n"; 
			std::cout << std::endl;

			size_t indexOOB = 3;
			std::cout << PURPLE << "Testing reading on index " << indexOOB << " (out of bound): " << RESET << std::endl;
			std::cout << constAlpha[indexOOB] << '\n';
			std::cerr << "Should not reach this text, even if using std::cerr\n";
			std::cout << "element at index " << indexOOB << " = " << constAlpha[indexOOB] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		
	}
	return 0;
	#endif



	// ===========================================================================
	// |						evaluation sheet's given test                    |
	// ===========================================================================
	#if 0
		#define MAX_VAL 750
		
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
		return 0;
	#endif
}