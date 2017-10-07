/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:37:10 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/02 18:46:43 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int			ctrl_d(t_dl *dl)
{
	if (dl->line)
		return (0);
	ft_putchar('\n');
	return (1);
}

int			ctrl_c(t_dl *dl)
{
	free(dl->line);
	dl->line = NULL;
	ft_putchar('\n');
	dl->ret_cmd = 31;
	return (3);
}

int			new_line(t_dl *dl)
{
	dl->ret_cmd = 32;
	return (2);
}

int			check_arrow(t_dl *dl, t_ak ak[17])
{
	int		i;
	int		ret;

	i = 5;
	if (dl->ctrl_set == 1)
		ak[9].f(dl);
	while (i <= 14)
	{
		if (!ft_memcmp(dl->buff, ak[i].buff, 3))
		{
			if (dl->comple_hist == NULL && dl->cmd_hist)
			{
				ft_lstadd_double(&(dl->cmd_hist),
						ft_lstnew(dl->line, ft_strlen(dl->line) + 1));
				dl->comple_hist = dl->cmd_hist;
			}
			ret = ak[i].f(dl);
			return (ret);
		}
		++i;
	}
	if (dl->comple_hist)
		free_first_list(dl);
	dl->comple_hist = NULL;
	return (3);
}

void		cut_copie_cut(t_dl *dl)
{
	int		i;

	i = dl->pos_curs;
	deset_rev();
	while (dl->pos_curs > 0)
	{
		move_l_or_r(68);
		--dl->pos_curs;
	}
	ft_putstr(dl->line);
	while (dl->pos_curs < (int)ft_strlen(dl->line))
		++dl->pos_curs;
	while (dl->pos_curs > i)
	{
		move_l_or_r(68);
		--dl->pos_curs;
	}
	dl->mark_set_to = -1;
}

void		cut_copie(t_dl *dl, t_ak ak[17])
{
	if (dl->mark_set_to != -1 && ft_memcmp(dl->buff, ak[7].buff, 3) &&
			ft_memcmp(dl->buff, ak[8].buff, 3) &&
			ft_memcmp(dl->buff, ak[9].buff, 3) &&
			ft_memcmp(dl->buff, ak[10].buff, 3) &&
			ft_memcmp(dl->buff, ak[16].buff, 3) &&
			ft_memcmp(dl->buff, ak[15].buff, 3) &&
			ft_memcmp(dl->buff, ak[14].buff, 3) &&
			ft_memcmp(dl->buff, ak[11].buff, 3))
		cut_copie_cut(dl);
}

int			edit_line(t_dl *dl, t_ak ak[17])
{
	int		i;
	int		ret;

	cut_copie(dl, ak);
	if ((ret = check_arrow(dl, ak)) != 3)
		return (ret);
	i = 0;
	while (ak[i].f)
	{
		if (!ft_memcmp(dl->buff, ak[i].buff, 3))
		{
			ret = ak[i].f(dl);
			return (ret);
		}
		++i;
	}
	if (dl->buff[1] == 0 && dl->buff[0] != '\t' && dl->buff[0] &&
			ak[i].f == NULL && dl->buff[0] > 31 && cpy_char(dl) == -1)
		return (-1);
	return (0);
}
