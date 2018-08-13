/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:20:16 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 14:29:05 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"




void        sha256_execute(t_input *input) {

    t_sha256 *sha256;

    sha256 = sha256_init(input);

    sha256_padding(sha256);
    sha256_run(sha256);
    sha256_output(sha256);
}


void    sha256_run(t_sha256 *sha256)
{
    int chunk;
    int cursor;

    cursor = 0;
    chunk = 0;
    while (chunk < ((int)sha256->encoded_len) / 512)
    {
        sha256_decompose(sha256, &cursor);

        sha256->a = sha256->h0;
        sha256->b = sha256->h1;
        sha256->c = sha256->h2;
        sha256->d = sha256->h3;
        sha256->e = sha256->h4;
        sha256->f = sha256->h5;
        sha256->g = sha256->h6;
        sha256->h = sha256->h7;

        sha256_hash(sha256);
        sha256_add(sha256);
        chunk++;
    }
}


void        sha256_decompose(t_sha256 *s, int *c)
{
    int i;
    uint32_t p0;
    uint32_t p1;
    uint32_t w;

    i = 0;
    while (i < 16)
	{
        w = sha256_word(s->data[*c],s->data[*c+1],s->data[*c+2],s->data[*c+3]);
        s->w[i] = w;
		*c += 4;
        i++;
	}
    while (i < 64) {
        p0 = sha256_p0(s, i);
        p1 = sha256_p1(s, i);
        s->w[i] = s->w[i - 16] + p0 + s->w[i - 7] + p1;
        i++;
    }
}




void        sha256_hash(t_sha256 *s)
{
    uint32_t    tmp1;
    uint32_t    tmp2;
    int         i;

    i = 0;
    while (i < 64)
    {
        s->s1 = R_ROT(s->e, 6) ^ R_ROT(s->e, 11) ^ R_ROT(s->e, 25);
        s->ch = (s->e & s->f) ^ ((~s->e) & s->g);
        tmp1 = s->h + s->s1 + s->ch + sha256_k(i) + s->w[i];
        s->s0 = R_ROT(s->a, 2) ^ R_ROT(s->a, 13) ^ R_ROT(s->a, 22);
        s->maj = (s->a & s->b) ^ (s->a & s->c) ^(s->b & s->c);
        tmp2 = s->s0 + s->maj;
        s->h = s->g;
        s->g = s->f;
        s->f = s->e;
        s->e = s->d + tmp1;
        s->d = s->c;
        s->c = s->b;
        s->b = s->a;
        s->a = tmp1 + tmp2;

        i++;
    }
}


void        sha256_add(t_sha256 *sha256)
{
    sha256->h0 += sha256->a;
    sha256->h1 += sha256->b;
    sha256->h2 += sha256->c;
    sha256->h3 += sha256->d;
    sha256->h4 += sha256->e;
    sha256->h5 += sha256->f;
    sha256->h6 += sha256->g;
    sha256->h7 += sha256->h;
}
