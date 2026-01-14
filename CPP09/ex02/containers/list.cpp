#include "../PmergeMe.hpp"

void	PmergeMe::insertPairInMainList(jacobList &main, jacobList &pend, \
long m, long &pairSize, long &pendIndex)
{
	for (long i = 0; i != pairSize; i++)
	{
		std::list<long>::iterator mainIt = main.numbers.begin();
		std::list<long>::iterator pendIt = pend.numbers.begin();

		advance(mainIt, (m + 1));
		advance(pendIt, (pendIndex - i));
		main.numbers.insert(mainIt, *pendIt);
		pend.numbers.erase(pendIt);
	}
	long realPendIndex = pendIndex > pairSize ? ((pendIndex + 1) / pairSize) - 1 : 0;
	long realM = m > pairSize ? ((m + 1) / pairSize) - 1 : 0;

	std::list<std::string>::iterator mainAB = main.aOrB.begin();
	std::list<std::string>::iterator pendAB = pend.aOrB.begin();

	advance(mainAB, (realM + 1));
	advance(pendAB, (realPendIndex));
	main.aOrB.insert(mainAB, *pendAB);
	pend.aOrB.erase(pendAB);

	std::list<long>::iterator mainPos = main.position.begin();
	std::list<long>::iterator pendPos = pend.position.begin();

	advance(mainPos, (realM + 1));
	advance(pendPos, (realPendIndex));
	main.position.insert(mainPos, *pendPos);
	pend.position.erase(pendPos);
}

void	PmergeMe::binarySearchList(jacobList &main, jacobList &pend, \
long &pairSize, long insertions, long n)
{
	for (long pendIndex = (pairSize * insertions) - 1; insertions != 0; pendIndex = (pairSize * --insertions) - 1)
	{
		long R = 0;
		long L = 0;
		std::list<long>::iterator mainPos = main.position.begin();
		std::list<std::string>::iterator mainAB = main.aOrB.begin();

		for (; main.position.size() != static_cast<size_t>(R) && (( n > *(mainPos++) && *mainAB == "a") || *(mainAB++) == "b"); R++)
		{
			//mainPos++;
			//mainAB++;
		}
		if (n > 2)
			n--;
		for (size_t insertionConfirm = main.numbers.size() + pairSize; insertionConfirm != main.numbers.size();)
		{
			std::list<long>::iterator mainIt = main.numbers.begin();
			std::list<long>::iterator mainNext = main.numbers.begin();
			std::list<long>::iterator mainPrev = main.numbers.begin();
			std::list<long>::iterator pendIt = pend.numbers.begin();

			long m = ((((L + ((R - L) / 2))) * pairSize) - 1) < 0 ? 0 : ((((L + ((R - L) / 2))) * pairSize) - 1);
			advance(mainIt, m);
			advance(pendIt, pendIndex);
			advance(mainNext, m + pairSize);
			advance(mainPrev, m - pairSize);
			if (m == ((R + 1) * pairSize) - 1 || (*pendIt > *mainIt && *pendIt < *mainNext))
				insertPairInMainList(main, pend, m, pairSize, pendIndex);
			else if (m == pairSize - 1 && *pendIt < *mainIt)
				insertPairInMainList(main, pend, -1, pairSize, pendIndex);
			else if ((*pendIt < *mainIt && *pendIt > *mainPrev))
				insertPairInMainList(main, pend, m - pairSize, pairSize, pendIndex);
			else if (*pendIt > *mainIt)
				L = ((m + 1) / pairSize) + 1;
			else if (*pendIt < *mainIt)
				R = ((m + 1) / pairSize) - 1;
		}
	}
}

bool	PmergeMe::mainPendSeparationList(jacobList &main, jacobList &pend,
long &pairSize, long &sizeList)
{
	long index = 0;
	long pairFirst = 0;
	bool insertPend = true;

	if (sizeList < (pairSize * 3))
		return true;
	for (std::list<long>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		if (index < (pairSize * 2))
			main.numbers.push_back(*it);
		else if (pairFirst + pairSize <= sizeList)
		{
			if (insertPend)
				pend.numbers.push_back(*it);
			else
				main.numbers.push_back(*it);
		}
		else
			break ;
		if (index++ == (pairFirst + (pairSize - 1)))
		{
			insertPend = (insertPend == false) ? true : false;
			pairFirst += pairSize;
		}
	}
	long pos = 1;
	main.aOrB.push_back("b");
	main.position.push_back(pos);
	for(size_t i = (pairSize * 2) - 1; i < main.numbers.size(); i += pairSize)
	{
		main.aOrB.push_back("a");
		main.position.push_back(pos++);
	}
	pos = 2;
	for(size_t i = pairSize - 1; i < pend.numbers.size(); i += pairSize)
	{
		pend.aOrB.push_back("b");
		pend.position.push_back(pos++);
	}
	return false;
}


void	PmergeMe::binaryInsertionList(long &pairSize, long &sizeList)
{
	jacobList main;
	jacobList pend;
	long jacobsthalN = 3;
	long prevJacobsthalN = 1;
	long n = 3;

	if (mainPendSeparationList(main, pend, pairSize, sizeList))
		return ;
	for(size_t insertions = jacobsthalN - prevJacobsthalN; insertions <= (pend.numbers.size() / pairSize); \
	insertions = jacobsthalN - prevJacobsthalN)
	{
		binarySearchList(main, pend, pairSize, insertions, jacobsthalN);
		prevJacobsthalN = jacobsthalN;
		jacobsthalN = std::pow(2, n++) - jacobsthalN;
	}
	while (!pend.numbers.empty())
		binarySearchList(main, pend, pairSize, 1, *(pend.position.begin()));
	std::list<long>::iterator itv = _list.begin();
	for (std::list<long>::iterator itm = main.numbers.begin(); itm != main.numbers.end(); itm++)
		*(itv++) = *itm;
}

void	PmergeMe::pairSortingList(long &pairSize, long &sizeList)
{
	std::list<long> tmp;

	for (long a = (pairSize - 1); a < sizeList; a += pairSize)
	{
		std::list<long>::iterator aIt = _list.begin();
		std::list<long>::iterator bIt = _list.begin();
		long b = a - (pairSize / 2);

		advance(aIt, a);
		advance(bIt, b);
		if (*aIt < *bIt)
		{
			long k = 0;
			for (long i = a; i != b; i--)
			{
				aIt = _list.begin();
				bIt = _list.begin();
				advance(aIt, i);
				advance(bIt, b - k++);
				tmp.insert(tmp.begin(), *aIt);
				*aIt = *bIt;
			}
			long prevPair = a - pairSize;
			k = 0;
			for (long j = b; j != prevPair; j--)
			{
				std::list<long>::iterator tmpIt = tmp.begin();

				bIt = _list.begin();
				advance(tmpIt, ((pairSize / 2) - 1) - k++);
				advance(bIt, j);
				*bIt = *tmpIt;
			}
		}
	}
}

void	PmergeMe::mergeInsertionList(long pairSize)
{
	long sizeList = static_cast<long>(_list.size());

	if (sizeList <= 1 || pairSize > sizeList / 2)
		return ;
	if (pairSize >= 2)
		pairSortingList(pairSize, sizeList);
	mergeInsertionList(pairSize * 2);
	binaryInsertionList(pairSize, sizeList);
}
