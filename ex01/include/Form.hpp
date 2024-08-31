/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:22:07 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 11:41:07 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  std::string const name;
  bool signature;
  int const gradeToSign;
  int const gradeToExecute;
  Form();

 public:
  Form(std::string const name, int gradeToSign, int gradeToExecute);
  Form(Form const& other);
  Form& operator=(Form const& other);
  ~Form();

  std::string const& getName() const;
  bool getSignature() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(Bureaucrat const& b);

  class GradeTooHighException : public std::exception {
   private:
    std::string message;

   public:
    GradeTooHighException();
    const char* what() const throw();
    virtual ~GradeTooHighException() throw();
  };

  class GradeTooLowException : public std::exception {
   private:
    std::string message;

   public:
    GradeTooLowException();
    const char* what() const throw();
    virtual ~GradeTooLowException() throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif  // !FORM_HPP
