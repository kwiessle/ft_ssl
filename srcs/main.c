/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:51:55 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/18 12:52:02 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


int     main(int ac, char **av)
{
    if (ac > 1)
        ssl_dispatch_commands(av);
    else {
        ssl_throw_error(SSL_ERR_NOCMD, NULL, SSL_USAGE);
    }
    return (0);
}
