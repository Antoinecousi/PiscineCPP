#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(char **input)
{
	vectorSort(input);
	listSort(input);
	for(int i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << "\n" << std::endl;
	for(auto i : _list)
		std::cout << i << " ";
	std::cout << "\n" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &instance)
{
	
}

PmergeMe::~PmergeMe(void)
{
	_vector.clear();
	_list.clear();
}

PmergeMe	&	PmergeMe::operator=(PmergeMe const &rhs)
{
	return (*this);
}

void	PmergeMe::mergeInsertVectorAlgorithm(int chunks, int size)
{
	int i = 0;
	int iSort = 0;
	int max = chunks * 2;
	int j;
	int current;
	std::vector<int> tmp = _vector;

	std::cout << "before sort of chunks " << chunks << " = ";
	for (int l = 0; l < _vector.size(); l++)
		std::cout << _vector[l] << " ";
	std::cout << std::endl;
	while (i < size - chunks)
	{
		j = i + chunks;
		while (j < i + chunks * 2) // could add isSorted(i, chunksize);
		{
			current = _vector[j]; // int copy cuz we change the value of _vector
			int k = j; 
			std::cout << "k = " << k << " i = " << i << " j = " << j << " _vector[k] = " << _vector[k] << " _vector[k - 1] = " << _vector[k - 1] << std::endl;
			for (; k > i && current <= _vector[k - 1] ;) // https://www.softwaretestinghelp.com/merge-sort/
			{
				k--;
				// std::cout << "im here" << std::endl;
				_vector[k + 1] = _vector[k];
			}
			_vector[k] = current;
			j++;
		}
		std::cout << "changement de chunk" << std::endl;
		i += chunks * 2;
	}
	std::cout << "after sort of chunks " << chunks << " = ";
	for (int l = 0; l < _vector.size(); l++)
		std::cout << _vector[l] << " ";
	std::cout << std::endl;
	if (chunks < size + 1)
	{
		tmp.clear();
		mergeInsertVectorAlgorithm(chunks * 2, size);
	}
}

void	PmergeMe::mergeInsertListAlgorithm(int chunks, int size)
{
	int i = 0;
	int iSort = 0;
	int max = chunks * 2;
	int j;
	int current;
	std::list<int> tmp = _list;

	std::cout << "before sort of chunks " << chunks << " = ";
	for (int l = 0; l < _list.size(); l++)
		std::cout << _list[l] << " ";
	std::cout << std::endl;
	while (i < size - chunks)
	{
		j = i + chunks;
		while (j < i + chunks * 2) // could add isSorted(i, chunksize);
		{
			current = _list[j]; // int copy cuz we change the value of _list
			int k = j; 
			std::cout << "k = " << k << " i = " << i << " j = " << j << " _list[k] = " << _list[k] << " _list[k - 1] = " << _list[k - 1] << std::endl;
			for (; k > i && current <= _list[k - 1] ;) // https://www.softwaretestinghelp.com/merge-sort/
			{
				k--;
				// std::cout << "im here" << std::endl;
				_list[k + 1] = _list[k];
			}
			_list[k] = current;
			j++;
		}
		std::cout << "changement de chunk" << std::endl;
		i += chunks * 2;
	}
	std::cout << "after sort of chunks " << chunks << " = ";
	for (int l = 0; l < _list.size(); l++)
		std::cout << _list[l] << " ";
	std::cout << std::endl;
	if (chunks < size + 1)
	{
		tmp.clear();
		mergeInsertListAlgorithm(chunks * 2, size);
	}
}

void	PmergeMe::vectorSort(char **input)
{
	int i = 0;
	int	total_time;
	int	beginning = time_now_in_us();

	while (input[i])
	{
		_vector.push_back(std::atoi(input[i]));
		i++;
	}
	for (int l = 0; l < _vector.size(); l++)
		std::cout << _vector[l] << " ";
	std::cout << "Hello" << std::endl;
	mergeInsertVectorAlgorithm(1, _vector.size() - 1);
	total_time = time_now_in_us() - beginning;
	std::cout << "vectorSort took " << total_time << " microseconds" << std::endl;
}

void	PmergeMe::listSort(char **input)
{
	int i = 0;
	int	total_time;
	int	beginning = time_now_in_us();

	while (input[i])
	{
		_list.push_back(std::atoi(input[i]));
		i++;
	}

	total_time = time_now_in_us() - beginning;
	std::cout << "listSort took " << total_time << " microseconds" << std::endl;
}

unsigned long long int	time_now_in_us(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long long int)(long long int)now.tv_sec * 1000000
		+ (long long int)now.tv_usec);
}