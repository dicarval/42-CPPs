/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:30:30 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/18 15:13:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	std::string abacaxi("Abacaxi");
	const std::string arrozdc("Arroz de Cabidela");
	int array[] = {3,4,5,6,7,8,9};
	const int arraaay[] = {333,444,555,666,777,888,999};

	iter(abacaxi.c_str(), 7, printIt);
	iter(abacaxi.c_str(), 7, changeIt);
	iter(arrozdc.c_str(), 17, printIt);
	iter(array, 7, printIt);
	iter(arraaay, 7, printIt);
}
