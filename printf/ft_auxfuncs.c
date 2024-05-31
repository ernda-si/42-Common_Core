/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:21:54 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/31 16:23:35 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_puthexadress(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_puthexadress(nb / 16);
	if (i == 0)
		i += write (1, "0x", 2);
	i += write(1, &"0123456789abcdef"[nb % 16], 1);
	return (i);
}

int	ft_puthexasmall(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_puthexasmall(nb / 16);
	i += write(1, &"0123456789abcdef"[nb % 16], 1);
	return (i);
}

int	ft_puthexabig(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_puthexabig(nb / 16);
	i += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	return (i);
}

int	ft_putunbr(unsigned int unb)
{
	int	i;

	i = 0;
	if (unb > 9)
		i += ft_putunbr(unb / 10);
	i += write(1, &"0123456789"[unb % 10], 1);
	return (i);
}
