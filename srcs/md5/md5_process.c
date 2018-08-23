/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:38:38 by kwiessle          #+#    #+#             */
/*   Updated: 2018/08/23 13:47:55 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_process_1(t_md5 *md5, int pos)
{
	md5->f = MD5_F1(md5->b, md5->c, md5->d);
	md5->g = pos;
}

void	md5_process_2(t_md5 *md5, int pos)
{
	md5->f = MD5_F2(md5->b, md5->c, md5->d);
	md5->g = (5 * pos + 1) % 16;
}

void	md5_process_3(t_md5 *md5, int pos)
{
	md5->f = MD5_F3(md5->b, md5->c, md5->d);
	md5->g = (3 * pos + 5) % 16;
}

void	md5_process_4(t_md5 *md5, int pos)
{
	md5->f = MD5_F4(md5->b, md5->c, md5->d);
	md5->g = (7 * pos) % 16;
}
