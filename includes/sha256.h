/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:33:04 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/18 12:32:10 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H


/*
**  -----------------------------------------------------
**                  S  H  A  2  5  6
**  -----------------------------------------------------
*/


typedef struct          s_sha256
{
    t_input         *input;
    uint8_t         *data;
    uint64_t        encoded_len;
    uint32_t        w[64];
    uint32_t        h0;
    uint32_t        h1;
    uint32_t        h2;
    uint32_t        h3;
    uint32_t        h4;
    uint32_t        h5;
    uint32_t        h6;
    uint32_t        h7;
    uint32_t         a;
    uint32_t         b;
    uint32_t         c;
    uint32_t         d;
    uint32_t         e;
    uint32_t         f;
    uint32_t         g;
    uint32_t         h;
    uint32_t        s0;
    uint32_t        s1;
    uint32_t        ch;
    uint32_t        maj;

}                       t_sha256;


t_sha256            *sha256_init(t_input *input);
void                sha256_execute(t_input *input);
t_sha256            *sha256_init(t_input *input);
void                sha256_padding(t_sha256 *sha256);
uint32_t            sha256_k(int index);
void                sha256_run(t_sha256 *sha256);
void                sha256_add(t_sha256 *sha256);
void                sha256_decompose(t_sha256 *sha256, int *k);
uint32_t            sha256_p0(t_sha256 *s, int pos);
uint32_t            sha256_p1(t_sha256 *s, int pos);
void                sha256_hash(t_sha256 *sha256);
void                sha256_output(t_sha256 *sha256);




#endif
