/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:51:33 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/31 18:05:09 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
  *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
  AForm* form = 0;

  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};

  AForm* (Intern::*formCreators[3])(std::string target) = {
      &Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm,
      &Intern::createPresidentialPardonForm};

  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      form = (this->*formCreators[i])(target);
      break;
    }
  }

  if (form == 0) {
    throw Intern::FormNotFoundException();
  }

  return form;
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

Intern::FormNotFoundException::FormNotFoundException() {
  this->message = "Form not found";
}

const char* Intern::FormNotFoundException::what() const throw() {
  return this->message.c_str();
}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}
