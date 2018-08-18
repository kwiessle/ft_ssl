/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:55:21 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/18 13:08:05 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H


/*
**  -----------------------------------------------------
**                  S  H  A  5  1  2
**  -----------------------------------------------------
*/


typedef struct          s_sha512
{
    t_input         *input;
    uint8_t         *data;
    uint64_t        encoded_len;
    uint64_t        w[80];
    uint64_t        h0;
    uint64_t        h1;
    uint64_t        h2;
    uint64_t        h3;
    uint64_t        h4;
    uint64_t        h5;
    uint64_t        h6;
    uint64_t        h7;
    uint64_t         a;
    uint64_t         b;
    uint64_t         c;
    uint64_t         d;
    uint64_t         e;
    uint64_t         f;
    uint64_t         g;
    uint64_t         h;
    uint64_t        s0;
    uint64_t        s1;
    uint64_t        ch;
    uint64_t        maj;

}                       t_sha512;


t_sha512            *sha512_init(t_input *input);
void                sha512_execute(t_input *input);
t_sha512            *sha512_init(t_input *input);
void                sha512_padding(t_sha512 *sha512);
uint64_t            sha512_k(int index);
uint64_t            sha512_k40(int index);
uint64_t            sha512_k80(int index);
void                sha512_run(t_sha512 *sha512);
void                sha512_add(t_sha512 *sha512);
void                sha512_decompose(t_sha512 *sha512, int *k);
uint64_t            sha512_p0(t_sha512 *s, int pos);
uint64_t            sha512_p1(t_sha512 *s, int pos);
void                sha512_hash(t_sha512 *sha512);
void                sha512_output(t_sha512 *sha512);
uint64_t            sha512_word(t_sha512 *sha512, int cursor);
#endif
