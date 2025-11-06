/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:30:30 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/06 10:19:43 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	const char			abacaxi[] = "Abacaxi";
	char				*brah = const_cast<char*>(abacaxi);
	int					array[] = {3,4,5,6,7,8,9};
	const int			arraaay[] = {333,444,555,666,777,888,999};

	iter(abacaxi, 7, printIt);
	//iter(abacaxi, 7, changeIt);
	iter(brah, 7, changeIt);
	iter(brah, 7, changeIt);
	iter(brah, 7, changeIt);
	std::cout << std::endl;
	iter(array, 7, printIt);
	iter(array, 7, changeIt);
	iter(arraaay, 7, printIt);
	//iter(arraaay, 7, changeIt);
}
