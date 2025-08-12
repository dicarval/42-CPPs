/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:59:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 16:23:11 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";
	Bureaucrat guy("Guy", 4);
	Bureaucrat dennis("Dennis", -5);
	Bureaucrat tony("Tony", 149);
	Bureaucrat van_damme("Van Damme", 174);

	guy.IncrementGrade();
	guy.IncrementGrade();
	guy.IncrementGrade();
	guy.IncrementGrade();
	tony.DecrementGrade();
	tony.DecrementGrade();
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";
	Bureaucrat phill("Phill", 42);

	std::cout << "This is " << phill;
}


int	main()
{
	test1();
	test2();
}
