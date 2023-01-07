/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:08:32 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/07 23:32:53 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int a = 2;
	int b = 3;

	std::cout << "\n\e[32mThis exercise concerns template functions.\e[m\n" << std::endl;
	std::cout << "for example....\ntemplate <typename T>\nvoid	swap(T &a, T &b);\n\n" << std::endl;
	std::cout << "test1: type \"int\" " << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "swap!!!\na = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;


	std::cout << "\n\ntest2: type \"string\" " << std::endl;
	std::string c = "str1";
	std::string d = "str2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "swap!!!\nc = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return (0);
}
