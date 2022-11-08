#include "Harl.hpp"

// ----------------- PUBLIC FUNCTIONS ----------------------

Harl::Harl(void)
{
	std::cout << "Hello Harl, what can we do for you?" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Don't forget your crown, King ;)" << std::endl;
}

void	Harl::complain(std::string level)
{
	void 		(Harl::*c[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string sentence[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == sentence[i])
			return (this->*(c[i]))();
	}
	std::cout << "Sorry, I didn't hear you. What the fuck did u just say u fakin twat?" << std::endl;
}

// ---------------- PRIVATE FUNCTIONS ----------------------

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;	
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;	
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;	
}