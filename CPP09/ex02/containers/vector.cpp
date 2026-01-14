#include "../PmergeMe.hpp"

void	PmergeMe::insertPairInMainVec(jacobVec &main, jacobVec &pend, \
long m, long &pairSize, long &pendIndex)
{
	for (long i = 0; i != pairSize; i++)
	{
		//std::cout << "main: " << main.numbers.size() << std::endl;
		//std::cout << "m:   " << m << std::endl;
		//std::cout << "pend: " << pend.numbers.size() << std::endl;
		//std::cout << "pendIndex: " << pendIndex << std::endl;
		//std::cout << "i: " << i << std::endl;
		//std::cout << "pairSize: " << pairSize << std::endl;
		main.numbers.insert(main.numbers.begin() + (m + 1), pend.numbers[pendIndex - i]);
		pend.numbers.erase((pend.numbers.begin() + (pendIndex - i)));
	}
	long realPendIndex = pendIndex > pairSize ? ((pendIndex + 1) / pairSize) - 1 : 0;
	long realM = m > pairSize ? ((m + 1) / pairSize) - 1 : 0;
	main.aOrB.insert(main.aOrB.begin() + realM + 1, pend.aOrB[realPendIndex]);
	pend.aOrB.erase(pend.aOrB.begin() + realPendIndex);
	main.position.insert(main.position.begin() + realM + 1, pend.position[realPendIndex]);
	pend.position.erase(pend.position.begin() + realPendIndex);
}

void	PmergeMe::binarySearchVec(jacobVec &main, jacobVec &pend, \
long &pairSize, long insertions, long n)
{
	for (long pendIndex = (pairSize * insertions) - 1; insertions != 0; pendIndex = (pairSize * --insertions) - 1)
	{
		long R = 0;
		long L = 0;
		for (; main.position.size() != static_cast<size_t>(R) && (( n > main.position[R] && main.aOrB[R] == "a") || main.aOrB[R] == "b"); R++){}
		if (n > 2)
			n--;
		for (size_t insertionConfirm = main.numbers.size() + pairSize; insertionConfirm != main.numbers.size();)
		{
			long m = ((((L + ((R - L) / 2))) * pairSize) - 1) < 0 ? 0 : ((((L + ((R - L) / 2))) * pairSize) - 1);
			std::cout << "pend size: " << pend.numbers.size() << std::endl;
			std::cout << "pendIndex: " << pendIndex << std::endl;
			std::cout << "main size: " << main.numbers.size() << std::endl;
			std::cout << "m + pairSize: " << (m + pairSize) << std::endl;
			std::cout << "m: " << m << std::endl;
			std::cout << "pairSize: " << pairSize << std::endl;
			long vecSize = static_cast<long>(main.numbers.size());
			if (m == vecSize - 1)
				insertPairInMainVec(main, pend, m, pairSize, pendIndex);
			else if ((pend.numbers[pendIndex] > main.numbers[m] && pend.numbers[pendIndex] < main.numbers[m + pairSize]))
				insertPairInMainVec(main, pend, m, pairSize, pendIndex);
			else if (m == pairSize - 1 && pend.numbers[pendIndex] < main.numbers[m])
				insertPairInMainVec(main, pend, -1, pairSize, pendIndex);
			else if ((pend.numbers[pendIndex] < main.numbers[m] && pend.numbers[pendIndex] > main.numbers[m - pairSize]))
				insertPairInMainVec(main, pend, m - pairSize, pairSize, pendIndex);
			else if (pend.numbers[pendIndex] > main.numbers[m])
				L = ((m + 1) / pairSize) + 1;
			else if (pend.numbers[pendIndex] < main.numbers[m])
				R = ((m + 1) / pairSize) - 1;
		}
	}
}

bool	PmergeMe::mainPendSeparationVec(jacobVec &main, jacobVec &pend,
long &pairSize, long &sizeVec)
{
	long index = 0;
	long pairFirst = 0;
	bool insertPend = true;

	if (sizeVec < (pairSize * 3))
		return true;
	for (std::vector<long>::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		if (index < (pairSize * 2))
			main.numbers.push_back(*it);
		else if (pairFirst + pairSize <= sizeVec)
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


void	PmergeMe::binaryInsertionVec(long &pairSize, long &sizeVec)
{
	jacobVec main;
	jacobVec pend;
	long jacobsthalN = 3;
	long prevJacobsthalN = 1;
	long n = 3;

	if (mainPendSeparationVec(main, pend, pairSize, sizeVec))
		return ;
	for(size_t insertions = jacobsthalN - prevJacobsthalN; insertions <= (pend.numbers.size() / pairSize); \
	insertions = jacobsthalN - prevJacobsthalN)
	{
		binarySearchVec(main, pend, pairSize, insertions, jacobsthalN);
		prevJacobsthalN = jacobsthalN;
		jacobsthalN = std::pow(2, n++) - jacobsthalN;
	}
	while (!pend.numbers.empty())
		binarySearchVec(main, pend, pairSize, 1, pend.position[0]);
	std::vector<long>::iterator itv = _vec.begin();
	for (std::vector<long>::iterator itm = main.numbers.begin(); itm != main.numbers.end(); itm++)
		*(itv++) = *itm;
}

void	PmergeMe::pairSortingVec(long &pairSize, long &sizeVec)
{
	std::vector<long> tmp;

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
	}
}

void	PmergeMe::mergeInsertionVec(long pairSize)
{
	long sizeVec = static_cast<long>(_vec.size());

	if (sizeVec <= 1 || pairSize > sizeVec / 2)
		return ;
	if (pairSize >= 2)
	{
		pairSortingVec(pairSize, sizeVec);
		mergeInsertionVec(pairSize * 2);
		binaryInsertionVec(pairSize, sizeVec);
	}
	else
	{
		mergeInsertionVec(pairSize * 2);
		binaryInsertionVec(pairSize, sizeVec);
	}
}
