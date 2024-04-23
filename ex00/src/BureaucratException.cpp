/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:08:29 by bazuara           #+#    #+#             */
/*   Updated: 2024/04/23 10:29:52 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BureaucratException.hpp>

// GradeTooHighExceptions
GradeTooHighException::GradeTooHighException() {
  this->message = "Grade is too high";
}

const char* GradeTooHighException::what() const throw() {
  return this->message.c_str();
}

// GradeTooLowExceptions
GradeTooLowException::GradeTooLowException() {
  this->message = "Grade is too low";
}
const char* GradeTooLowException::what() const throw() {
  return this->message.c_str();
}
