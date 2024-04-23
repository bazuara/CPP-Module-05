/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratException.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:29:30 by bazuara           #+#    #+#             */
/*   Updated: 2024/04/23 10:31:05 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATEXCEPTION_HPP
#define BUREAUCRATEXCEPTION_HPP

#include <exception>
#include <iostream>
#include <string>

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

#endif  // BUREAUCRATEXCEPTION_HPP
