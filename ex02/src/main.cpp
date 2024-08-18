/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:12 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/18 22:19:19 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>

int main(void) {
  std::cout << std::endl
            << "******** Ex00 begins here: *********" << std::endl
            << std::endl;
  Bureaucrat hermes = Bureaucrat("Hermes Conrad", 150);
  Bureaucrat fry = Bureaucrat("Philip J. Fry", 1);

  std::cout << hermes << std::endl;
  std::cout << fry << std::endl;

  std::cout << std::endl
            << "******** Ex02 begins here: *********" << std::endl
            << std::endl;

  ShrubberyCreationForm f1 = ShrubberyCreationForm("culo");
  RobotomyRequestForm f2 = RobotomyRequestForm("culo");

  std::cout << f1 << std::endl;
  std::cout << f2 << std::endl;

  
  return 0;
}
