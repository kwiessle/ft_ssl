/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:43:49 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/23 11:46:36 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_input		*input_init(char *message)
{
	t_input *new;

	if (!(new = malloc(sizeof(t_input))))
		return (NULL);
	new->message = message;
	new->len = ft_strlen(message) * 8;
	return (new);
}

char		*get_input(int fd)
{
	char	buf;
	char	*input;

	if (!(input = malloc(sizeof(char))))
		return (NULL);
	while (read(fd, &buf, sizeof(buf)) > 0)
		input = ft_strappend(input, buf);
	return (input);
}

size_t		get_padding_size(size_t len, int modulo, size_t congruent)
{
	size_t	result;

	result = len % modulo;
	if (result >= congruent)
		return (modulo + congruent) - result;
	return (congruent - result);
}

int			little_endian(uint32_t h)
{
	int		b0;
	int		b1;
	int		b2;
	int		b3;

	b0 = (h & 0xFF);
	b1 = (h & 0xFF00) >> 8;
	b2 = (h & 0xFF0000) >> 16;
	b3 = (h & 0xFF000000) >> 24;
	return (b0 << 24 | b1 << 16 | b2 << 8 | b3 << 0);
}
