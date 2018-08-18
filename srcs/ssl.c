/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:34:58 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/18 13:01:44 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void    ssl_dispatch_commands(char **args)
{
    if (ft_strcmp(args[1], "md5") == 0)
        mdig_engine(args, &md5_execute, "MD5");
    else if (ft_strcmp(args[1], "sha256") == 0)
        mdig_engine(args, &sha256_execute, "SHA256");
    else if (ft_strcmp(args[1], "sha512") == 0)
        mdig_engine(args, &sha512_execute, "SHA512");
    else if (ft_strcmp(args[1], "base64") == 0)
        base64_execute(args, "BASE64");
    else
        ssl_throw_error(SSL_ERR_CMD, NULL, SSL_USAGE);

}


void        ssl_usage(char *usage)
{
    ft_putstr("Usage : ");
    ft_putstr(usage);
}


void        ssl_throw_error(char *err, char *desc, char *usage)
{
    ft_putstr("Error : ");
    ft_putstr(err);
    if (desc != NULL)
    {
        ft_putstr(" '");
        ft_putstr(desc);
        ft_putchar('\'');
    }
    ft_putchar('\n');
    if (usage != NULL)
        ssl_usage(usage);

    exit(0);
}
