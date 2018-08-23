/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiefer <kiefer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:03:39 by kiefer            #+#    #+#             */
/*   Updated: 2018/08/23 16:33:59 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

/*
**  -----------------------------------------------------
**                    E  N  G  I  N  E
**  -----------------------------------------------------
*/

typedef struct	s_mdig
{
	t_state		q;
	t_state		r;
	t_state		stop;
	int			entries_len;
	int			ignored_entries;
	char		*cmd_name;
	void		(*cmd_execute)(t_input *);

}				t_mdig;

void			mdig_engine(char **args, void (*p)(t_input *), char *name);
void			mdig_output(t_mdig *env, char *entry, char *arg);
t_mdig			*mdig_init(char **entries, char *name, void (*cmd)(t_input *));

#endif
