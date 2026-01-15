/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:52:06 by dicarval          #+#    #+#             */
/*   Updated: 2025/12/03 16:25:41 by dicarval         ###   ########.fr       */
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
void	BitcoinExchange::foundPreviousDate(std::string &year, std::string &month, std::string &day)
{
	const int	mDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::istringstream isy(year);
	int			yearD;
	isy >> yearD;

	std::istringstream ism(month);
	int			monthD;
	ism >> monthD;

	std::istringstream isd(day);
	int			dayD;
	isd >> dayD;

	if (dayD == 1)
	{
		monthD -= 1;
		if (monthD == 0)
		{
			yearD -= 1;
			monthD = 12;
		}
		dayD = mDays[monthD - 1];
		if (monthD == 2 && isLeap(atoi(year.c_str())))
			dayD = 29;
	}
	else
		dayD -= 1;
	if ((yearD == 2009 && monthD == 1 && dayD == 1) || yearD < 2009 \
	|| yearD > 2022 || (yearD == 2022 && monthD > 2))
		throw InputInvalidDate("date (" + year + "-" + month + "-" + day + ")");
	year = intToDateFormat(yearD);
	month = intToDateFormat(monthD);
	day = intToDateFormat(dayD);
}

double	BitcoinExchange::exchangeExtract(std::string year, std::string month, std::string day)
{
	std::string	date = year + "-" + month + "-" + day;
	std::string	line;
	bool		found = false;

	_csv.clear();
	_csv.seekg(0);

	while (std::getline(_csv, line))
	{
		if(line.find(date) != std::string::npos)
		{
			found = true;
			break ;
		}
	}
	if (found == false)
	{
		foundPreviousDate(year, month, day);
		return (exchangeExtract(year, month, day));
	}
	line = line.substr(11);
	return (strtod(line.c_str(), NULL));
}

double	BitcoinExchange::numberExtract(std::string number)
{
	double nbF;
	char c;
	std::istringstream iss(number);

	if (!(iss >> nbF) || (iss >> c))
		throw InputInvalidFormat("input", number);
	else if (nbF < 0 || nbF > 1000)
		throw InputInvalidNumber(number);
	return nbF;
}

void	BitcoinExchange::checkSeparators(std::string hyphen1, std::string hyphen2, \
std::string separ)
{
	if (hyphen1 != "-")
		throw InputInvalidFormat("data separator", hyphen1);
	else if (hyphen2 != "-")
		throw InputInvalidFormat("data separator", hyphen2);
	else  if (separ != " | ")
		throw InputInvalidFormat("separator", separ);
}

std::string	BitcoinExchange::checkDay(std::string year,std::string month, std::string day)
{
	static const long mDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int imonth = atoi(month.c_str());
	int dMonth = mDays[imonth - 1];
	if (imonth == 2 && isLeap(atoi(year.c_str())))
		dMonth = 29;

	std::istringstream dayS(day);
	long dayL;
	if (!(dayS >> dayL) || dMonth <= dayL || dayL < 1)
		throw InputInvalidDate("day (" + day + ")");
	return day;
}

std::string	BitcoinExchange::checkMonth(std::string month)
{
	std::istringstream monthS(month);
	long monthL;

	if (!(monthS >> monthL) || monthL > 12 || monthL < 1)
		throw InputInvalidDate("month (" + month + ")");
	return month;
}

std::string	BitcoinExchange::checkYear(std::string year)
{
	std::istringstream yearS(year);
	long yearL;

	if (!(yearS >> yearL) || year.size() != 4|| yearL < 0)
		throw InputInvalidDate("year (" + year + ")");
	return year;
}

void	BitcoinExchange::openCsv()
{
	std::string		csvName = "data.csv";

	_csv.open(csvName.c_str());
	if (!_csv.is_open())
		throw InputFileUnableOpen(csvName);
}

void	BitcoinExchange::checkAndPrint()
{
	openCsv();
	while(!_qe.empty())
	{
		try
		{
			std::string year = checkYear(_qe.front().substr(0, 4));
			std::string month = checkMonth(_qe.front().substr(5, 2));
			std::string day =checkDay(year, month, _qe.front().substr(8, 2));
			checkSeparators(_qe.front().substr(4, 1), _qe.front().substr(7, 1), \
			_qe.front().substr(10, 3));
			double inputNumber = numberExtract(_qe.front().substr(13));
			double csvNumber = exchangeExtract(year, month, day);
			std::cout << std::fixed << std::setprecision(3);
			std::cout << year << "-" << month << "-" << day << " => " << inputNumber \
			<< " = " << (csvNumber * inputNumber)  << std::endl;
			_qe.pop();
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			_qe.pop();
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
: std::runtime_error("the " + date + " is not valid")
{}

BitcoinExchange::InputInvalidFormat::InputInvalidFormat(std::string invalid, std::string &format)
: std::runtime_error("the " + invalid + " has a invalid format: \"" + format + "\"")
{}

BitcoinExchange::InputInvalidNumber::InputInvalidNumber(std::string &number)
: std::runtime_error("the number \"" + number + "\" is out of the range {0-1000}")
{}


BitcoinExchange::InputFileUnableOpen::InputFileUnableOpen(std::string &filename)
: std::runtime_error("the input file failed to open: " + filename)
{}
