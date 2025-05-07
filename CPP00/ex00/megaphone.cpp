/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:10 by dicarval          #+#    #+#             */
/*   Updated: 2025/04/29 16:27:45 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_strings(char **argv)
{
	int	i = 0;

	while (argv[++i])
		std::cout << argv[i];
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j;

	if (argc > 1)
	{
		while (argv[++i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (islower((int)argv[i][j]))
					argv[i][j] = toupper((int)argv[i][j]);
				j++;
			}
		}
		print_strings(argv);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return 0;
}
