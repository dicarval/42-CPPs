/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:41:18 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/02 16:53:08 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void for_loop(std::vector<int> &c)
{
	for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}

void	test_1(std::vector<int> &cont)
{
	std::cout << "--- test 1 ---\n\n";

	for_loop(cont);

	std::vector<int>::iterator found = easyfind(cont, 21);
	std::cout << "found: " << *found << std::endl;
}

void	test_2(const std::vector<int> &block)
{
	std::cout << "\n--- test 2 ---\n\n";

	for (std::vector<int>::const_iterator it = block.begin(); it != block.end(); ++it)
		std::cout << *it << std::endl;

	std::vector<int>::const_iterator found = easyfind(block, 22);
	std::cout << "found: " << *found << std::endl;
}

void	test_3(std::vector<int> &meh)
{
	std::cout << "\n--- test 3 ---\n\n";

	for_loop(meh);
	std::cout << std::endl;
	meh.erase(meh.end());
	for_loop(meh);
	meh.insert(meh.begin(), 43);
	for_loop(meh);
	meh.assign(2, 53);
	for_loop(meh);
	meh.push_back(93);
	for_loop(meh);
	std::vector<int>::iterator found = easyfind(meh, 93);
	std::cout << "found: " << *found << std::endl;
}


int	main()
{
	try
	{
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
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
