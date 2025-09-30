/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:58 by eve               #+#    #+#             */
/*   Updated: 2025/09/30 18:10:23 by eve              ###   ########.fr       */
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

	void complain( std::string level );

};

#endif