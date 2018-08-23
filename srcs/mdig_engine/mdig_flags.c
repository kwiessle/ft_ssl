/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdig_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:22:02 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/23 14:18:19 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		reverse_output(t_mdig *env, char *entry, char *arg)
{
	t_input		*input;

	input = input_init(entry);
	env->cmd_execute(input);
	ft_putchar(' ');
	if (env->stop == off)
		ft_putstr("\"");
	ft_putstr_drop(arg, '\n');
	if (env->stop == off)
		ft_putstr("\"");
}

void		default_output(t_mdig *env, char *entry, char *arg)
{
	t_input		*input;

	input = input_init(entry);
	ft_putstr(env->cmd_name);
	ft_putstr(" (");
	if (env->stop == off)
		ft_putstr("\"");
	ft_putstr_drop(arg, '\n');
	if (env->stop == off)
		ft_putstr("\"");
	ft_putstr(") = ");
	env->cmd_execute(input);
}

void		mdig_output(t_mdig *env, char *entry, char *arg)
{
	t_input		*input;

	if (env->q == on)
	{
		input = input_init(entry);
		env->cmd_execute(input);
	}
	else if (env->r == on)
		reverse_output(env, entry, arg);
	else
		default_output(env, entry, arg);
	ft_putchar('\n');
}
