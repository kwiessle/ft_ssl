/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:18:21 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 23:20:55 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum s_state {off, on} e_state;

typedef struct          s_input
{
    char        *message;
    size_t      len;
}                       t_input;


typedef struct          s_env
{
    e_state             q;
    e_state             r;
    e_state             stop;
    int                 entries_len;
    int                 ignored_entries;
    char                *cmd_name;
    void                (*cmd_execute)(t_input *);

}                       t_hash;



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






#endif
