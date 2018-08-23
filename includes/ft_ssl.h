/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:35:01 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/23 16:35:36 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
**  -----------------------------------------------------
**                  F  T  _  S  S  L
**  -----------------------------------------------------
*/

# include "libft.h"
# include <stdio.h>
# include "input.h"
# include "error.h"
# include "engine.h"
# include "md5.h"
# include "sha256.h"
# include "sha512.h"
# include "base64.h"

# define STDIN 0
# define STDOUT 1
# define O_CLEAR O_CREAT | O_RDWR | O_TRUNC
# define L_ROT(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
# define R_ROT(a, b) (((a) >> (b)) | ((a) << (32 - (b))))
# define L_ROT64(a, b) (((a) << (b)) | ((a) >> (64 - (b))))
# define R_ROT64(a, b) (((a) >> (b)) | ((a) << (64 - (b))))
# define W_32(a, b, c, d) (a << 24 | b << 16 | c << 8 | d)

void				ssl_throw_error(char *err, char *desc, char *usage);
void				ssl_dispatch_commands(char **args);

#endif
