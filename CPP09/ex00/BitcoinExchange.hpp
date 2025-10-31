/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:46:32 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/31 18:40:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <queue>
#include <iostream>
#include <fstream>
//#include <string>

class BitcoinExchange
{
	protected:
		std::queue<std::string>	_qe;
		std::string				_csvContent;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &original);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange &original);

		void				loadInput(std::string &input);
		void				extractCsv();
		void				printExchangeResults();
		void				checkInputHeader();
		void				checkAndPrint();
		std::string			checkYear(std::string year);
		std::string			checkMonth(std::string month);
		std::string			checkDay(std::string year, std::string month, std::string day);
		void				checkSeparator(std::string separ);

		class InputFileUnableOpen : public std::runtime_error
		{
			public:
				InputFileUnableOpen(std::string &filename);
		};

		class InputInvalidFormat : public std::runtime_error
		{
			public:
				InputInvalidFormat(std::string invalid, std::string &format);
		};

		class InputInvalidDate : public std::runtime_error
		{
			public:
				InputInvalidDate(std::string date);
		};
};

bool	isLeap(int year);

#endif
