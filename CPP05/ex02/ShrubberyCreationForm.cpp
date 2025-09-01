/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:21:03 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 16:36:46 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//CONSTRUCTORS & DESTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm()
 : AForm("ShrubberyCreationForm", "Default", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 : AForm("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original)
 : AForm(original._name, original._target, original._gradeToSign, original._gradeToExec)
{
	*this = original;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

//OPERATORS
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	if (this != &original && original.getSigned() == true)
		_signed = original._signed;
	return (*this);
}

//MEMBER FUNCTIONS
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
	std::string fileName = _target + "_shrubbery";
	std::ofstream outFile(fileName.c_str(), std::fstream::app);
	if (!outFile.is_open() || outFile.fail())
		std::cerr << "Error opening file in ShrubberyCreationForm" <<\
	std::endl;
	outFile << std::endl <<\
"              _{\\ _{\\{\\/}/}/}__             " << std::endl <<\
"             {/{/\\}{/{/\\}(\\}{/\\} _          " << std::endl <<\
"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _      " << std::endl <<\
"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}     " << std::endl <<\
"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}      " << std::endl <<\
"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}      " << std::endl <<\
"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}     " << std::endl <<\
"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}     " << std::endl <<\
"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}    " << std::endl <<\
"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}   " << std::endl <<\
"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)    " << std::endl <<\
"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}    " << std::endl <<\
"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}    " << std::endl <<\
"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}    " << std::endl <<\
"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)     " << std::endl <<\
"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}         " << std::endl <<\
"             {/{\\{\\{\\/}/}{\\{\\\\}/}           " << std::endl <<\
"              {){/ {\\/}{\\/} \\}\\}            " << std::endl <<\
"              (_)  \\.-'.-/                  " << std::endl <<\
"          __...--- |'-.-'| --...__          " << std::endl <<\
"   _...--    .-'   |'-.-'|  ' -.  --..__    " << std::endl <<\
" -     ' .  . '    |.'-._| '  . .  '   ;    " << std::endl <<\
" .  '-  '    .--'  | '-.'|    .  '  . '     " << std::endl <<\
"          ' ..     |'-_.-|                  " << std::endl <<\
"  .  '  .       _.-|-._ -|-._  .  '  .      " << std::endl <<\
"              .'   |'- .-|   '.             " << std::endl <<\
"  ..-'   ' .  '.   `-._.-'   .'  '  - .     " << std::endl <<\
"   .-' '        '-._______.-'     '  .      " << std::endl <<\
"        .      ~,                      .    " << std::endl <<\
"    .       .   |    .    ' '-.     '     ' " << std::endl <<\
std::endl;
outFile.close();
}
