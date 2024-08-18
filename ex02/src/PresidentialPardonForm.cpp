/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:01:54 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 00:26:46 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", 25, 5) {
        this->setTarget(target);
    }
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other)
    : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other) {
    AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::setTarget(std::string const& target) {
    this->target = target;
}

std::string const& PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::beSigned(Bureaucrat const& b) {
    AForm::beSigned(b);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    AForm::execute(executor);
        std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}