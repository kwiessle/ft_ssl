/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_drop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:51:06 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/23 15:15:29 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_drop(char *str, char drop)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != drop)
			ft_putchar(str[i]);
		i++;
	}
}
