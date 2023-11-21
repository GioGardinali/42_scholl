/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:10:41 by gigardin          #+#    #+#             */
/*   Updated: 2023/10/28 15:51:15 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrun(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_nbrun(nbr / 10);
	}
	ft_putchar_fd((char)(nbr % 10 + 48), 1);
	return (ft_nbrlen(nbr));
}
