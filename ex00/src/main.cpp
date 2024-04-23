/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:12 by bazuara           #+#    #+#             */
/*   Updated: 2024/04/23 09:21:13 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bureaucrat.hpp>

int main(void) {
  Bureaucrat hermes = Bureaucrat("Hermes Conrad", 150);
  Bureaucrat fry = Bureaucrat("Philip J. Fry", 1);

  std::cout << hermes << std::endl;
  std::cout << fry << std::endl;

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
