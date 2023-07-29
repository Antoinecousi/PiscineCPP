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

		// Vector
		void	vectorSort(char **input);
		void	mergeInsertVectorAlgorithm(int chunks, int size);
		void	binarySearchInsertionVector(std::vector<int>& mainChain, int element);
		void	fordJohnsonMergeInsertVector(std::vector<int>& list);

		// List
		void	listSort(char **input);
		void	mergeInsertListAlgorithm(int chunks, int size);
		void	binarySearchInsertionList(std::list<int>& mainChain, int element);
		void	fordJohnsonMergeInsertList(std::list<int>& list);
		int		findInsertionIndex(const std::vector<int>& mainChainVector, int element);

	private:
		unsigned int		_size;

		std::vector<int>	_vector;
		int					_timeInsertVector;
		int					_timeMergeSortVector;
		int					_timeFullVector;
		int					_timeFordJohnsonVector;

		std::list<int>		_list;
		int					_timeInsertList;
		int					_timeMergeSortList;
		int					_timeFullList;
		int					_timeFordJohnsonList;
};

unsigned long long int	time_now_in_us(void);
std::ostream & operator<<(std::ostream & o, std::vector<int> rhs);
std::ostream & operator<<(std::ostream & o, std::list<int> rhs);

#endif