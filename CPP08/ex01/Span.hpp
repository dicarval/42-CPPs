/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:54:48 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/06 16:31:10 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

class Span
{
	private:
		const unsigned int	_N;
		std::vector<int>		_theVector;

	public:
		Span(const unsigned int &nb);
		Span(const Span &original);
		~Span();

		void			addNumber(const int &newNb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		Span&			operator=(const Span &original);
};

#endif
