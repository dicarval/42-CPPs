/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:53:19 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/04 13:29:49 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *ptr = new Data;
	ptr->number = 42;
	uintptr_t uint;

	std::cout << "Pointer adress: " << ptr << std::endl;
	uint = Serializer::serialize(ptr);
	std::cout << "Unsigned int(serialize): " << uint << std::endl;
	std::cout << "Pointer adress(deserialize): "\
	 << Serializer::deserialize(uint) << std::endl;
	delete ptr;
}
