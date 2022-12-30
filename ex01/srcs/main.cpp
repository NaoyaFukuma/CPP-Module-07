/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:31:53 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/31 01:22:19 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define N 3

int main( void )
{
    std::cout << "\e[33mtest case 1 char arr\e[m" << std::endl;
    char arr1[] = { 'a', 'b', 'c'};
    iter(arr1, N, &printInfo);


    std::cout << "\e[33mtest case 2 int arr\e[m" << std::endl;
    int arr2[] = { 1, 2, 3, 4, 5 };
    iter(arr2, N, &printInfo);


    std::cout << "\e[33mtest case 3 float arr\e[m" << std::endl;
    float arr3[] = { 1.1, 2.2, 3.3};
    iter(arr3, N, &printInfo);


    std::cout << "\e[33mtest case 4 double arr\e[m" << std::endl;
	double arr4[] = { 1.1, 2.2, 3.3};
    iter(arr4, N, &printInfo);


    std::cout << "\e[33mtest case 5 std::string arr\e[m" << std::endl;
    std::string arr5[] = { "one", "two", "threeeeeeeeeeeeeeeeeeeee"};
    iter(arr5, N, &printInfo);

    return 0;
}
