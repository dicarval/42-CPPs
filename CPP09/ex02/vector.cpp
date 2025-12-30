#include "PmergeMe.hpp"

void	PmergeMe::mainPendSeparationVec(std::vector<long> &main, std::vector<long> &pend,
long &pairSize, long &sizeVec)
{
	long index = 0;
	long pairFirst = 0;
	bool b = true;

	if (sizeVec < (pairSize * 3))
		return ;
	for (std::vector<long>::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		if (index < (pairSize * 2))
			main.push_back(*it);
		else if (pairFirst + pairSize < sizeVec)
		{
			if (b)
				pend.push_back(*it);
			else
				main.push_back(*it);
		}
		else
			break ;
		if (index++ == (pairFirst + (pairSize - 1)))
		{
			b = false;
			pairFirst += pairSize;
		}
	}
}

void	PmergeMe::binaryInsertionVec(long &pairSize, long &sizeVec)
{
	std::vector<long> main;
	std::vector<long> pend;

	mainPendSeparationVec(main, pend, pairSize, sizeVec);

}

void	PmergeMe::pairSortingVec(long &pairSize, long &sizeVec)
{
	std::vector<long> tmp;

	if (sizeVec <= 1 || pairSize > sizeVec)
		return ;
	for (long a = (pairSize - 1); a < sizeVec; a += pairSize)
	{
		long b = a - (pairSize / 2);
		if (_vec.at(a) < _vec.at(b))
		{
			long k = 0;
			for (long i = a; i != b; i--)
			{
				tmp.insert(tmp.begin(), _vec.at(i));
				_vec.at(i) = _vec.at(b - k++);
			}
			long prevPair = a - pairSize;
			k = 0;
			for (long j = b; j != prevPair; j--)
				_vec.at(j) = tmp.at(((pairSize / 2) - 1) - k++);
		}
//		for (int i = 0; i < sizeVec; i++)
//				std::cout << _vec.at(i) << " ";
//		std::cout << std::endl;
	}
}

void	PmergeMe::mergeInsertionVec(long pairSize)
{
	long sizeVec = static_cast<long>(_vec.size());

	pairSortingVec(pairSize, sizeVec);
	mergeInsertionVec(pairSize * 2);
	binaryInsertionVec(pairSize, sizeVec);
}
