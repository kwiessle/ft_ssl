/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:15:21 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 15:56:26 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"



uint64_t        sha512_p0(t_sha512 *s, int p)
{
    return R_ROT64(s->w[p -15], 1) ^ R_ROT64(s->w[p -15], 8) ^ s->w[p -15] >> 7;
}

uint64_t        sha512_p1(t_sha512 *s, int p)
{
    return R_ROT64(s->w[p -2], 19) ^ R_ROT64(s->w[p -2], 61) ^ s->w[p -2] >> 6;
}


uint64_t        sha512_word(t_sha512 *s, int c)
{
    uint64_t lhs;
    uint64_t rhs;


    lhs = sha256_word(s->data[c], s->data[c+1], s->data[c+2], s->data[c+3]);
    rhs = sha256_word(s->data[c+4], s->data[c+5], s->data[c+6], s->data[c+7]);
    return lhs << 32 | rhs;
}
