/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:41:04 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/16 17:47:11 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"



void      base64_encode(t_base64 *b64)
{
    uint32_t    b24;
    e_state     last;
    int         i;

    i = 0;
    last = off;
    while (i < (int)(b64->input->len/8) + b64->padding)
    {
        b24 =  sha256_word(0x0, b64->data[i], b64->data[i+1], b64->data[i+2]);
        b64->chunk[0] = b24 >> 18;
        b64->chunk[1] = (0x3FFFF & b24) >> 12;
        b64->chunk[2] = (0xFFF & b24) >> 6;
        b64->chunk[3] = (0x3F & b24);
        if (i == (int)(b64->input->len/8) + b64->padding - 3)
            last = on;
        base64_print_encoded(b64, last);
        i += 3;
    }
}


void      base64_decode(t_base64 *b64)
{
    int     i;
    char    a;
    char    b;
    char    c;

    i = 0;
    while (i < (int)b64->input->len / 8)
    {
        a = (b64->data[i] << 2) | (b64->data[i+1] >> 4);
        b = (0xF0 & b64->data[i+1] << 4) | (0xF & (b64->data[i+2] >> 2));
        c = (0xC0 & (b64->data[i+2] << 6)) | (0x3F & (b64->data[i+3]));
        ft_putchar_fd(a, b64->o_fd);
        ft_putchar_fd(b, b64->o_fd);
        ft_putchar_fd(c, b64->o_fd);
        i += 4;
    }
}



void      base64_engine(char **arg) {

    t_base64    *b64;

    b64 = init_base64(arg);
    b64->cmd_execute(b64);


    // ft_putchar('\n');
    // ft_putstr(b64->input->message);
    // ft_putchar('\n');
    // ft_putstr(ft_strcrop(b64->input->message, ));
    // ft_putchar('\n');
    close(b64->i_fd);
    close(b64->o_fd);
}
