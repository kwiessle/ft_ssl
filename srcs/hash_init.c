/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:24:31 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/13 23:27:59 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void    detect_global_flags(t_hash *env, char **entries) {
    int i;

    i = 0;
    while (entries[i])
    {
        if (ft_strcmp(entries[i],"-q") == 0)
        {
            env->q = on;
            env->ignored_entries++;
        }
        else if (ft_strcmp(entries[i],"-r") == 0)
        {
            env->r = on;
            env->ignored_entries++;
        }
        i++;
    }
    env->entries_len = i;
}


t_hash       *hash_init(char **entries, char *name, void (*cmd)(t_input *))
{
    t_hash   *env;

    if (!(env = malloc(sizeof(t_hash))))
        return NULL;
    env->q = off;
    env->r = off;
    env->ignored_entries = 0;
    env->cmd_execute = cmd;
    env->cmd_name = name;
    env->stop = off;
    detect_global_flags(env, entries);
    return env;
}
