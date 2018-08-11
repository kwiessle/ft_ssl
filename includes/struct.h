/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:18:21 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/11 15:55:07 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H



typedef struct          s_input
{
    char        *message;
    size_t      len;
}                       t_input;



typedef struct          s_md5
{
    t_input          *input;
    uint8_t          *data;
    int              encoded_len;
    uint32_t         r[64];
    uint32_t         k[64];
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







#endif
