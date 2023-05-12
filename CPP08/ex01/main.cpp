#include "Span.hpp"

int		main()
{	
				///// TEST 15000 entrees //////////

	Span holder1(15000);
	std::vector<int>::iterator start = holder1.get_vect_int().begin();
	std::vector<int>::iterator end = holder1.get_vect_int().end();
	try
	{
		holder1.addALotOfNumbers<std::vector<int>::iterator>(start, start + 10);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "IT start = " << *holder1.get_vect_int().begin() << " IT end = " << *(holder1.get_vect_int().end() - 1) << std::endl;
	std::cout << holder1 << std::endl;
	std::cout << holder1.shortestSpan() << std::endl;
	std::cout << holder1.longestSpan() << std::endl;
	try
	{
		start = holder1.get_vect_int().begin();
		holder1.addALotOfNumbers<std::vector<int>::iterator>(start, start + 10);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "IT start = " << *holder1.get_vect_int().begin() << " IT end = " << *(holder1.get_vect_int().end() - 1) << std::endl;
	std::cout << holder1 << std::endl;
	std::cout << holder1.shortestSpan() << std::endl;
	std::cout << holder1.longestSpan() << std::endl;





			// TEST with ADD & finish w/addRange ////

	Span Holder2(25);
	std::vector<int>::iterator start4;
	try
	{
		Holder2.addNumber(-2);
		Holder2.addNumber(-3);
		Holder2.addNumber(-12);
		Holder2.addNumber(-9);
		Holder2.addNumber(-13);
		Holder2.addNumber(-14);
		Holder2.addNumber(-15);
		Holder2.addNumber(-16);
		Holder2.addNumber(-17);
		start4 = Holder2.get_vect_int().begin();
		Holder2.addALotOfNumbers<std::vector<int>::iterator>(start4, start4 + 25000);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Holder2.addNumber(2147483648);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "IT start = " << *Holder2.get_vect_int().begin() << " IT end = " << * (Holder2.get_vect_int().end() -1  )<< std::endl;
	std::cout << Holder2 << std::endl;
	try
	{
		std::cout << Holder2.shortestSpan() << std::endl;
		std::cout << Holder2.longestSpan() << std::endl << std::endl << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}




				//// TEST DU SUJET ///////
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.addNumber(6);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}