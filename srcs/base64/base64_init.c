/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:02:01 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/16 17:52:51 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int     base64_table(int c)
{
    if (c > 47 && c < 58)
        return c + 4;
    else if (c > 64 && c < 91)
        return c - 65;
    else if (c > 96 && c < 123)
        return c - 71;
    else if (c == '+')
        return 62;
    else if (c == '/')
        return 63;
    else if (c == '=')
        return 0;
    else
        return -1;

}

void      base64_convert_data(t_base64 *b64)
{
    int i = 0;
    while (i < (int)b64->input->len / 8) {
        b64->data[i] = base64_table(b64->data[i]);
        i++;
    }
}


void     base64_data_parse(t_base64 *b64)
{
    b64->padding = 0;
    if (((b64->input->len / 8) % 3 != 0) && (b64->d == off))
        b64->padding = 3 - (b64->input->len / 8) % 3;
    b64->data = ft_memalloc(b64->input->len / 8 + b64->padding);
    ft_memcpy(b64->data, b64->input->message, b64->input->len / 8);
    if (b64->d == on)
        base64_convert_data(b64);
}

void           base64_detect_flags(t_base64 *b64, char **args)
{
    int         i;

    i = 0;
    while (args[i])
        {
            if (ft_strcmp(args[i], "-d") == 0)
            {
                b64->cmd_execute = &base64_decode;
                b64->d = on;
            }
            else if (ft_strcmp(args[i], "-e") == 0);
            else if (ft_strcmp(args[i], "-i") == 0)
            {
                if ((b64->i_fd = open(args[++i], O_RDONLY)) < 0)
                    throw_error("Canont open file", args[i]);
            }
            else if (ft_strcmp(args[i], "-o") == 0)
            {
                if ((b64->o_fd = open(args[++i], O_CLEAR, S_IRWXU)) < 0)
                        throw_error("Canont open file", args[i]);
            }
            i++;
    }
}

t_base64      *init_base64(char **args)
{
    t_base64    *b64;



    if (!(b64 = malloc(sizeof(t_base64))))
        return NULL;
    b64->i_fd = STDIN;
    b64->o_fd = STDOUT;
    b64->d = off;
    b64->cmd_execute = &base64_encode;
    base64_detect_flags(b64, args);
    if (b64->d == on)
        b64->input = input_init(ft_strcrop(get_input(b64->i_fd), " \t\n\v\f\r"));
    else
        b64->input = input_init(get_input(b64->i_fd));
    base64_data_parse(b64);
    return b64;
}
