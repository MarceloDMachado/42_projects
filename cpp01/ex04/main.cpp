/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:45:18 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/13 12:31:40 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

std::string substitute(const char *line, char *s1, char *s2)
{
    std::string result;
    int         i;
    
    i = 0;
    while (line[i])
    {
        if (!strncmp(&line[i], s1, strlen(s1)))
        {
            result.append(s2);
            i += strlen(s1);
        }
        else
            result.push_back(line[i++]);
    }
    return (result);
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cerr << "Invalid arguments" << std::endl;
        return (1);
    }
    
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open the file: " << argv[1] << std::endl;
        return (1);
    }
    
    std::string newFile;
    std::string line;
    while (std::getline(inputFile, line))
	{
		newFile.append(substitute(line.c_str(), argv[2], argv[3]));
		if (!inputFile.eof())
			newFile.append("\n");
	}
	
    inputFile.close();
    
    std::ofstream outFile(std::string(argv[1]).append(".replace"));
    if (!outFile.is_open())
    {
        std::cerr << "Error: cannot write on " << std::string(argv[1]).append(".replace") << std::endl;
        return (1);
    }
    outFile << newFile;

    outFile.close();
    
    return (0);
}
