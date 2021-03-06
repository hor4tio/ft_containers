/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:32:49 by allanganoun       #+#    #+#             */
/*   Updated: 2022/04/14 19:32:51 by allanganoun      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int main()
{
	std::cout << "\033[1;35mVector :\033[0m" << std::endl;
	vector_tests();
	std::cout << "\033[1;35mStack :\033[0m" << std::endl;
	stack_tests();
	std::cout << "\033[1;35mMap :\033[0m" << std::endl;
	map_tests();
}
