/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:49:34 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/31 18:04:50 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

class Intern {
 private:
  AForm* createShrubberyCreationForm(std::string target);
  AForm* createRobotomyRequestForm(std::string target);
  AForm* createPresidentialPardonForm(std::string target);

 public:
  Intern();
  Intern(const Intern& other);
  ~Intern();
  Intern& operator=(const Intern& other);

  AForm* makeForm(std::string formName, std::string target);
  class FormNotFoundException : public std::exception {
   private:
    std::string message;

   public:
    FormNotFoundException();
    const char* what() const throw();
    virtual ~FormNotFoundException() throw();
  };
};

#endif  // !INTERN_HPP
