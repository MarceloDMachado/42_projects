/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:25:48 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/17 16:29:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("default", GRADE_TO_SIGN, GRADE_TO_EXECUTE)
{
    this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrubbery Creation Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target)
{
    this->isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm("Shrubbery Creation Form", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(other.target)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->target = other.target;    
        this->isSigned = other.isSigned;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    checkGradeToExecute(executor.getGrade());
    std::cout << executor.getName() << " executed Shrubbery Creation 🌳" << std::endl;
    
    plantShrubbery();
}

void    ShrubberyCreationForm::plantShrubbery(void) const 
{
    std::ofstream file(std::string(target).append("_shrubbery").c_str());

    file << " " << std::endl;
    file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
    file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
    file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
    file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
    file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
    file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
    file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
    file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
    file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
    file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
    file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
    file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
    file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
    file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
    file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
    file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
    file << "             {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
    file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
    file << "              (_)  \\.-'.-/" << std::endl;
    file << "          __...--- |'-.-'| --...__" << std::endl;
    file << "   _...--\"   .-'   |'-.-'|  ' -.  ""--..__" << std::endl;
    file << " -\"    ' .  . '    |.'-._| '  . .  '   " << std::endl;
    file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
    file << "          ' ..     |'-_.-|" << std::endl;
    file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
    file << "              .'   |'- .-|   '." << std::endl;
    file << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
    file << "   .-' '        '-._______.-'     '  ." << std::endl;
    file << " " << std::endl;
    file.close();
}

