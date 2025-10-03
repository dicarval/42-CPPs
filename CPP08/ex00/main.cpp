/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:41:18 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 17:35:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void for_loop_v(std::vector<int> &c)
{
	for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}

void for_loop_l(std::list<int> &l)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}


void	test_1(std::vector<int> &cont)
{
	try
	{
		std::cout << "--- test 1 ---\n\n";

		for_loop_v(cont);

		std::vector<int>::iterator found = easyfind(cont, 21);
		std::cout << "found: " << *found << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "easyfind: value " << e.what() << " not found"<< std::endl;
	}
}

void	test_2(const std::vector<int> &block)
{
	try
	{
		std::cout << "\n--- test 2 ---\n\n";

		for (std::vector<int>::const_iterator it = block.begin(); it != block.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << std::endl;
		std::vector<int>::const_iterator found = easyfind(block, 22);
		std::cout << "found: " << *found << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "easyfind: value " << e.what() << " not found"<< std::endl;
	}
}

void	test_3(std::vector<int> &meh)
{
	try
	{
		std::cout << "\n--- test 3 ---\n\n";
		for_loop_v(meh);
		meh.erase(meh.end() - 1);
		for_loop_v(meh);
		meh.insert((meh.begin() + 1), 43);
		for_loop_v(meh);
		meh.assign(2, 53);
		for_loop_v(meh);
		meh.push_back(93);
		for_loop_v(meh);
		std::vector<int>::iterator found = easyfind(meh, 93);
		std::cout << "found: " << *found << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "easyfind: value " << e.what() << " not found"<< std::endl;
	}
}

void	test_4(std::deque<int> &deq)
{
	try
	{
		std::deque<int>::iterator found = easyfind(deq, 34);
		std::cout << "found: " << *found << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "easyfind: value " << e.what() << " not found"<< std::endl;
	}
}

void	test_5(std::list<int> &list)
{
	try
	{
		for_loop_l(list);
		std::list<int>::iterator found = easyfind(list, 42);
		std::cout << "found: " << *found << std::endl;
		found = easyfind(list, 404);
		std::cout << "found: " << *found << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "easyfind: value " << e.what() << " not found"<< std::endl;
	}
}


int	main()
{
	std::cout << "--- VECTOR ---" << std::endl;
	std::vector<int> cont;
	cont.push_back(11);
	cont.push_back(21);
	cont.push_back(31);

	test_1(cont);

	std::vector<int> block;
	block.push_back(12);
	block.push_back(22);
	block.push_back(32);

	test_2(block);

	std::vector<int> meh;
	meh.push_back(13);
	meh.push_back(23);
	meh.push_back(33);

	test_3(meh);

	std::cout << "\n--- DEQUE ---\n" << std::endl;
	std::deque<int> deq;
	deq.push_back(24);
	deq.push_front(14);
	deq.push_back(34);

	test_4(deq);

	std::cout << "\n--- LIST ---\n" << std::endl;
	int myints[] = {75,23,65,42,13};
  	std::list<int> list (myints, myints+5);

	test_5(list);

	return (0);
}
