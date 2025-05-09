/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:54:48 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 11:40:33 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n) {
  // std::cout << "Bureaucrat constructor called" << std::endl
  //           << "with params: " << std::endl
  //           << "n: :" << n << std::endl
  //           << "g: " << g << std::endl;
  if (g < 1) {
    throw GradeTooHighException();
  } else if (g > 150) {
    throw GradeTooLowException();
  } else {
    this->grade = g;
  }
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) {
  *this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
  // name is a constant so it should be out of the assignment operator
  // this->name(other.getName());
  this->grade = other.getGrade();
  return *this;
}

std::string const& Bureaucrat::getName() const {
  return this->name;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  if (this->grade == 1) {
    throw GradeTooHighException();
  } else {
    this->grade--;
  }
}

void Bureaucrat::decrementGrade() {
  if (this->grade == 150) {
    throw GradeTooLowException();
  } else {
    this->grade++;
  }
}

void Bureaucrat::signForm(Form& f) {
  try {
    f.beSigned(*this);
    std::cout << this->name << " signed " << f.getName() << std::endl;
  } catch (Form::GradeTooLowException& e) {
    std::cout << this->name << " cannot sign " << f.getName() << " because "
              << e.what() << std::endl;
  }
}

// GradeTooHighExceptions
Bureaucrat::GradeTooHighException::GradeTooHighException() {
  this->message = "Grade is too high";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return this->message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

// GradeTooLowExceptions
Bureaucrat::GradeTooLowException::GradeTooLowException() {
  this->message = "Grade is too low";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return this->message.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

// << operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}