#include "headers/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int> mstack1;
	mstack1 = mstack;

	MutantStack<int>::iterator it = mstack1.begin();
	MutantStack<int>::iterator ite = mstack1.end();

	++it;
	--it;
	int i = 0;
	while (it != ite)
	{
		std::cout << RED << "stack[" << i++ << "] = " << RESET << *it << std::endl;
		++it;
	}
	std::cout << RED << "stack" << YELLOW <<  ".size() = " << RESET << mstack.size() << std::endl;
	std::cout << std::endl;

	MutantStack<int> mstack2(mstack);

	MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack2.rend();

	std::cout << BLUE << "stack2" << YELLOW << ".size() = " << RESET << mstack2.size() << std::endl;

	++rit;
	--rit;

	while (rit != rite)
	{
		std::cout << BLUE << "stack2[" << --i << "] = " << RESET << *rit << std::endl;
		++rit;
	}
	std::stack<int> s(mstack);
	return 0;
}
