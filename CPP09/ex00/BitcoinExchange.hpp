#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream &file);
		BitcoinExchange(BitcoinExchange const &instance);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);

		void		fillWallet();
		void		fillBitcoinPrice(std::string date, float value);
		int			parsing(std::string line);
		const bool	IsValidDate(const std::string &monthDay, const std::string &year);
		float		convertInDollars(std::string date, float value);

	private:
		std::map<std::string, float> _wallet;
		std::map<std::string, float> _bitcoinPrice;

};

const bool	isFloat(const std::string &str);
const bool	isInt(const std::string &str);
const int	countDays(const std::string &date);

#endif