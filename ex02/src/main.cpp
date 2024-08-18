/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:12 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 00:40:27 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main(void) {
  std::cout << std::endl
            << "******** Ex02 begins here: *********" << std::endl
            << std::endl;
  
  Bureaucrat fry = Bureaucrat("Philip J. Fry", 1);
  std::cout << fry << std::endl << std::endl;


  ShrubberyCreationForm f1 = ShrubberyCreationForm("culo");
  RobotomyRequestForm f2 = RobotomyRequestForm("culo");
  PresidentialPardonForm f3 = PresidentialPardonForm("culo");


  std::cout << f1 << std::endl;
  std::cout << f2 << std::endl;
  std::cout << f3 << std::endl;

  std::cout << "***** ShrubberyCreationForm *****" << std::endl;
  try {
    f1.execute(fry);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  f1.beSigned(fry);
  f1.execute(fry);
  std::cout << "***** End ShrubberyCreationForm *****" << std::endl << std::endl;


  std::cout << "***** RobotomyRequestForm *****" << std::endl;
  try {
    f2.execute(fry);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  f2.beSigned(fry);
  f2.execute(fry);
  std::cout << "***** End RobotomyRequestForm *****" << std::endl << std::endl;

  std::cout << "***** PresidentialPardonForm *****" << std::endl;
  try {
    f3.execute(fry);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  f3.beSigned(fry);
  f3.execute(fry);
  std::cout << "***** End PresidentialPardonForm *****" << std::endl << std::endl;

  std::cout << "***** Testing bureaucrat executing forms *****" << std::endl;
  std::cout << "***** ShrubberyCreationForm *****" << std::endl;
  fry.executeForm(f1);
  std::cout << "***** RobotomyRequestForm *****" << std::endl;
  fry.executeForm(f2);
  std::cout << "***** PresidentialPardonForm *****" << std::endl;
  fry.executeForm(f3);
  std::cout << "***** End testing bureaucrat executing forms *****" << std::endl;

  return 0;
}
