#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **input)
{
	std::cout << "Before:  ";
	for (int i = 0; input[i]; i++)
	{
		std::cout << std::atoi(input[i]) << " ";
	}
	std::cout << std::endl;
	vectorSort(input);
	listSort(input);
	/////////// DISPLAY TIMEMANAGEMENT ////////////
	// std::cout << "Vector after:   ";
	// std::cout << _vector << std::endl;
	// std::cout << "List after:     ";
	// std::cout << _list << std::endl;
	std::cout << "After:   " << _vector << std::endl;

	std::cout << "Time to insert the numbers only with " <<
	_vector.size() << " elements with std::vector : " <<
	_timeInsertVector << " microseconds" << std::endl;


	std::cout << "Time to insert the numbers only with " <<
	_list.size() << " elements with std::list   : " <<
	_timeInsertList << " microseconds" << std::endl;



	std::cout << "Time to process the merge sort only with " <<
	_vector.size() << " elements with std::vector : " <<
	_timeMergeSortVector << " microseconds" << std::endl;


	std::cout << "Time to process the merge sort only with " <<
	_list.size() << " elements with std::list   : " <<
	_timeMergeSortList << " microseconds" << std::endl;



	std::cout << "Time to process the FordJohnson only with " <<
	_vector.size() << " elements with std::vector : " <<
	_timeFordJohnsonVector << " microseconds" << std::endl;


	std::cout << "Time to process the FordJohnson only with " <<
	_list.size() << " elements with std::list   : " <<
	_timeFordJohnsonList << " microseconds" << std::endl;



	std::cout << "Time to process a range of " << _vector.size() <<
	" elements with std::vector : " <<
	_timeFullVector << " microseconds" << std::endl;


	std::cout << "Time to process a range of " << _list.size() <<
	" elements with std::list   : " <<
	_timeFullList << " microseconds" << std::endl;

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

	while (i < size - chunks + 1)
	{
		j = i + chunks;
		while (j < i + chunks * 2 && j <= size)
		{
			current = _vector[j];
			int k = j;
			for (; k > i && current <= _vector[k - 1] ;)
			{
				k--;
				_vector[k + 1] = _vector[k];
			}
			_vector[k] = current;
			j++;
		}
		i += chunks * 2;
	}
	tmp.clear();
	if (chunks < size + 1)
		mergeInsertVectorAlgorithm(chunks * 2, size);
}

void	PmergeMe::mergeInsertListAlgorithm(int chunks, int size)
{
    int i = 0;
    int iSort = 0;
    int max = chunks * 2;
    int j;
    int current;
    std::list<int> tmp = _list;

    while (i < size - chunks + 1)
    {
        j = i + chunks;
        while (j < i + chunks * 2 && j <= size)
        {
            current = *std::next(_list.begin(), j);
            std::list<int>::iterator k = std::next(_list.begin(), j);
            for (; k != std::next(_list.begin(), i) && current <= *std::prev(k);)
            {
                k--;
                *std::next(k) = *k;
            }
            *k = current;
            j++;
        }
        i += chunks * 2;
    }
    if (chunks < size + 1)
    {
        tmp.clear();
        mergeInsertListAlgorithm(chunks * 2, size);
    }
}

void	PmergeMe::vectorSort(char **input)
{
	int i = 0;
	int	beginningMergeSortAlgoVector;
	int	beginning;
	int beginningFordJohnson;

	beginning = time_now_in_us();
	while (input[i])
		_vector.push_back(std::atoi(input[i++]));
	_timeInsertVector = time_now_in_us() - beginning;
	beginningMergeSortAlgoVector = time_now_in_us();
	mergeInsertVectorAlgorithm(1, _vector.size() - 1);
	_timeMergeSortVector = time_now_in_us() - beginningMergeSortAlgoVector;
	_vector.clear();
	i = 0;
	// std::cout << "vector is clear : " << _vector.size() << std::endl;
	while (input[i])
		_vector.push_back(std::atoi(input[i++]));
	// std::cout << "vector is full : " << _vector << std::endl;
	beginningFordJohnson = time_now_in_us();
	fordJohnsonMergeInsertVector(_vector);
	// std::cout << "vector is sorted : " << _vector << std::endl;
	_timeFordJohnsonVector = time_now_in_us() - beginningFordJohnson;
	_timeFullVector = time_now_in_us() - beginning;
}

void	PmergeMe::listSort(char **input)
{
	int i = 0;
	int	beginningMergeSortAlgoList;
	int	beginning;
	int beginningFordJohnson;

	beginning = time_now_in_us();
	while (input[i])
		_list.push_back(std::atoi(input[i++]));
	_timeInsertList = time_now_in_us() - beginning;	
	beginningMergeSortAlgoList = time_now_in_us();
	mergeInsertListAlgorithm(1, _list.size() - 1);
	_timeMergeSortList = time_now_in_us() - beginningMergeSortAlgoList;
	_list.clear();
	i = 0;
	// std::cout << "list is clear : " << _list.size() << std::endl;
	while (input[i])
		_list.push_back(std::atoi(input[i++]));
	// std::cout << "list is full and rearranged : " << _list << std::endl;
	beginningFordJohnson = time_now_in_us();
	fordJohnsonMergeInsertList(_list);
	_timeFordJohnsonList = time_now_in_us() - beginningFordJohnson;
	_timeFullList = time_now_in_us() - beginning;
}

