/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:15 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/24 14:38:52 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:

// Constructor Destructor //
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	ShrubberyCreationForm(const std::string target);
	~ShrubberyCreationForm();

// operator //
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

// get //
     std::string    getTarget();

// function // 
     void      execute(Bureaucrat const & executor) const;

private:

	std::string _target;
};

// std::ostream&	operator<<(std::ostream &out, const ShrubberyCreationForm& B);

#endif
/*


      \,`\"\"\',
      ;\' \` ;
      ;^__^;
      ;\' ` ;
 ,,,  ;\`,\',;
;\,` ; ;\' ` ;   ,',
;\`,'; ;`,',;  ;,' ;
;',`; ;` ' ; ;`'`';
;` '',''` `,',`',;
 `''`'; ', ;`'`'
      ;' `';
      ;` ' ;
      ;' `';
      ;` ' ;
      ; ',';
      ;,' ';
    \|/\|/;\|/



          .     .  .      +     .      .          .
     .       .      .     #       .           .
        .      .         ###            .      .      .
      .      .   "#:. .:##"##:. .:#"  .      .
          .      . "####"###"####"  .
       .     "#:.    .:#"^O^"#:.    .:#"  .        .       .
  .             "#########"#########"        .        .
        .    "#:.  "####"###"####"  .:#"   .       .
     .     .  "#######""##"##""#######"                  .
                ."##"#####"#####"##"           .      .
    .   "#:. ...  .:##"###"###"##:.  ... .:#"     .
      .     "#######"##"#####"##"#######"      .     .
    .    .     "#####""#######""#####"    .      .
            .     "      000      "    .     .
       .         .   .   000     .        .       .
.. .. ..................O000O........................ ...... ...


*/
