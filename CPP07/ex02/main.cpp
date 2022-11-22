#include "Array.hpp"

class Testing
{
	public : 
		Testing(void): _elem(0){};

		virtual ~Testing(void){};

		int		get(void) const 
		{
			return (_elem);
		};

		void	set(int n)
		{
			_elem = n;
		};

		Testing & operator=(int rhs)
		{
			_elem = rhs;
			return *this;
		};

		Testing & operator=(Testing & rhs)
		{
			_elem = rhs._elem;
			return *this;
		};

	private :
		int		_elem;
};

std::ostream & operator<<(std::ostream & o, Testing & rhs){
	o << rhs.get();
	return o;
}

int main(void)
{
	std::cout << "\n\n\n ---------- TEST STRINGS ----------" << std::endl;
	Array<std::string> str1(9);
	str1[0] = "Dispo";
	str1[1] = "24h/24";
	str1[2] = "pour";
	str1[3] = "depannage";
	str1[4] = "et";
	str1[5] = "plus";
	str1[6] = "si";
	str1[7] = "affinite";
	str1[8] = "!";
	std::cout << "FULL DISPLAY : " << str1 << std::endl;
	std::cout << "Its size : " << str1.size() << std::endl << std::endl;
	try
	{
		str1[8] = "!!!";
		str1[9] = "Isabella";
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		for (int i = 0 ; i <= 10 ; i++)	
		{
			std::cout << str1[i] << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	Array<std::string> str2(9);
	str2 = str1;
	std::cout << "PAR RECOPIE :\nSTR 2 = " << str2 << std::endl << "STR 1 = " << str1 << std::endl << std::endl;
	for (int i = 0 ; i < str2.size() ; i++)
		str2[i] = str1[str1.size() - i - 1];
	std::cout << "APRES LA MODIF  :\nSTR 2 = " << str2 << std::endl << "STR 1 = " << str1 << std::endl << std::endl << std::endl;

	Array<std::string> str3(str2);
	std::cout << "PAR ASSIGNATION :\nSTR 3 = " << str3 << std::endl << "STR 2 = " << str2 << std::endl << std::endl;
	for (int i = 0 ; i < str2.size() ; i++)
		str3[i] = str2[str1.size() - i - 1];
	std::cout << "APRES LA MODIF  :\nSTR 3 = " << str3 << std::endl << "STR 2 = " << str2 << std::endl << std::endl;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	std::cout << "---------- TEST INT ----------" << std::endl;
	Array<int> hinter1(9);
	hinter1[0] = 0;
	hinter1[1] = 1;
	hinter1[2] = 2;
	hinter1[3] = 3;
	hinter1[4] = 4;
	hinter1[5] = 5;
	hinter1[6] = 6;
	hinter1[7] = 7;
	hinter1[8] = 8;
	std::cout << "FULL DISPLAY : " << hinter1 << std::endl;
	std::cout << "Its size : " << hinter1.size() << std::endl << std::endl;
	try
	{
		hinter1[8] = 10;
		hinter1[9] = 15;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		for (int i = 0 ; i <= 10 ; i++)	
		{
			std::cout << hinter1[i] << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	Array<int> hinter2(9);
	hinter2 = hinter1;
	std::cout << "PAR RECOPIE :\nHINTER 2 = " << hinter2 << std::endl << "HINTER 1 = " << hinter1 << std::endl << std::endl;
	for (int i = 0 ; i < hinter2.size() ; i++)
		hinter2[i] = hinter1[hinter1.size() - i - 1];
	std::cout << "APRES LA MODIF  :\nHINTER 2 = " << hinter2 << std::endl << "HINTER 1 = " << hinter1 << std::endl << std::endl << std::endl;

	Array<int> hinter3(hinter2);
	std::cout << "PAR ASSIGNATION :\nHINTER 3 = " << hinter3 << std::endl << "HINTER 2 = " << hinter2 << std::endl << std::endl;
	for (int i = 0 ; i < hinter2.size() ; i++)
		hinter3[i] = hinter2[hinter1.size() - i - 1];
	std::cout << "APRES LA MODIF  :\nHINTER 3 = " << hinter3 << std::endl << "HINTER 2 = " << hinter2 << std::endl << std::endl;

	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << "---------- TEST CLASS ----------" << std::endl;
	Array<Testing> Classeur1(9);
	Classeur1[0] = 0;
	Classeur1[1] = 1;
	Classeur1[2] = 2;
	Classeur1[3] = 3;
	Classeur1[4] = 4;
	Classeur1[5] = 5;
	Classeur1[6] = 6;
	Classeur1[7] = 7;
	Classeur1[8] = 8;
	std::cout << "FULL DISPLAY : " << Classeur1 << std::endl;
	std::cout << "Its size : " << Classeur1.size() << std::endl << std::endl;
	try
	{
		Classeur1[8] = 10;
		Classeur1[9] = 15;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		for (int i = 0 ; i <= 10 ; i++)	
		{
			std::cout << Classeur1[i] << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	Array<Testing> Classeur2(9);
	Classeur2 = Classeur1;
	std::cout << "PAR RECOPIE :\nCLASSEUR 2 = " << Classeur2 << std::endl << "CLASSEUR 1 = " << Classeur1 << std::endl << std::endl;
	for (int i = 0 ; i < Classeur2.size() ; i++)
		Classeur2[i] = Classeur1[Classeur1.size() - i - 1];
	std::cout << "APRES LA MODIF  :\nCLASSEUR 2 = " << Classeur2 << std::endl << "CLASSEUR 1 = " << Classeur1 << std::endl << std::endl << std::endl;

	Array<Testing> Classeur3(Classeur2);
	std::cout << "PAR ASSIGNATION :\nCLASSEUR 3 = " << Classeur3 << std::endl << "CLASSEUR 2 = " << Classeur2 << std::endl << std::endl;
	for (int i = 0 ; i < Classeur2.size() ; i++)
		Classeur3[i] = Classeur2[Classeur1.size() - i - 1];
	std::cout << "APRES LA MODIF  :\nCLASSEUR 3 = " << Classeur3 << std::endl << "CLASSEUR 2 = " << Classeur2 << std::endl << std::endl;



	return (0);
}