void PmergeMe::binarySearchInsertionVector(std::vector<int>& mainChain, int element)
{
    int left = 0;
    int right = mainChain.size() - 1;

    while (left <= right)
	{
        int mid = left + (right - left) / 2;
        if (element < mainChain[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    mainChain.insert(mainChain.begin() + left, element);
}

void PmergeMe::fordJohnsonMergeInsertVector(std::vector<int>& list)
{
	std::vector<int> Jacobsthal = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844,
								43690, 87380, 174762, 349524, 699050, 1398100, 2796202, 5592404, 11184810,
								22369620, 44739242, 89478484, 178956970, 357913940, 715827882,
								1431655764, 2147483647}; // suite de jacobsthal-1 pour garder une logique en index.
	for (int i = 0; i < list.size() - 1; i += 2)
		if (list[i] > list[i + 1])
			std::swap(list[i], list[i + 1]); // swap pairs if not in order
	if (list.size() > 2)
	{
		std::vector<int> pairs;
		for (int i = 0; i < list.size(); i += 2)
			pairs.push_back(list[i]); //first element inside 'pairs'
		fordJohnsonMergeInsertVector(pairs); //repeat until only one pair is left
		std::vector<int> mainChain = pairs;
		std::vector<int> bs;
		for (int i = 1; i < list.size(); i += 2)
			bs.push_back(list[i]);
		int sizeTot = bs.size();
		for (int index = 0; index < sizeTot; index++)
		{
			int j = 0; // J est l'index de la range dans laquelle on se trouve sur Jacobsthal
			int finalIndex;
			for (j ; index > Jacobsthal[j] ; j++) {}
			if (j != 0)
			{
				if (sizeTot - 1 <= Jacobsthal[j]) // Si pending's size est plus petit que range on descend de pending's size.
					finalIndex = sizeTot - (index - Jacobsthal[j - 1]);
				else // Si range est inferieur a size on descend de max range (J(n))
					finalIndex = Jacobsthal[j] + 1 - (index - Jacobsthal[j - 1]); 
			}
			else
				finalIndex = 0;
			binarySearchInsertionVector(mainChain, bs[finalIndex]);
		}
		list = mainChain;
	}
}

void PmergeMe::binarySearchInsertionList(std::list<int>& mainChain, int element)
{
    std::vector<int> mainChainVector(mainChain.begin(), mainChain.end());
    int index = findInsertionIndex(mainChainVector, element);

    std::list<int>::iterator it = mainChain.begin();
    std::advance(it, index);

    mainChain.insert(it, element);
}

int PmergeMe::findInsertionIndex(const std::vector<int>& mainChainVector, int element)
{
    int left = 0;
    int right = mainChainVector.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (mainChainVector[mid] < element)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PmergeMe::fordJohnsonMergeInsertList(std::list<int>& list)
{
	std::vector<int> Jacobsthal = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730,
									5460, 10922, 21844, 43690, 87380, 174762, 349524,
									699050, 1398100, 2796202, 5592404, 11184810, 22369620,
									44739242, 89478484, 178956970, 357913940, 715827882,
									1431655764, 2147483647};
	for (std::list<int>::iterator it = list.begin(); it != list.end(); )
	{
		if(std::next(it) != list.end())
		{
			if (*it > *std::next(it))
				std::iter_swap(it, std::next(it)); 
			std::advance(it, 2);
		}
		else
		{
			break;
		}
	}
	if (list.size() > 2)
	{
		std::list<int> pairs;
		for (std::list<int>::iterator it = list.begin(); it != list.end(); )
		{
			pairs.push_back(*it);
			if (std::next(it) == list.end()) 
				break;
			std::advance(it, 2);
		}
		fordJohnsonMergeInsertList(pairs);
		std::list<int> mainChain = pairs;
		std::list<int> bs;
		for (std::list<int>::iterator it = ++list.begin(); it != list.end(); )
		{
			bs.push_back(*it);
			if (std::next(it) == list.end())
				break;
			std::advance(it, 2);
		}
		int sizeTot = bs.size();
		for (int index = 0; index < sizeTot; index++)
		{
			int j = 0;
			int finalIndex;
			for (j ; index > Jacobsthal[j] ; j++) {}
			if (j != 0)
			{
				if (sizeTot - 1 <= Jacobsthal[j])
					finalIndex = sizeTot - (index - Jacobsthal[j - 1]);
				else
					finalIndex = Jacobsthal[j] + 1 - (index - Jacobsthal[j - 1]);
			}
			else
				finalIndex = 0;
			binarySearchInsertionList(mainChain, *std::next(bs.begin(), finalIndex));
			sizeTot = bs.size();
		}
		list = mainChain;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// OTHER FUNCTIONS /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned long long int	time_now_in_us(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long long int)(long long int)now.tv_sec * 1000000
		+ (long long int)now.tv_usec);
}

std::ostream & operator<<(std::ostream & o, std::vector<int> rhs)
{
	for (int i = 0; i < rhs.size(); i++)
		o << rhs[i] << " ";
	return (o);
}

std::ostream & operator<<(std::ostream & o, std::list<int> rhs)
{
	for (std::list<int>::iterator it = rhs.begin(); it != rhs.end(); it++)
		o << *it << " ";
	return (o);
}