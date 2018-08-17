/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:26:32 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/16 16:22:42 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define STDIN 0
# define STDOUT 1

# define O_CLEAR O_CREAT | O_RDWR | O_TRUNC

# define L_ROT(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
# define R_ROT(a, b) (((a) >> (b)) | ((a) << (32 - (b))))
# define L_ROT64(a, b) (((a) << (b)) | ((a) >> (64 - (b))))
# define R_ROT64(a, b) (((a) >> (b)) | ((a) << (64 - (b))))


# define MD5_F1(b, c, d) ((b & c) | ((~b) & d))
# define MD5_F2(b, c, d) ((d & b) | ((~d) & c))
# define MD5_F3(b, c, d) (b ^ c ^ d)
# define MD5_F4(b, c, d) (c ^ (b | (~d)))

# define ERR_CMD "Invalid command name"
# define ERR_NCMD "Must have a least one argument"
# define ERR_MD5_NA "MD5 [–s] option requires an argument"
# define ERR_MD5_NOFILE "File not found"


#endif
