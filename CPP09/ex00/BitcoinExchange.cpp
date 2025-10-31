/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:52:06 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/31 18:46:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//CONSTRUCTORS & DESTRUCTOR
BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
	*this = original;
}

BitcoinExchange::~BitcoinExchange()
{}

//OPERATORS
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &original)
{
	if(this != &original)
		_qe = original._qe;
	return (*this);
}

//MEMBER FUNCTIONS
void	BitcoinExchange::checkSeparator(std::string separ)
{
	if (separ != " | ")
		throw InputInvalidFormat("separator", separ);
}

std::string	BitcoinExchange::checkDay(std::string year,std::string month, std::string day)
{
	static const long mDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int imonth = atoi(month.c_str());
	int dMonth = mDays[imonth - 1];
	if (imonth == 2 && isLeap(atoi(year.c_str())))
		dMonth = 29;
	errno = 0;
	long lday = strtol(day.c_str(), NULL, 10);
	if (errno == ERANGE || dMonth <= lday || lday < 1)
		throw InputInvalidDate("day = " + day);
	return day;
}

std::string	BitcoinExchange::checkMonth(std::string month)
{
	errno = 0;
	long lmonth = strtol(month.c_str(), NULL, 10);
	if (errno == ERANGE || lmonth < 1 || lmonth > 12)
		throw InputInvalidDate("month = " + month);
	return month;
}

std::string	BitcoinExchange::checkYear(std::string year)
{
	errno = 0;
	long lyear = strtol(year.c_str(), NULL, 10);
	if (errno == ERANGE || year.size() != 4 || lyear < 0)
		throw InputInvalidDate("year = " + year);
	return year;
}

void	BitcoinExchange::checkAndPrint()
{
	while(!_qe.empty())
	{
		try
		{
			std::string year = checkYear(_qe.front().substr(0, 4));
			std::string month = checkMonth(_qe.front().substr(5, 2));
			std::string day =checkDay(year, month, _qe.front().substr(8, 2));
			checkSeparator(_qe.front().substr(10, 3));
			//it's necessary to check the input number (after the separator)
			//find a way to compare dates to multiplicate the two values (input and csv)
			std::cout << year << "-" << month << "-" << day << " => " << inputNumber \
			<< "= " << csvNumber << std::endl;
			_qe.pop();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::checkInputHeader()
{
	if (_qe.front() != "date | value")
		throw InputInvalidFormat("header", _qe.front());
	_qe.pop();
}

void	BitcoinExchange::printExchangeResults()
{
	try
	{
		checkInputHeader();
		checkAndPrint();
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void	BitcoinExchange::extractCsv()
{
	std::fstream	csv;
	std::string		csvName = "data.csv";

	csv.open(csvName);
	if (!csv.is_open())
		throw InputFileUnableOpen(csvName);
	csv >> _csvContent;
	csv.close();
}


void	BitcoinExchange::loadInput(std::string& input)
{
	std::fstream	inFile;
	std::string		line;

	inFile.open(input.c_str());
	if (!inFile.is_open())
		throw InputFileUnableOpen(input);
	while(std::getline(inFile, line))
		_qe.push(line);
	inFile.close();
}


//EXCEPTIONS
BitcoinExchange::InputInvalidDate::InputInvalidDate(std::string date)
: std::runtime_error("The " + date + " is not valid")
{}

BitcoinExchange::InputInvalidFormat::InputInvalidFormat(std::string invalid, std::string &format)
: std::runtime_error("The " + invalid + " has a invalid format: " + format)
{}

BitcoinExchange::InputFileUnableOpen::InputFileUnableOpen(std::string &filename)
: std::runtime_error("The input file failed to open: " + filename)
{}
