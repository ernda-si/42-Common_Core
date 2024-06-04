/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:48:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/04 12:54:53 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_puthexadress(unsigned int nb);
int	ft_puthexasmall(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_puthexabig(unsigned int nb);
int	ft_putunbr(unsigned int unb);

#endif