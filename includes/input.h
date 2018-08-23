/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:29:26 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/23 16:26:49 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/*
**  -----------------------------------------------------
**                     I  N  P  U  T
**  -----------------------------------------------------
*/

typedef struct		s_input
{
	char		*message;
	size_t		len;
	size_t		weight;
}					t_input;

t_input				*input_init(char *message);
char				*get_input(int fd);
size_t				get_padding_size(size_t len, int modulo, size_t congruent);
int					little_endian(uint32_t h);

#endif
