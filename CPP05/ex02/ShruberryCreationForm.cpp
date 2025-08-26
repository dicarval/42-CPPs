/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:21:03 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 16:28:42 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

//CONSTRUCTORS & DESTRUCTOR
ShruberryCreationForm::ShruberryCreationForm(std::string target)
	: AForm("ShruberryCreationForm", 145, 137), _fileName(target + "_shruberry")
{}

ShruberryCreationForm::~ShruberryCreationForm()
{}

int	ShruberryCreationForm::execute(const Bureaucrat &executor)
{
	if (checkToExecute(executor) != SUCCESS)
		return (NOT_EXECUTED);
	std::ofstream outFile(_fileName.c_str(), std::fstream::app);
	if (!outFile.is_open() || outFile.fail())
		return (std::cerr << "Error opening file in ShruberryCreationForm" <<\
		 std::endl, NOT_EXECUTED);
	outFile <<\
"              _{\ _{\{\/}/}/}__             " << std::endl <<\
"             {/{/\}{/{/\}(\}{/\} _          " << std::endl <<\
"            {/{/\}{/{/\}(_)\}{/{/\}  _      " << std::endl <<\
"         {\{/(\}\}{/{/\}\}{/){/\}\} /\}     " << std::endl <<\
"        {/{/(_)/}{\{/)\}{\(_){/}/}/}/}      " << std::endl <<\
"       _{\{/{/{\{/{/(_)/}/}/}{\(/}/}/}      " << std::endl <<\
"      {/{/{\{\{\(/}{\{\/}/}{\}(_){\/}\}     " << std::endl <<\
"      _{\{/{\{/(_)\}/}{/{/{/\}\})\}{/\}     " << std::endl <<\
"     {/{/{\{\(/}{/{\{\{\/})/}{\(_)/}/}\}    " << std::endl <<\
"      {\{\/}(_){\{\{\/}/}(_){\/}{\/}/})/}   " << std::endl <<\
"       {/{\{\/}{/{\{\{\/}/}{\{\/}/}\}(_)    " << std::endl <<\
"      {/{\{\/}{/){\{\{\/}/}{\{\(/}/}\}/}    " << std::endl <<\
"       {/{\{\/}(_){\{\{\(/}/}{\(_)/}/}\}    " << std::endl <<\
"         {/({/{\{/{\{\/}(_){\/}/}\}/}(\}    " << std::endl <<\
"          (_){/{\/}{\{\/}/}{\{\)/}/}(_)     " << std::endl <<\
"            {/{/{\{\/}{/{\{\{\(_)/}         " << std::endl <<\
"             {/{\{\{\/}/}{\{\\}/}           " << std::endl <<\
"              {){/ {\/}{\/} \}\}            " << std::endl <<\
"              (_)  \.-'.-/                  " << std::endl <<\
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
