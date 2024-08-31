/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:14:55 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/31 17:52:17 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

// Required grades: sign 72, exec 45
// Makes some drilling noises.
// Then, informs that <target> has been robotomized successfully 50% of the time.
// Otherwise, informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm("RobotomyRequestForm", 72, 45) {
  setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
    : AForm(other) {
  *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& other) {
  AForm::operator=(other);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::setTarget(std::string const& target) {
  this->target = target;
}

std::string const& RobotomyRequestForm::getTarget() const {
  return this->target;
}

void RobotomyRequestForm::beSigned(Bureaucrat const& b) {
  AForm::beSigned(b);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  AForm::execute(executor);
  // drilling noises
  std::cout << "Bzzzzzzzz Bzzzzzzz Bzzzzz A.K.A: Drilling noises" << std::endl;
  // robotomized successfully 50% of the time
  srand(std::time(0));
  if (rand() % 2) {
    std::cout << this->getTarget() << " has been robotomized successfully"
              << std::endl;
  } else {
    std::cout << "Robotomy failed" << std::endl;
  }
}