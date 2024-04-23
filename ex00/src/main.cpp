/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:12 by bazuara           #+#    #+#             */
/*   Updated: 2024/04/23 10:43:34 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bureaucrat.hpp>

int main(void) {
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

  return 0;
}
