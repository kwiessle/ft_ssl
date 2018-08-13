/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:26:32 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 14:27:50 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define L_ROT(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
# define R_ROT(a, b) (((a) >> (b)) | ((a) << (32 - (b))))
# define L_ROT64(a, b) (((a) << (b)) | ((a) >> (64 - (b))))
# define R_ROT64(a, b) (((a) >> (b)) | ((a) << (64 - (b))))


# define MD5_F1(b, c, d) ((b & c) | ((~b) & d))
# define MD5_F2(b, c, d) ((d & b) | ((~d) & c))
# define MD5_F3(b, c, d) (b ^ c ^ d)
# define MD5_F4(b, c, d) (c ^ (b | (~d)))



#endif
