#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(char **input)
{
	std::cout << "Before: " << std::endl;
	vectorSort(input);
	listSort(input);
	for(int i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
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

	for (int l = 0; l < _vector.size(); l++)
		std::cout << _vector[l] << " ";
	std::cout << std::endl;
	while (i < size - chunks + 1)
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

    std::cout << "before sort list of chunks " << chunks << " = ";
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    while (i < size - chunks + 1)
    {
        j = i + chunks;
        while (j < i + chunks * 2) // could add isSorted(i, chunksize);
        {
            current = *std::next(_list.begin(), j); // int copy cuz we change the value of _list
            std::list<int>::iterator k = std::next(_list.begin(), j);
            std::cout << "k = " << j << " i = " << i << " j = " << j << " *k = " << *k << " *(k-1) = " << *std::prev(k) << std::endl;
            for (; k != _list.begin() && current <= *std::prev(k);) // https://www.softwaretestinghelp.com/merge-sort/
            {
                k--;
                // std::cout << "im here" << std::endl;
                *std::next(k) = *k;
            }
            *k = current;
            j++;
        }
        std::cout << "changement de chunk" << std::endl;
        i += chunks * 2;
    }
    std::cout << "after sort list of chunks " << chunks << " = ";
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
        std::cout << *it << " ";
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
	int	beginningMergeSortAlgoVector = time_now_in_us();
	mergeInsertVectorAlgorithm(1, _vector.size() - 1);
	_timeFullVector = time_now_in_us() - beginning;
	_timeMergeSortVector = time_now_in_us() - beginningMergeSortAlgoVector;
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
	mergeInsertListAlgorithm(1, _list.size() - 1);
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