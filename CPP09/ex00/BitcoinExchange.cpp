#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	std::string line;
	float		valueFloat;

	fillWallet();
	while (std::getline(file, line))
	{
		if (line == "date | value" || parsing(line))
			continue;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance)
{
	*this = instance;
}

BitcoinExchange::~BitcoinExchange(void)
{
	_wallet.clear();
	_bitcoinPrice.clear();
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		_wallet = rhs._wallet;
		_bitcoinPrice = rhs._bitcoinPrice;
	}
	return (*this);
}

int	BitcoinExchange::parsing(std::string line)
{
	std::string date;
	std::string	value;

	if (std::count(line.begin(), line.end(), '|') != 1)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	date = line.substr(0, line.find('|'));
	value = line.substr(line.find('|') + 1);
	if (isInt(date.substr(0, line.find('-'))) ||
		IsValidDate(date.substr(date.find('-') + 1, 5), date.substr(0, line.find('-'))) ||
		countDays(date) > 739037)
	{
		std::cout << "Error: bad date input => " << date << std::endl;
		return (1);
	}
	if (value.length() <= 1 || !isFloat(value))
	{
		std::cout << "Error: bad value input =>" << value << std::endl;
		return (1);
	}
	if (stof(value) < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (stof(value) > 1000)
	{
		std::cout << "Error: too large number." << std::endl;
		return (1);
	}
	std::cout << date << "=> " << stof(value) << " = " << convertInDollars(date, stof(value)) << std::endl;
	return (0);
}

void	BitcoinExchange::fillWallet(void)
{
	std::ifstream data("data.csv");
	std::string line;
	std::string date;
	std::string	value;
	float		valueFloat;
	std::getline(data, line);

	while (std::getline(data, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value);
		valueFloat = std::stof(value);
		_wallet.insert(std::pair<std::string, float>(date, valueFloat));
	}
	data.close();
}

float	BitcoinExchange::convertInDollars(std::string date, float value)
{
	std::map<std::string, float>::iterator it;
	float result;
	int dateCount = countDays(date);
	int dateCount2;

	if (dateCount <= 734367)
		return (0);
	it = _wallet.begin();
	while (it != _wallet.end())
	{
		dateCount2 = countDays(it->first);
		if (dateCount2 == dateCount)
			break;
		if (dateCount2 > dateCount)
		{
			it--;
			break ;
		}
		it++;
	}
	if (it == _wallet.end())
		it--;
	result = value * it->second;
	return (result);
}

const bool	BitcoinExchange::IsValidDate(const std::string &monthDay, const std::string &year)
{
	std::map<std::string, float>::iterator it;
	std::string dateWall;

	if (monthDay == "02-29" && !((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || stoi(year) % 400 == 0))
		return (true);
	if (monthDay == "02-29")
		return (false);
	it = _wallet.begin();
	while (it != _wallet.end())
	{
		if (it->first.substr(it->first.find('-') + 1) == monthDay)
			return (false);
		it++;
	}
	return (true);
}

const bool	isFloat(const std::string &str)
{
    size_t idx;
    try
    {
        float f = std::stof(str, &idx);   
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }

    for(size_t i = idx; i < str.size(); i++)
    {
        if(!std::isspace(str[i]))
        {
            return false;
        }
    }

    return true;
}

const bool	isInt(const std::string &str)
{
	try
	{
		std::stoi(str);
		return (false);
	}
	catch (const std::invalid_argument &)
	{
		return (true);
	}
}

const int	countDays(const std::string &date)
{
	int year = std::stoi(date.substr(0, date.find('-')));
	int month = std::stoi(date.substr(date.find('-') + 1, date.find('-')));
	int day = std::stoi(date.substr(date.find('-') + 4, date.find('-')));
    int days = 0;
    int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
    for (int i = 0; i < year; i++)
	{
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            days += 366;
		else
            days += 365;
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        month_days[1] = 29;
    for (int i = 0; i < month - 1; i++)
        days += month_days[i];
    days += day; // Add days of current month
    return (days);
}
