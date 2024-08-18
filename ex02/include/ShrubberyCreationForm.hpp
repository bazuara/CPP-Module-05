/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:49:14 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/18 21:59:19 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <AForm.hpp>
#include <fstream>

// Class ShrubberyCreationForm : public AForm
// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(std::string const& target);
  ShrubberyCreationForm(ShrubberyCreationForm const& other);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
  ~ShrubberyCreationForm();

  void beSigned(Bureaucrat const& b);
  void execute(Bureaucrat const& executor) const;
};



#endif // !SHRUBBERYCREATIONFORM_HPP