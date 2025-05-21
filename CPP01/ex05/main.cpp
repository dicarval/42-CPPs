/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:59:44 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/21 17:58:58 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	Karen;

	Karen.complain("info");
	Karen.complain("debug");
	Karen.complain("warning");
	Karen.complain("error");
	return 0;
}
