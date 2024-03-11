/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:58:52 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/11 13:33:07 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

class RPN
{
private:
	std::stack<int> _stack;
	std::string	_str;

public:
	RPN(std::string str);
	~RPN();
	void	resolve();
	int	validExpression(std::string str);
};




#endif
