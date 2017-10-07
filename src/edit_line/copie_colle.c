/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copie_colle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:20:10 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/02 18:59:44 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include <stdlib.h>
#include <curses.h>
#include <termcap.h>

int		cpy_char_for_stick(t_dl *dl, char c)
{
	int	j;

	if ((dl->line = ft_reallocfake(dl->line,
									ft_strlen(dl->line), 1 + 1)) == NULL)
		return (-1);
	ft_cpy_char_to_i(dl->line, c, dl->pos_curs);
	ft_putstr(dl->line + dl->pos_curs);
	++(dl->pos_curs);
	j = ft_strlen(dl->line);
	while (j > dl->pos_curs && j--)
		move_l_or_r(68);
	return (0);
}

int			activ_cpy(t_dl *dl)
{
	dl->mark_set_to = dl->pos_curs;
	set_rev();
	return (0);
}

int			create_buff_cpy(t_dl *dl, int pos_min, int pos_max)
{
	if ((dl->buff_cpy = malloc(sizeof(char) *
					((pos_max - pos_min) + 2))) == NULL)
		return (-1);
	ft_strncpy(dl->buff_cpy, dl->line + pos_min, (pos_max - pos_min + 1));
	dl->buff_cpy[pos_max - pos_min + 1] = 0;
	return (0);
}

int			cpy_mark(t_dl *dl)
{
	ft_memset(dl->buff, 0, 4);
	if (dl->mark_set_to != -1)
	{
		if (dl->pos_curs <= dl->mark_set_to)
		{
			if (create_buff_cpy(dl, dl->pos_curs, dl->mark_set_to) == -1)
				return (-1);
		}
		else
			if (create_buff_cpy(dl, dl->mark_set_to, dl->pos_curs) == -1)
				return (-1);
	}
	cut_copie_cut(dl);
	return (0);
}

int			stick_mark(t_dl *dl)
{
	int		i;

	i = 0;
	while (dl->buff_cpy[i])
	{
		cpy_char_for_stick(dl, dl->buff_cpy[i]);
		++i;
	}
	return (0);
}
