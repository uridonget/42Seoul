/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:27:16 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 15:37:38 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

static void	changeWord(std::string &line, std::string s1, std::string s2) {
	std::string::size_type N;
	std::string::size_type len;
	
	len = s1.length();
	while (true) {
		N = line.find(s1);
		if (N == std::string::npos)
			break ;
		line = line.substr(0, N) + s2 + line.substr(N + len);
	}
}

int	main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Wrong number of arguments(there should be three!)" << std::endl;
		return (1);
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open()) {
		std::cerr << "fail to open infile" << std::endl;
		return (1);
	}
	std::ofstream outfile((std::string(av[1]) + ".replace").c_str());
	if (!outfile.is_open()) {
		infile.close();
		std::cerr << "fail to open outfile" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(infile, line)) {
		changeWord(line, av[2], av[3]);
		outfile << line;
		if (infile.eof())
			break ;
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}