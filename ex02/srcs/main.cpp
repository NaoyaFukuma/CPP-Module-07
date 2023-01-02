/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:19:07 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/02 16:36:45 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main()
{
// Construction with no parameter: Creates an empty array.
	std::cout << "test 1 : no parameter constractor" << std::endl;
	{
		Array<int> test1;
	}

/* Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a. */
	{
		std::cout << "\ntest 2 : take unsined int parameter constractor" << std::endl;
		Array<int> test2(1);
		int * a = new int();
		std::cout << test2 << "vs " << *a << std::endl;
		delete a;
	}
/* Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array. */
	std::cout << "\ntest 3 : copy constractor & assignment operator." << std::endl;
	{
		Array<int> test3(5);
		for (int i = 0; i < 5; ++i)
			test3[i] = i * 2;
		std::cout << "src array ----> " << test3 << std::endl;

		Array<int> copy3(test3);
		std::cout << "copy array ---> " << copy3 << std::endl;

		Array<int> assign3(1);
		assign3 = test3;
		Array<int> *tmp3 = NULL;
		tmp3 = &assign3;
		assign3 = *tmp3;
		std::cout << "assignment array ---> " << assign3 << std::endl;

	}

	std::cout << "\ntest 4 : [] operator " << std::endl;
	{
		try
		{
			Array<int> test4(5);
			for (int i = 0; i < 5; ++i)
				test4[i] = i * 2;
			for (int i = 0; i < 6; ++i)
				std::cout << test4[i] << " " << std::flush;
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	Array<int> test5(5);
	std::cout << "\ntest 5 : menber function size() \n --> " << test5.size() << std::endl;
}
