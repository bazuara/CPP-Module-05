/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:56:06 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 00:22:06 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("ShrubberyCreationForm", 145, 137) {
        this->setTarget(target);
    }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
    AForm::operator=(other);
    return *this;
    }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat const& b) {
    AForm::beSigned(b);
}

void ShrubberyCreationForm::setTarget(std::string const& target) {
    this->target = target;
}

std::string const& ShrubberyCreationForm::getTarget() const {
    return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    AForm::execute(executor);
    std::ofstream file(this->getTarget() + "_shrubbery");
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not create file");
    } else {
        file << "       _-_\n"
                "    /~~   ~~\\\n"
                " /~~         ~~\\\n"
                "{               }\n"
                " \\  _-     -_  /\n"
                "   ~  \\\\ //  ~\n"
                "_- -   | | _- _\n"
                "  _ -  | |   -_\n"
                "      // \\\\" << std::endl;
        file.close();
    }
}
