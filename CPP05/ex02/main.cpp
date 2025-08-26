/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:59:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/25 17:31:26 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	test3()
{
	std::cout << "\n==========| TEST 3 |==========\n\n";
	Bureaucrat	xico("Xico", 4);
	Bureaucrat	tony("Tony", 56);
	Form		build("Building Autorization", 7, 2);
	Form		demolition("Demolition Autorization", 55, 55);

	std::cout << "\n";

	xico.signForm(build);
	xico.signForm(build);
	tony.signForm(demolition);
	tony.IncrementGrade();
	tony.signForm(demolition);
}

int	main()
{
	test1();
	test2();
	test3();
}
