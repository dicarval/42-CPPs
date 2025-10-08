/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:54:48 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/08 14:52:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <climits>

class Span
{
	private:
		std::vector<int>	_theVector;

	public:
		Span();
		Span(const unsigned int &nb);
		Span(const Span &original);
		~Span();

		void			addNumber(const int &newNb);
		void			addRange(const int &begin, const int &end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		Span&			operator=(const Span &original);

		class LessThanTwo : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
