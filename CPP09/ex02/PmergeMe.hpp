#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <array>
# include <list>
# include <iostream>
# include <string>
# include <sstream>
# include <sys/time.h>
# include <fstream>
# include <algorithm>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(char **input);
		PmergeMe(PmergeMe const &instance);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe(void);
		void	vectorSort(char **input);
		void	listSort(char **input);
		void	mergeInsertVectorAlgorithm(int chunks, int size);
		void	mergeInsertListAlgorithm(int chunks, int size);

	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		unsigned int		_size;
};

unsigned long long int	time_now_in_us(void);

#endif