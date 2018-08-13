/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:25:17 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 13:56:59 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


uint32_t     sha256_k(int index)
{
    static uint32_t map[64] = {
        0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,
        0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
        0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,
        0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
        0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,
        0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
        0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,
        0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
        0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,
        0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
        0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
    };
    return map[index];
}

t_sha256    *sha256_init(t_input *input) {
    t_sha256    *sha256;

    if (!(sha256 = malloc(sizeof(t_sha256))))
        return NULL;
    sha256->h0 = 0x6a09e667;
    sha256->h1 = 0xbb67ae85;
    sha256->h2 = 0x3c6ef372;
    sha256->h3 = 0xa54ff53a;
    sha256->h4 = 0x510e527f;
    sha256->h5 = 0x9b05688c;
    sha256->h6 = 0x1f83d9ab;
    sha256->h7 = 0x5be0cd19;
    sha256->input = input;

    return sha256;
}

void        sha256_padding(t_sha256 *sha256)
{
    int         padding;
    long        len;

    len = sha256->input->len;
    padding = get_padding_size(len, 512, 448);
    sha256->data = ft_memalloc((len + padding + 64) / 8);

    sha256->encoded_len = (len + padding + 64);
    ft_memcpy(sha256->data, sha256->input->message, len / 8);
    sha256->data[len / 8] = 0b10000000;

    int offset = (len + padding) / 8;
    ft_memcpy(sha256->data + offset, &len, 8);
    ft_swap(sha256->data + offset, sha256->data + offset + 7);
    ft_swap(sha256->data + offset + 1, sha256->data + offset + 6);
    ft_swap(sha256->data + offset + 2, sha256->data + offset + 5);
    ft_swap(sha256->data + offset + 3, sha256->data + offset + 4);

    return;
}

void    sha256_output(t_sha256 *sha256)
{
    // ft_putstr("SHA256 (\"");
    // ft_putstr(sha256->input->message);
    // ft_putstr("\") = ");
    ft_putnbr_base(sha256->h0, 16, B16_SET);
    ft_putnbr_base(sha256->h1, 16, B16_SET);
    ft_putnbr_base(sha256->h2, 16, B16_SET);
    ft_putnbr_base(sha256->h3, 16, B16_SET);
    ft_putnbr_base(sha256->h4, 16, B16_SET);
    ft_putnbr_base(sha256->h5, 16, B16_SET);
    ft_putnbr_base(sha256->h6, 16, B16_SET);
    ft_putnbr_base(sha256->h7, 16, B16_SET);
    ft_putchar('\n');
}
