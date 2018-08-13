/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:25:37 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 14:29:21 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"



uint32_t        sha256_p0(t_sha256 *s, int p)
{
    return R_ROT(s->w[p -15], 7) ^ R_ROT(s->w[p -15], 18) ^ s->w[p -15] >> 3;
}

uint32_t        sha256_p1(t_sha256 *s, int p)
{
    return R_ROT(s->w[p -2], 17) ^ R_ROT(s->w[p -2], 19) ^ s->w[p -2] >> 10;
}

uint32_t        sha256_word(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    return a << 24 | b << 16 | c << 8 | d;
}
