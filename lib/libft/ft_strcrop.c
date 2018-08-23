/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:28:50 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/23 15:39:20 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		is_inside(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

int			ft_stroccur(char *str, char *set)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (is_inside(str[i], set) == true)
			n++;
		i++;
	}
	return (n);
}

char		*ft_strcrop(char *str, char *set)
{
	char	*result;
	int		s_len;
	int		n;
	int		i;

	s_len = ft_strlen(str);
	n = ft_stroccur(str, set);
	result = ft_strnew(s_len - n);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (is_inside(str[i], set) == false)
		{
			result[n] = str[i];
			n++;
		}
		i++;
	}
	return (result);
}
