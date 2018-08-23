/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:37:57 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/23 16:24:30 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
**  -----------------------------------------------------
**                     E  R  R  O  R
**  -----------------------------------------------------
*/

# define MD_U1 "\n [1] - Cmd  : [md5, sha256, sha512 ]\n [2] - "
# define MD_U2 "Options : [ -p, -r, -q ]\n [3] - String : -s <string> \n "
# define MD_U3 "[4] - File : <file>\n"
# define MD_USAGE MD_U1 MD_U2 MD_U3
# define SSL_U1 "ft_ssl\n\n Message Digest Commands : \n   - md5\n   "
# define SSL_U2 "- sha256\n   - sha512\n\n Cipher Commands :\n   - base64\n  "
# define SSL_U3 "des\n   - des-ecb\n   - des-cbc\n"
# define SSL_USAGE SSL_U1 SSL_U2 SSL_U3
# define ERR_MD5_NA "Message Digest [–s] option requires an argument"
# define ERR_MD5_NOFILE "File not found"
# define SSL_ERR_CMD "Invalid command name"
# define SSL_ERR_NOCMD "Must have a least one argument"

#endif
