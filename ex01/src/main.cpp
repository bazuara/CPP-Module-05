/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:12 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 12:11:13 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

int main(void) {
  std::cout << std::endl
            << "******** Ex00 begins here: *********" << std::endl
            << std::endl;
  Bureaucrat hermes = Bureaucrat("Hermes Conrad", 150);
  Bureaucrat fry = Bureaucrat("Philip J. Fry", 1);

  std::cout << hermes << std::endl;
  std::cout << fry << std::endl;

  std::cout << "Incrementing and decrementing grades properly working:"
            << std::endl;
  std::cout << hermes << std::endl;
  try {
    hermes.incrementGrade();
    std::cout << hermes << std::endl;
    hermes.incrementGrade();
    std::cout << hermes << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << fry << std::endl;
  try {
    fry.decrementGrade();
    std::cout << fry << std::endl;
    fry.decrementGrade();
    std::cout << fry << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Trying to increment and decrement grades out of bounds:"
            << std::endl;
  try {
    hermes.decrementGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    fry.incrementGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat bender = Bureaucrat("Bender Bending Rodriguez", 0);
    std::cout << bender << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat leela = Bureaucrat("Turanga Leela", 151);
    std::cout << leela << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl
            << "******** Ex01 begins here: *********" << std::endl
            << std::endl;

  Form f1 = Form("Form 1", 1, 1);
  Form f2 = Form("Form 2", 140, 140);

  std::cout << f1 << std::endl;
  std::cout << f2 << std::endl;

  std::cout << std::endl
            << "Trying to create forms with grades out of bounds:" << std::endl;
  try {
    std::cout << std::endl << "------ Test ------" << std::endl;
    Form f3 = Form("Form 3", 0, 0);
    std::cout << f3 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "--- End of test --" << std::endl << std::endl;

  try {
    std::cout << std::endl << "------ Test ------" << std::endl;
    Form f4 = Form("Form 4", 151, 151);
    std::cout << f4 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "--- End of test --" << std::endl << std::endl;

  std::cout << std::endl
            << "Trying to sign forms with grades out of bounds:" << std::endl;
  try {
    std::cout << std::endl << "------ Test ------" << std::endl;
    std::cout << f1 << std::endl;
    std::cout << std::endl << fry << std::endl;
    fry.signForm(f1);
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  std::cout << "--- End of test --" << std::endl << std::endl;

  try {
    std::cout << std::endl << "------ Test ------" << std::endl;
    std::cout << f2 << std::endl;
    std::cout << std::endl << hermes << std::endl;
    hermes.signForm(f2);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "--- End of test --" << std::endl << std::endl;

  std::cout << std::endl
            << "Trying to sign forms with proper grades from Bureaucrat:"
            << std::endl;
  try {
    std::cout << std::endl << "------ Test ------" << std::endl;
    fry.incrementGrade();
    std::cout << f1 << std::endl;
    std::cout << std::endl << fry << std::endl;
    fry.signForm(f1);
    std::cout << f1 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  std::cout << "--- End of test --" << std::endl << std::endl;

  std::cout << std::endl
            << "Trying to sign forms with proper grades from Form:"
            << std::endl;

  try {
    std::cout << std::endl << "------ Test ------" << std::endl;
    std::cout << f2 << std::endl;
    std::cout << std::endl << fry << std::endl;
    f2.beSigned(fry);
    std::cout << f2 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
