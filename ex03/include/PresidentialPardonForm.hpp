/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:28:56 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 01:24:17 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <AForm.hpp>

class PresidentialPardonForm : public AForm {
 private:
  std::string target;
  PresidentialPardonForm();

 public:
  explicit PresidentialPardonForm(std::string const& target);
  PresidentialPardonForm(PresidentialPardonForm const& other);
  PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
  ~PresidentialPardonForm();

  void setTarget(std::string const& target);
  std::string const& getTarget() const;

  void beSigned(Bureaucrat const& b);
  void execute(Bureaucrat const& executor) const;
};

#endif  // !PRESIDENTIALPARDONFORM_HPP
