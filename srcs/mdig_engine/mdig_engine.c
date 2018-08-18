/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdig_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:59:12 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/18 13:02:38 by kiefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


void        stdin_compute(t_mdig *env, e_state flag) {
    t_input     *input;

    input = input_init(get_input(STDIN));
    if (flag == on)
    {
        ft_putstr_drop(input->message, '\n');
        ft_putchar('\n');
    }
    env->cmd_execute(input);
    ft_putchar('\n');
}


void        file_compute(t_mdig *env, char *filename)
{
    int fd;

    env->stop = on;
    if ((fd = open(filename, O_RDONLY)) < 0)
        ssl_throw_error(ERR_MD5_NOFILE, filename, NULL);
    else
        mdig_output(env, get_input(fd), filename);
    close(fd);
}


void        mdig_engine(char **args, void (*p)(t_input *), char *name)
{
    t_mdig  *env;
    int         i;

    i = 2;
    env = mdig_init(args, name, p);
    if (env->entries_len - env->ignored_entries == i) {
        stdin_compute(env, off);
        return;
    }
    while (args[i]) {
        if (ft_strcmp(args[i], "-r") == 0 || ft_strcmp(args[i], "-q") == 0);
        else if (ft_strcmp(args[i], "-s") == 0 && env->stop == off) {
            if (++i < env->entries_len)
                mdig_output(env, args[i], args[i]);
            else
                ssl_throw_error(ERR_MD5_NA, NULL, MD_USAGE);
        }
        else if (ft_strcmp(args[i], "-p") == 0)
            stdin_compute(env, on);
        else
            file_compute(env, args[i]);
        i++;
    }
}
