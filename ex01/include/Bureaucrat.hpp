/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:50:26 by bazuara           #+#    #+#             */
/*   Updated: 2024/05/25 11:38:18 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
 private:
  std::string const name;
  int grade;

 public:
  Bureaucrat(std::string const name, int grade);
  Bureaucrat(Bureaucrat const& other);
  Bureaucrat& operator=(Bureaucrat const& other);
  ~Bureaucrat();

  std::string const& getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  void signForm(Form& f);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif  // BUREAUCRAT_HPP
