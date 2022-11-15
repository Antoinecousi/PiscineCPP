#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//-------------------- CONST & DESTRCT ----------------------------//

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";" ;
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _totalNbWithdrawals;
	std::cout << " index:" << _accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";" ;
	std::cout << "closed" << std::endl;
	return ;
}

//------------------------ ACCESSORS --------------------------------//

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount( void ) const
{
	return _amount; // Account::_amount???
}

//------------------------ DISPLAY METHODS --------------------------------//

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl ;
	return ;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";" ;
	std::cout << "deposits:" << _nbDeposits << ";" ;
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532]";

	// time_t current_time = time(NULL);
	// const struct tm *format_time = localtime(&current_time);
	// std::cout << "[" << format_time->tm_year + 1900 ;
	// if (format_time->tm_mon + 1 < 10)
	// 	std::cout << "0";
	// std::cout << format_time->tm_mon + 1 ;
	// if (format_time->tm_mday + 1 < 10)
	// 	std::cout << "0";
	// std::cout << format_time->tm_mday << "_";
	// if (format_time->tm_hour < 10)
	// 	std::cout << "0";
	// std::cout << format_time->tm_hour ;
	// if (format_time->tm_min < 10)
	// 	std::cout << "0";
	// std::cout << format_time->tm_min ;
	// if (format_time->tm_sec < 10)
	// 	std::cout << "0";
	// std::cout << format_time->tm_sec << "]";
}

//---------------------------- METHODS ------------------------------------//

void	Account::makeDeposit( int deposit )
{	
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" ;
	std::cout << "p_amount:" << _amount << ";" ;
	if (deposit < 0)
	{
		std::cout << "deposit:refused" << std::endl;
		return ;
	}
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "amount:" << _amount << ";" ;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" ;
	std::cout << "p_amount:" << _amount << ";" ;
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << "amount:" << _amount << ";" ;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl ;
	return (true);
}