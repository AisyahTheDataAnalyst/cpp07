/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:49:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/12/02 19:41:06 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/*

	✅ Why your .tpp shows errors like “Array<T> not recognized”?
	- Because your VSCode IntelliSense (or CLion, or nvim LSP) is confused — NOT the compiler.
	- Templates in .tpp files almost always show false red errors unless you configure your include order perfectly.

	Array.hpp
	├── template class declaration
	└── #include "Array.tpp"    <-- correct
	Array.tpp
	├── template class definitions
	└── NO include "Array.hpp"

	❗ Why IntelliSense shows red errors even though it’s correct?
		- Because the .tpp file is parsed on its own, without a header context.
		- Your editor does NOT know that .tpp is included inside .hpp.
		➡️ This is ONLY an editor problem, NOT a compiler problem.
		
*/

// ========================================
// 					 OCF 
// ========================================

template<typename T>
Array<T>::Array()
: _arr(new T[0]()), _size(0)
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
	this->_arr = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &other)
: _arr(new T[other.size()]()) , _size(other.size())
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
		this->_arr = new T[other.size()]();
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
T &Array<T>::operator[](size_t index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Index is out of bounds");
	return this->_arr[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return this->_size;
}

#endif