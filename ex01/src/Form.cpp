/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 11:41:29 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
  this->signature = false;
}

Form::Form(Form const& other)
    : name(other.name),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute),
      signature(other.signature) {}

Form& Form::operator=(Form const& other) {
  this->signature = other.signature;
  return *this;
}

Form::~Form() {}

std::string const& Form::getName() const {
  return this->name;
}

bool Form::getSignature() const {
  return this->signature;
}

int Form::getGradeToSign() const {
  return this->gradeToSign;
}

int Form::getGradeToExecute() const {
  return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat const& b) {
  if (b.getGrade() > this->gradeToSign) {
    throw GradeTooLowException();
  }
  this->signature = true;
}

// GradeTooHighExceptions
Form::GradeTooHighException::GradeTooHighException() {
  this->message = "Grade is too high";
}

const char* Form::GradeTooHighException::what() const throw() {
  return this->message.c_str();
}

// GradeTooLowExceptions
Form::GradeTooLowException::GradeTooLowException() {
  this->message = "Grade is too low";
}
const char* Form::GradeTooLowException::what() const throw() {
  return this->message.c_str();
}

// << overload

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << "Form: " << f.getName() << std::endl
     << "Signed: " << f.getSignature() << std::endl
     << "Grade to sign: " << f.getGradeToSign() << std::endl
     << "Grade to execute: " << f.getGradeToExecute() << std::endl;
  return os;
}
