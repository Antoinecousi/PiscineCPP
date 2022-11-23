#include "Span.hpp"

int		main()
{	
				///// TEST 15000 entrees //////////

	Span holder_one(15000);
	std::vector<int>::iterator start = holder_one.get_vect_int().begin();
	std::vector<int>::iterator end = holder_one.get_vect_int().end();
	try
	{
		holder_one.addALotOfNumbers<std::vector<int>::iterator>(start, start + 10);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<int>::const_iterator start2 = holder_one.get_vect_int().begin();
	// std::vector<int>::iterator end2 = holder_one.get_vect_int().end();
	std::cout << "IT start = " << *start2 << " IT end = " << "toto" << std::endl;
	// std::cout << holder_one << std::endl;
	//std::cout << holder_one.shortestSpan() << std::endl;
	//std::cout << holder_one.longestSpan() << std::endl;






			//// TEST with ADD & finish w/addRange ////

	// Span Holder2(25);
	// std::vector<int>::iterator start4;
	// try
	// {
	// 	Holder2.addNumber(-2);
	// 	Holder2.addNumber(-3);
	// 	Holder2.addNumber(-12);
	// 	Holder2.addNumber(-9);
	// 	Holder2.addNumber(-13);
	// 	Holder2.addNumber(-14);
	// 	Holder2.addNumber(-15);
	// 	Holder2.addNumber(-16);
	// 	Holder2.addNumber(-17);
	// 	start4 = Holder2.get_vect_int().begin();
	// 	Holder2.addALotOfNumbers<std::vector<int>::iterator>(start4, start4 + 25000);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::vector<int>::iterator start3;
	// start3 = Holder2.get_vect_int().begin();
	// std::vector<int>::iterator end3 = Holder2.get_vect_int().end();
	// std::cout << "IT start = " << (*start3) << " IT end = " << * (Holder2.get_vect_int().end() -1  )<< std::endl;
	// std::cout << Holder2 << std::endl;
	// std::cout << Holder2.shortestSpan() << std::endl;
	// std::cout << Holder2.longestSpan() << std::endl;




	// 			//// TEST DU SUJET ///////

	// Span sp = Span(5);

	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(12);
	// sp.addNumber(9);
	// sp.addNumber(11);

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	return 0;
}