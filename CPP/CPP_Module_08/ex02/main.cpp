#include "headers/MutantStack.hpp"
#include <list>
int main()
{

	std::cout << std::endl << PURPLE << "TEST 1 with MutantStack.\n\n" << RESET;

	{
		std::cout << std::endl << "create a MutantStack<int>" << std::endl << std::endl;
		MutantStack<int> mstack;
		std::cout << "adding 5, then 17 to the stack" << std::endl;
		mstack.push(5);
		mstack.push(17);

		std::cout << std::endl << "element on top : " << YELLOW << mstack.top()  << RESET << std::endl;
		std::cout << std::endl << "removing element on top." << std::endl;
		mstack.pop();

		std::cout << std::endl << "numbers of elements in the stack : " << GREEN << mstack.size() << RESET << std::endl;

		std::cout << "adding 3, 5, 737 and 0 to the stack." << std::endl << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int> mstack1;
		mstack1 = mstack;

		std::cout << "creating 2 " << YELLOW << "iterators " << RESET << "of " << RED << "stack" << RESET << "." << std::endl << std::endl;
		MutantStack<int>::iterator it = mstack1.begin();
		MutantStack<int>::iterator ite = mstack1.end();

		int i = 0;
		while (it != ite)
		{
			std::cout << RED << "stack[" << i++ << "] = " << RESET << *it << std::endl;
			++it;
		}
		std::cout << RED << "stack" << GREEN <<  ".size() = " << mstack.size() << RESET << std::endl;
		std::cout << std::endl;

		std::cout << "creating new MutantStack" << BLUE << " stack2" << RESET << " by copying " << RED << "stack" << RESET <<"." << std::endl << std::endl;
		MutantStack<int> mstack2(mstack);

		std::cout << "creating 2 " << YELLOW << "reverse_iterators " << RESET << "of " << BLUE << "stack2" << RESET << "." << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack2.rend();

		std::cout << BLUE << "stack2" << GREEN << ".size() = " << mstack2.size() << RESET << std::endl;

		while (rit != rite)
		{
			std::cout << BLUE << "stack2[" << --i << "] = " << RESET << *rit << std::endl;
			++rit;
		}
	}

	std::cout << PURPLE << "\n\n\nTEST 2 with list.\n\n" << RESET;

	{
		std::cout << std::endl << "create a std::list<int>" << std::endl << std::endl;
		std::list<int> list;
		std::cout << "adding 5, then 17 to the list" << std::endl;
		list.push_back(5);
		list.push_back(17);

		std::cout << std::endl << "element on back : " << YELLOW << list.back()  << RESET << std::endl;
		std::cout << std::endl << "removing last element." << std::endl;
		list.pop_back();

		std::cout << std::endl << "numbers of elements in the list : " << GREEN << list.size() << RESET << std::endl;

		std::cout << "adding 3, 5, 737 and 0 to the list." << std::endl << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int> list1;
		list1 = list;

		std::cout << "creating 2 " << YELLOW << "iterators " << RESET << "of " << RED << "list" << RESET << "." << std::endl << std::endl;
		std::list<int>::iterator it = list1.begin();
		std::list<int>::iterator ite = list1.end();

		++it;
		--it;
		int i = 0;
		while (it != ite)
		{
			std::cout << RED << "list[" << i++ << "] = " << RESET << *it << std::endl;
			++it;
		}
		std::cout << RED << "list" << GREEN <<  ".size() = " << list.size() << RESET << std::endl;
		std::cout << std::endl;

		std::cout << "creating new std::list" << BLUE << " list2" << RESET << " by copying " << RED << "list" << RESET <<"." << std::endl << std::endl;
		std::list<int> list2(list);

		std::cout << "creating 2 " << YELLOW << "reverse_iterators " << RESET << "of " << BLUE << "list2" << RESET << "." << std::endl;
		std::list<int>::reverse_iterator rit = list2.rbegin();
		std::list<int>::reverse_iterator rite = list2.rend();

		std::cout << BLUE << "list2" << GREEN << ".size() = " << list2.size() << RESET << std::endl;

		while (rit != rite)
		{
			std::cout << BLUE << "list2[" << --i << "] = " << RESET << *rit << std::endl;
			++rit;
		}
	}

	return 0;
}
