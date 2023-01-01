/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:23:16 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/31 01:17:08 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <iomanip>
#include <typeinfo>

template <typename T>
void	iter(T *arr, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

template <typename T>
void	printInfo(T &src)
{
	std::cout << "type " << typeid(src).name() << std::endl;
	std::cout << "value " << src << std::endl;
	size_t size = sizeof(src);
	std::cout << "bitset(" << size << "byte)" << std::endl;
	char *char_ptr = reinterpret_cast<char *>(&src);
	for (size_t i = 0; i < size ; ++i)
	{
		std::cout << "\e[3;2m" << std::setw(2) << i + 1 << "th byte:\e[m" << std::flush;
		for (int bit_idx = 7; bit_idx >= 0; --bit_idx)
			std::cout << " " << (*char_ptr >> bit_idx & 1) << std::flush;
		++char_ptr;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

#endif
