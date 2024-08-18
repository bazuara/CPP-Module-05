/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:13:02 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 00:23:11 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <AForm.hpp>
#include <ctime>

class RobotomyRequestForm : public AForm {

 private:
  std::string target;
 public:
  RobotomyRequestForm(std::string const& target);
  RobotomyRequestForm(RobotomyRequestForm const& other);
  RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
  ~RobotomyRequestForm();

  void setTarget(std::string const& target);
  std::string const& getTarget() const;

  void beSigned(Bureaucrat const& b);
  void execute(Bureaucrat const& executor) const;
};

#endif // !ROBOTOMYREQUESTFORM_HPP