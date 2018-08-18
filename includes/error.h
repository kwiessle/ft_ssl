/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:37:57 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/18 13:08:05 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H


/*
**  -----------------------------------------------------
**                     E  R  R  O  R
**  -----------------------------------------------------
*/


# define MD_USAGE "\n [1] - Cmd  : [ md5, sha256, sha512 ]\n [2] - Options : [ -p, -r, -q ]\n [3] - String : -s <string> \n [4] - File : <file>\n"
# define SSL_USAGE "ft_ssl\n\n Message Digest Commands : \n   - md5\n   - sha256\n   - sha512\n\n Cipher Commands :\n   - base64\n   - des\n   - des-ecb\n   - des-cbc\n"

# define ERR_MD5_NA "Message Digest [–s] option requires an argument"
# define ERR_MD5_NOFILE "File not found"

# define SSL_ERR_CMD "Invalid command name"
# define SSL_ERR_NOCMD "Must have a least one argument"



#endif
