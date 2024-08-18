/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:22:07 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 11:41:07 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
 private:
  std::string const name;
  bool signature;
  int const gradeToSign;
  int const gradeToExecute;

 public:
  AForm(std::string const name, int gradeToSign, int gradeToExecute);
  AForm(AForm const& other);
  AForm& operator=(AForm const& other);
  ~AForm();

  std::string const& getName() const;
  bool getSignature() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  virtual void beSigned(Bureaucrat const& b) = 0;

  class GradeTooHighException : public std::exception {
   private:
    std::string message;

   public:
    GradeTooHighException();
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   private:
    std::string message;

   public:
    GradeTooLowException();
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif  // !AForm_HPP
