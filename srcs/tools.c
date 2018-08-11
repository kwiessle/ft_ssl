/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:14:07 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/11 15:07:44 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"



t_input *input_init(char *message)
{
    t_input *new;

    if (!(new = malloc(sizeof(t_input))))
        return NULL;
    new->message = message;
    new->len = ft_strlen(message) * 8;

    return new;
}

char    *get_input(int fd)
{
    char    buf;
    char    *input;

    if (!(input = malloc(sizeof(char))))
        return NULL;
    while (read(fd, &buf, sizeof(buf)) > 0)
        input = ft_strappend(input, buf);

    return (input);
}

size_t      get_padding_size(size_t len)
{
    size_t modulo;

    modulo = len % 512;

    if (modulo >= 448)
        return 960 - modulo;
    return 448 - modulo;
}

int     little_endian(uint32_t h)
{
    int b0, b1, b2, b3;
    b0 = (h & 0x000000FF) >> 0;
    b1 = (h & 0x0000FF00) >> 8;
    b2 = (h & 0x00FF0000) >> 16;
    b3 = (h & 0xFF000000) >> 24;
    return b0 << 24 | b1 << 16 | b2 << 8 | b3 << 0;
}

static long	max_power(long nb, int base)
{
	long max;

	max = base;
	while (max < nb)
		max *= base;
	if (max > nb)
		max /= base;
	return (max);
}

void    print_hex(unsigned int n)
{
    static char     hex[16] = "0123456789abcdef";
    long            power = max_power(n, 16);

    while (power > 0) {
        ft_putchar(hex[n / power]);
        n %= power;
        power = power / 16;
    }
}
