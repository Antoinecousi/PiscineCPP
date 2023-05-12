#include "MutantStack.hpp"


int		main()
{
	{
		std::cout << "---------- FIRST TEST WITH INTS ------------" << std::endl;
		// srand(0);
		MutantStack<int> myStackInt;
		// for (int i = 0; i < 15 ; i++)
		// {
		// 	myStackInt.push(rand() % 100);
		// }
		myStackInt.push(42);
		myStackInt.push(145);
		std::cout << "VALUE ON TOP OF STACK : " << myStackInt.top() << std::endl;
		myStackInt.pop();
		std::cout << "REMOVE OF THE LASt VALUE WITH \"POP()\"" << std::endl;
		std::cout << "SIZE OF THE STACK : " << myStackInt.size() << std::endl;

		std::cout << "------- PUSH OTHER VALUES --------" << std::endl;
		myStackInt.push(-100);
		myStackInt.push(-50);
		myStackInt.push(1);
		myStackInt.push(-1);
		myStackInt.push(42);
		myStackInt.push(84);
		myStackInt.push(126);
		MutantStack<int> myStackInt2(myStackInt);
		MutantStack<int> myStackInt3;
		myStackInt3 = myStackInt2;
		MutantStack<int>::container_type::iterator it = myStackInt2.begin(); // == typename std::stack<T>::container_type::iterator begin(){return (this->c.begin());}
		std::cout << "FIRST VALUE : " << *it++ << std::endl;
		std::cout << "SECOND VALUE : " << *it-- << std::endl;
		std::cout << "FIRST VALUE : " << *it << std::endl;
		std::cout << "COPY CONSTRUCTOR : ";
		while (it != myStackInt2.end())
		{	
			std::cout << *it;
			if (it != (myStackInt2.end() - 1))
				std::cout << ", ";
			++it;
		}
		std::cout << std::endl;
		MutantStack<int>::container_type::iterator it2 = myStackInt3.begin();
		std::cout << "ASSIGNATION CONSTRUCTOR : ";
		while (it2 != myStackInt3.end())
		{	
			std::cout << *it2;
			if (it2 != (myStackInt3.end() - 1))
				std::cout << ", ";
			++it2;
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n------ COMPARE WITH CONTAINER WITH ITERATORS ----------" << std::endl << std::endl;
	{
		std::cout << "---------- FIRST TEST WITH INTS ------------" << std::endl;
		// srand(0);
		std::list<int> myListInt;
		// for (int i = 0; i < 15 ; i++)
		// {
		// 	myListInt.push(rand() % 100);
		// }
		myListInt.push_back(42);
		std::cout << "VALUE ON TOP OF STACK : " << myListInt.back() << std::endl;
		myListInt.pop_back();
		std::cout << "REMOVE OF THE LASt VALUE WITH \"POP_BACK()\"" << std::endl;
		std::cout << "SIZE OF THE STACK : " << myListInt.size() << std::endl;

		std::cout << "------- PUSH OTHER VALUES --------" << std::endl;
		myListInt.push_back(-100);
		myListInt.push_back(-50);
		myListInt.push_back(1);
		myListInt.push_back(-1);
		myListInt.push_back(42);
		myListInt.push_back(84);
		myListInt.push_back(126);
		std::list<int>::iterator it = myListInt.begin();
		std::cout << "FIRST VALUE : " << *it++ << std::endl;
		std::cout << "SECOND VALUE : " << *it-- << std::endl;
		std::cout << "FIRST VALUE : " << *it << std::endl;
		while (it != myListInt.end())
		{	
			std::cout << *it;
			std::cout << " ";
			++it;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\n\n---------- FIRST TEST WITH STRINGS ------------\n" << std::endl;
		// srand(0);
		MutantStack<std::string> myStackStr;
		// for (int i = 0; i < 15 ; i++)
		// {
		// 	myStackStr.push(rand() % 100);
		// }
		myStackStr.push("patrick");
		std::cout << "VALUE ON TOP OF STACK : " << myStackStr.top() << std::endl;
		myStackStr.pop();
		std::cout << "REMOVE OF THE LASt VALUE WITH \"POP()\"" << std::endl;
		std::cout << "SIZE OF THE STACK : " << myStackStr.size() << std::endl;

		std::cout << "------- PUSH OTHER VALUES --------" << std::endl;
		myStackStr.push("COUCOU");
		myStackStr.push("50");
		myStackStr.push("1");
		myStackStr.push("1");
		myStackStr.push("42");
		myStackStr.push("84");
		myStackStr.push("AU REVOIR");
		MutantStack<std::string> myStackStr2(myStackStr);
		MutantStack<std::string> myStackStr3;
		myStackStr3 = myStackStr2;
		MutantStack<std::string>::container_type::iterator it = myStackStr2.begin();
		std::cout << "FIRST VALUE : " << *it++ << std::endl;
		std::cout << "SECOND VALUE : " << *it-- << std::endl;
		std::cout << "FIRST VALUE : " << *it << std::endl;
		std::cout << "COPY CONSTRUCTOR : ";
		while (it != myStackStr2.end())
		{	
			std::cout << *it;
			if (it != (myStackStr2.end() - 1))
				std::cout << ", ";
			++it;
		}
		std::cout << std::endl;
		MutantStack<std::string>::container_type::iterator it2 = myStackStr3.begin();
		std::cout << "ASSIGNATION CONSTRUCTOR : ";
		while (it2 != myStackStr3.end())
		{	
			std::cout << *it2;
			if (it2 != (myStackStr3.end() - 1))
				std::cout << ", ";
			++it2;
		}
		std::cout << std::endl;
	}
}