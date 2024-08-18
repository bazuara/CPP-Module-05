/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:12 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 01:31:39 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main(void) {
  std::cout << std::endl
            << "******** Ex03 begins here: *********" << std::endl
            << std::endl;

  Bureaucrat fry = Bureaucrat("Philip J. Fry", 1);
  std::cout << fry << std::endl << std::endl;

  std::cout << "Testing interns:" << std::endl;
  Intern intern;
  AForm* form1 = intern.makeForm("shrubbery creation", "Home");
  AForm* form2 = intern.makeForm("robotomy request", "Bender");
  AForm* form3 = intern.makeForm("presidential pardon", "Zoidberg");

  fry.signForm(*form1);
  fry.executeForm(*form1);
  fry.signForm(*form2);
  fry.executeForm(*form2);
  fry.signForm(*form3);
  fry.executeForm(*form3);

  delete form1;
  delete form2;
  delete form3;

  return 0;
}
