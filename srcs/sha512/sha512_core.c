/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:15:12 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 16:15:52 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


uint64_t     sha512_k(int index)
{
    if (index > 40)
        return sha512_k80(index - 40);
    return sha512_k40(index);
}


t_sha512    *sha512_init(t_input *input) {
    t_sha512    *sha512;

    if (!(sha512 = malloc(sizeof(t_sha512))))
        return NULL;
    sha512->h0 = 0x6a09e667f3bcc908;
    sha512->h1 = 0xbb67ae8584caa73b;
    sha512->h2 = 0x3c6ef372fe94f82b;
    sha512->h3 = 0xa54ff53a5f1d36f1;
    sha512->h4 = 0x510e527fade682d1;
    sha512->h5 = 0x9b05688c2b3e6c1f;
    sha512->h6 = 0x1f83d9abfb41bd6b;
    sha512->h7 = 0x5be0cd19137e2179;
    sha512->input = input;

    return sha512;
}


void        sha512_padding(t_sha512 *sha512)
{
    int         padding;
    long        len;
    int         offset;

    len = sha512->input->len;
    padding = get_padding_size(len, 1024, 896);
    sha512->data = ft_memalloc((len + padding + 128) / 8);
    sha512->encoded_len = (len + padding + 128);
    ft_memcpy(sha512->data, sha512->input->message, len / 8);
    sha512->data[len / 8] = 0b10000000;
    offset = (len + padding) / 8;
    ft_memcpy(sha512->data + offset, &len, 8);
    ft_swap(sha512->data + offset, sha512->data + offset + 15);
    ft_swap(sha512->data + offset + 1, sha512->data + offset + 14);
    ft_swap(sha512->data + offset + 2, sha512->data + offset + 13);
    ft_swap(sha512->data + offset + 3, sha512->data + offset + 12);
    ft_swap(sha512->data + offset + 4, sha512->data + offset + 11);
    ft_swap(sha512->data + offset + 5, sha512->data + offset + 10);
    ft_swap(sha512->data + offset + 6, sha512->data + offset + 9);
    ft_swap(sha512->data + offset + 7, sha512->data + offset + 8);
    return;
}


void    sha512_output(t_sha512 *sha512)
{
    // ft_putstr("SHA512 (\"");
    // ft_putstr(sha512->input->message);
    // ft_putstr("\") = ");
    ft_putbignbr_base(sha512->h0, 16, B16_SET);
    ft_putbignbr_base(sha512->h1, 16, B16_SET);
    ft_putbignbr_base(sha512->h2, 16, B16_SET);
    ft_putbignbr_base(sha512->h3, 16, B16_SET);
    ft_putbignbr_base(sha512->h4, 16, B16_SET);
    ft_putbignbr_base(sha512->h5, 16, B16_SET);
    ft_putbignbr_base(sha512->h6, 16, B16_SET);
    ft_putbignbr_base(sha512->h7, 16, B16_SET);
    ft_putchar('\n');
}
