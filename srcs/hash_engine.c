/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:59:12 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 23:31:00 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void        stdin_compute(t_hash *env, e_state flag) {
    t_input     *input;

    input = input_init(get_input(0));
    if (flag == on)
    {
        ft_putstr_drop(input->message, '\n');
        ft_putchar('\n');
    }
    env->cmd_execute(input);
    ft_putchar('\n');
}


void        file_compute(t_hash *env, char *filename)
{
    int fd;

    env->stop = on;
    if ((fd = open(filename, O_RDONLY)) < 0)
        throw_error(ERR_MD5_NOFILE, filename);
    else
        interpret_command(env, get_input(fd), filename);
    close(fd);
}


void        hash_engine(char **args, void (*p)(t_input *), char *name)
{
    t_hash  *env;
    int         i;

    i = 2;
    env = hash_init(args, name, p);
    if (env->entries_len - env->ignored_entries == i) {
        stdin_compute(env, off);
        return;
    }
    while (args[i]) {
        if (ft_strcmp(args[i], "-r") == 0 || ft_strcmp(args[i], "-q") == 0);
        else if (ft_strcmp(args[i], "-s") == 0 && env->stop == off) {
            if (++i < env->entries_len)
                interpret_command(env, args[i], args[i]);
            else
                throw_error(ERR_MD5_NA, "");
        }
        else if (ft_strcmp(args[i], "-p") == 0)
            stdin_compute(env, on);
        else
            file_compute(env, args[i]);
        i++;
    }
}
