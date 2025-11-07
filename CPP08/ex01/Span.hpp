/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:54:48 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/07 11:12:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>

class Span
{
	private:
		std::vector<int>	_theVector;

	public:
		Span();
		Span(const unsigned int &nb);
		Span(const Span &original);
		~Span();

		void			addNumber(const long &newNb);
		void			addRange(const long &begin, const long &end);
		unsigned long	shortestSpan();
		unsigned long	longestSpan();

		Span&			operator=(const Span &original);

		class LessThanTwo : public std::exception
		{
			virtual const char* what() const throw();
		};
		class OutOfRange : public std::exception
		{
			virtual const char* what() const throw();
		};


};

#endif
