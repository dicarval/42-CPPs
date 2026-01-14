/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:46:32 by dicarval          #+#    #+#             */
/*   Updated: 2025/12/03 16:25:44 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <queue>
#include <limits>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
	protected:
		std::queue<std::string>	_qe;
		std::ifstream			_csv;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &original);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange &original);

		void				loadInput(std::string &input);
		void				openCsv();
		void				printExchangeResults();
		void				checkInputHeader();
		void				checkAndPrint();
		std::string			checkYear(std::string year);
		std::string			checkMonth(std::string month);
		std::string			checkDay(std::string year, std::string month, std::string day);
		void				checkSeparators(std::string hyphen1, std::string hyphen2, std::string separ);
		double				numberExtract(std::string number);
		double				exchangeExtract(std::string year, std::string month, std::string day);
		void				foundPreviousDate(std::string &year, std::string &month, std::string &day);

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

		class InputInvalidNumber : public std::runtime_error
		{
			public:
				InputInvalidNumber(std::string &number);
		};

		class InputInvalidDate : public std::runtime_error
		{
			public:
				InputInvalidDate(std::string date);
		};
};

bool		isLeap(int year);
std::string	intToDateFormat(int number);

#endif
