/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:04:37 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 13:56:44 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void    md5_execute(t_input *input)
{
    t_md5   *md5;

    md5 = md5_init(input);
    md5_padding(md5);
    md5_run(md5);
    md5_output(md5);

    return;
}


void    md5_run(t_md5 *md5)
{
    uint64_t chunk;

    chunk = 0;
    while (chunk < ((md5->encoded_len) / 512))
    {
        ft_memcpy(md5->w, &md5->data[chunk * 64], 64);

        md5->a = md5->h0;
        md5->b = md5->h1;
        md5->c = md5->h2;
        md5->d = md5->h3;

        md5_hash(md5);

        md5->h0 += md5->a;
        md5->h1 += md5->b;
        md5->h2 += md5->c;
        md5->h3 += md5->d;
        chunk++;
    }
}

void    md5_hash(t_md5 *md5)
{
    int i;
    int tmp;

    i = 0;
    while (i < 64)
    {
        if (i < 16)
            md5_process_1(md5, i);
        else if (i < 32)
            md5_process_2(md5, i);
        else if (i < 48)
            md5_process_3(md5, i);
        else
            md5_process_4(md5, i);

        tmp = md5->d;
        md5->d = md5->c;
        md5->c = md5->b;
        md5->b = L_ROT((md5->a + md5->f + md5_k(i) + md5->w[md5->g]), md5_r(i)) + md5->b;
        md5->a = tmp;

        i++;
    }
}



void    md5_padding(t_md5 *md5)
{
    int         padding;
    uint64_t    len;

    len = md5->input->len;
    padding = get_padding_size(len, 512, 448);

    md5->data = ft_memalloc((len + padding + 64) / 8);
    md5->encoded_len = (len + padding + 64);
    ft_memcpy(md5->data, md5->input->message, len / 8);
    md5->data[len / 8] = 0b10000000;
    ft_memcpy(md5->data + (len + padding) / 8, &len, 8);

    return;
}
