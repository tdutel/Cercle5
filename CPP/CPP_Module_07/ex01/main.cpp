/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:09:52 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/09 12:16:56 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Iter.hpp"

template <typename T>
void	print(T& element){
	std::cout << element << std::endl;
}

template <typename T>
void	tolower(T& element){
	char el = element - 32;
	std::cout << el << std::endl;
}

int	main()
{
	std::cout << "int tab : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << std::endl << std::endl;
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	iter<int, size_t, void>(tab, 10, &print);
	std::cout << std::endl;
	
	std::cout << "char tab : \"eh yoo welcome\"" << std::endl << std::endl;
	char chab[] = "eh yoo welcome";
	iter<char, size_t, void>(chab, 14, &print);
	std::cout << std::endl;
	std::cout << "Now with tolower function :" << std::endl << std::endl;
	iter<char, size_t, void>(chab, 14, &tolower);
	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
