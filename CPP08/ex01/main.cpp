/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:29:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/07 13:39:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	test1(Span &test)
{
	try
	{
		std::cout <<"--- Test1 ---\n\n";
		test.addNumber(6);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		std::cout <<test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test2(Span &test)
{
	try
	{
		std::cout <<"\n--- Test2 ---\n\n";
		test.addRange(2147483000, 2147483647);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
		std::cout << std::endl;

		test.addRange(-2147483648, -2147483647);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
		std::cout << std::endl;

		test.addRange(1, 1000990909090900900);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test3(Span &test)
{
	try
	{
		std::cout <<"\n--- Test3 ---\n\n";
		test.addRange(0, 0);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	Span sp1 = Span(5);
	test1(sp1);

	Span sp2 = Span(30000);
	test2(sp2);

	Span sp3 = Span(500);
	test3(sp3);

	return 0;
}
