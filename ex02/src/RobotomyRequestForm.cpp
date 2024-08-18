/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:14:55 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/18 22:25:47 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>


// Required grades: sign 72, exec 45
// Makes some drilling noises.
// Then, informs that <target> has been robotomized successfully 50% of the time.
// Otherwise, informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyRequestForm", 72, 45) {
    // drilling noises
    std::cout << "Bzzzzzzzz Bzzzzzzz Bzzzzz A.K.A: Drilling noises" << std::endl;
    // robotomized successfully 50% of the time
    std::srand(std::time(0));
    if (rand() % 2) {
        std::cout << target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Robotomy failed" << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) : AForm(other) {
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other) {
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::beSigned(Bureaucrat const& b) {
    AForm::beSigned(b);
}