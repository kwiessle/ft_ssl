/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:28:33 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/18 12:43:43 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H


/*
**  -----------------------------------------------------
**                      M   D   5
**  -----------------------------------------------------
*/


# define MD5_F1(b, c, d) ((b & c) | ((~b) & d))
# define MD5_F2(b, c, d) ((d & b) | ((~d) & c))
# define MD5_F3(b, c, d) (b ^ c ^ d)
# define MD5_F4(b, c, d) (c ^ (b | (~d)))


typedef struct          s_md5
{
    t_input          *input;
    uint8_t          *data;
    uint64_t         encoded_len;
    uint32_t         w[16];
    uint32_t         a;
    uint32_t         b;
    uint32_t         c;
    uint32_t         d;
    uint32_t         f;
    uint32_t         g;
    uint32_t         h0;
    uint32_t         h1;
    uint32_t         h2;
    uint32_t         h3;

}                       t_md5;


t_md5               *md5_init(t_input *input);
void                md5_run(t_md5 *md5);
void                md5_execute(t_input *input);
void                md5_padding(t_md5 *md5);
void                md5_hash(t_md5 *md5);
void                md5_process_1(t_md5 *md5, int pos);
void                md5_process_2(t_md5 *md5, int pos);
void                md5_process_3(t_md5 *md5, int pos);
void                md5_process_4(t_md5 *md5, int pos);
void                md5_output(t_md5 *md5);
uint32_t            md5_r(int index);
uint32_t            md5_k(int index);

#endif
