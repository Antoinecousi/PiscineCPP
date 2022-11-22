#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <sys/time.h>

Base	*generate(void)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	if (tp.tv_usec % 3 == 0)
	{
		A *Arbre = new A;
		std::cout << "Class A created." << std::endl;
		return (Arbre);
	}
	else if (tp.tv_usec % 3 == 1)
	{
		B *Boulot = new B;
		std::cout << "Class B created." << std::endl;
		return (Boulot);
	}
	else
	{
		C *Chene = new C;
		std::cout << "Class C created." << std::endl;
		return (Chene);
	}
}

void	identify(Base* p)
{
	A	*Acacia;
	B	*Boulot;
	C	*Chene;

	if (Acacia = dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (Boulot = dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (Chene = dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A & Acacia = dynamic_cast<A &>(p);
		(void) Acacia;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		// std::cout << "it is not A. Exception : " << e.what() << std::endl;
	}
	try
	{
		B & Boulot = dynamic_cast<B &>(p);
		(void) Boulot;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		// std::cout << "it is not B. Exception : " << e.what() << std::endl;
	}
	try
	{
		C & Chene = dynamic_cast<C &>(p);
		(void) Chene;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		// std::cout << "it is not C. Exception : " << e.what() << std::endl;
	}

}

int		main()
{
	Base *tmp = generate();
	identify(tmp);
	identify(*tmp);
	delete tmp;
	return (1);
}
