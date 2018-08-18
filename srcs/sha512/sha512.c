/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:15:33 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/17 16:09:49 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"




void        sha512_execute(t_input *input) {

    t_sha512 *sha512;

    sha512 = sha512_init(input);
    sha512_padding(sha512);
    sha512_run(sha512);
    sha512_output(sha512);
    free(sha512->input);
    free(sha512);
}


void    sha512_run(t_sha512 *sha512)
{
    int chunk;
    int cursor;

    cursor = 0;
    chunk = 0;
    while (chunk < ((int)sha512->encoded_len) / 1024)
    {
        sha512_decompose(sha512, &cursor);
        sha512->a = sha512->h0;
        sha512->b = sha512->h1;
        sha512->c = sha512->h2;
        sha512->d = sha512->h3;
        sha512->e = sha512->h4;
        sha512->f = sha512->h5;
        sha512->g = sha512->h6;
        sha512->h = sha512->h7;

        sha512_hash(sha512);
        sha512_add(sha512);
        chunk++;
    }
}


void        sha512_decompose(t_sha512 *s, int *c)
{
    int i;
    uint64_t p0;
    uint64_t p1;
    uint64_t w;

    i = 0;
    while (i < 16)
	{
        w = sha512_word(s, *c);
        s->w[i] = w;
		*c += 8;
        i++;
	}
    while (i < 80) {
        p0 = sha512_p0(s, i);
        p1 = sha512_p1(s, i);
        s->w[i] = s->w[i - 16] + p0 + s->w[i - 7] + p1;
        i++;
    }
}




void        sha512_hash(t_sha512 *s)
{
    uint64_t    tmp1;
    uint64_t    tmp2;
    int         i;

    i = 0;
    while (i < 80)
    {
        s->s1 = R_ROT64(s->e, 14) ^ R_ROT64(s->e, 18) ^ R_ROT64(s->e, 41);
        s->ch = (s->e & s->f) ^ ((~s->e) & s->g);
        tmp1 = s->h + s->s1 + s->ch + sha512_k(i) + s->w[i];
        s->s0 = R_ROT64(s->a, 28) ^ R_ROT64(s->a, 34) ^ R_ROT64(s->a, 39);
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


void        sha512_add(t_sha512 *sha512)
{
    sha512->h0 += sha512->a;
    sha512->h1 += sha512->b;
    sha512->h2 += sha512->c;
    sha512->h3 += sha512->d;
    sha512->h4 += sha512->e;
    sha512->h5 += sha512->f;
    sha512->h6 += sha512->g;
    sha512->h7 += sha512->h;
}
