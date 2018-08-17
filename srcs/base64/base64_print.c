/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:06:17 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/16 15:48:19 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void      base64_print_encoded(t_base64 *b64, e_state last)
{
    ft_putchar_fd(B64_SET[b64->chunk[0]], b64->o_fd);
    ft_putchar_fd(B64_SET[b64->chunk[1]], b64->o_fd);
    if (last == on && b64->padding == 2)
        ft_putstr_fd("==", b64->o_fd);
    else if (last == on && b64->padding == 1) {
        ft_putchar_fd(B64_SET[b64->chunk[2]], b64->o_fd);
        ft_putchar_fd('=', b64->o_fd);
    }
    else
    {
        ft_putchar_fd(B64_SET[b64->chunk[2]], b64->o_fd);
        ft_putchar_fd(B64_SET[b64->chunk[3]], b64->o_fd);
    }
}
