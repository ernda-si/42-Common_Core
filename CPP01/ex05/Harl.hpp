/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:47:17 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/09 18:47:19 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <string>

class   Harl {
	
private:

	void    debug( void );

	void    info( void );

	void    warning( void );

	void    error( void );

public:

	Harl() {};

	~Harl() {};

	void complain( std::string level );

};

#endif