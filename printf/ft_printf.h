/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:59:27 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/06 18:10:02 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_puthexadress(unsigned long nb);
int	ft_puthexasmall(unsigned int nb);
int	ft_puthexabig(unsigned int nb);
int	ft_putunbr(unsigned int unb);
int	ft_printf(const char *str, ...);

#endif