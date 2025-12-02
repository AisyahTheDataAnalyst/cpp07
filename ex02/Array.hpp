/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:11:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/02 10:55:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>	// std::exception
# include <stdexcept>	// std::runtime_error(""), std::out_of_range(""), std::length_error("")
# include <string>		// std::string
# include <iostream>	// std::cout
# include <climits>		// SIZE_MAX
# include <stdint.h>		// uint64_t

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
# define RESET_BOLD "\033[1m"
# define RL_CYAN "\001\033[1;36m\002"
# define RL_COLOR "\001\033[0m\002"

template <typename T>
class Array
{
	private:
		T 		*_arr;
		size_t	_size;
	
	public:
		// OCF
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array<T> &operator=(const Array<T> &other);
		~Array();
		
		// methods
		T &operator[](size_t index);
		const T &operator[](size_t index) const;
		size_t size() const;
		// void setElement(size_t index, T element);
};

// ========================================
// 					 OCF 
// ========================================

template<typename T>
Array<T>::Array()
: _arr(new T[0]), _size(0)
{}

// unsigned int (32-bit on most systems).
// uint64_t (guaranteed 64-bit, portable across platforms) -> prevents overflow
// unsigned long is unsafe:
	// 32-bit Windows (LLP32)		32 bits
	// 64-bit Windows (LLP64)		32 bits
	// 64-bit Linux / macOS (LP64)	64 bits
// size_t is portable, 32bits in 32bit system / 64bits in 64bit system, unisgned int can write into it
// we compare bytes trying to be allocated with SIZE_MAX
	// coz internally [new] uses size_t to store the allocation size.
// Comparing to UINT_MAX is wrong on 64-bit systems, 
	// because UINT_MAX is smaller than the maximum memory the system can actually address.
template<typename T>
Array<T>::Array(unsigned int n)
{
	if (static_cast<uint64_t>(n) * sizeof(T) > SIZE_MAX)
		throw std::length_error("Size is too big for type T");
	this->_arr = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &other)
: _arr(new T[other.size()]) , _size(other.size())
{
	if (this->_size)
		for (size_t i = 0; i < this->_size; ++i)
			this->_arr[i] = other._arr[i];
}

// no need to do a const obj version, system&compiler will give error even before compiling
// name: subscript operator
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete [] this->_arr;
		this->_arr = new T[other.size()];
		this->_size = other.size();

		if (this->_size)
			for (size_t i = 0; i < this->_size; ++i)
				this->_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_arr;
}


// ========================================
// 					 METHODS 
// ========================================

// with template, we will not care about accessing the null terminator,
// not anymore in C++ since we have a lot of helpful member functions like str.size() / str.length()
// so use the size to indicate index validity
template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (!this->_size)
		throw std::out_of_range("This array is empty with size of 0");
	if (index >= this->_size)
		throw std::out_of_range("Index is out of bounds");
	return this->_arr[index];
}

// return type forces that the char/int returned in immodifyable
template <typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (!this->_size)
		throw std::out_of_range("This array is empty with size of 0");
	if (index >= this->_size)
		throw std::out_of_range("Index is out of bounds");
	return this->_arr[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return this->_size;
}

// template <typename T>
// void Array<T>::setElement(size_t index, T element)
// {
// 	if (!this->_size)
// 		throw std::out_of_range("This array is empty with size of 0");
// 	if (index >= this->_size)
// 		throw std::out_of_range("Index is out of bounds");
// 	this->_array[index] = element;
// }
#endif