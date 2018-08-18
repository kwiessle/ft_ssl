/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:00:16 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/18 13:08:05 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H


/*
**  -----------------------------------------------------
**                   B  A  S  E    6  4
**  -----------------------------------------------------
*/


typedef struct          s_base64
{
    t_input         *input;
    uint8_t         *data;
    int             padding;
    int             chunk[4];
    int             i_fd;
    int             o_fd;
    e_state         e;
    e_state         d;
    char            *cmd_name;
    void            (*cmd_execute)(struct s_base64 *);

}                       t_base64;


void                base64_execute(char **args, char *cmd_name);
void                base64_encode(t_base64 *b64);
void                base64_decode(t_base64 *b64);
t_base64            *init_base64(char **args, char *name);
void                base64_print_encoded(t_base64 *b64, e_state last);
void                base64_print_decoded(t_base64 *b64);


#endif
