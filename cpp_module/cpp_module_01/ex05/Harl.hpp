/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:27:44 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/12 15:58:28 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		
	public :
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif