/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 11:41:29 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <AForm.hpp>

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
  this->signature = false;
}

AForm::AForm(AForm const& other)
    : name(other.name),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute),
      signature(other.signature) {}

AForm& AForm::operator=(AForm const& other) {
  this->signature = other.signature;
  return *this;
}

AForm::~AForm() {}

std::string const& AForm::getName() const {
  return this->name;
}

bool AForm::getSignature() const {
  return this->signature;
}

int AForm::getGradeToSign() const {
  return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
  return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat const& b) {
  if (b.getGrade() > this->gradeToSign) {
    throw GradeTooLowException();
  }
  this->signature = true;
}

// GradeTooHighExceptions
AForm::GradeTooHighException::GradeTooHighException() {
  this->message = "Grade is too high";
}

const char* AForm::GradeTooHighException::what() const throw() {
  return this->message.c_str();
}

// GradeTooLowExceptions
AForm::GradeTooLowException::GradeTooLowException() {
  this->message = "Grade is too low";
}
const char* AForm::GradeTooLowException::what() const throw() {
  return this->message.c_str();
}

// << overload

std::ostream& operator<<(std::ostream& os, const AForm& f) {
  os << "AForm: " << f.getName() << std::endl
     << "Signed: " << f.getSignature() << std::endl
     << "Grade to sign: " << f.getGradeToSign() << std::endl
     << "Grade to execute: " << f.getGradeToExecute() << std::endl;
  return os;
}
