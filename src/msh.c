/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:38:25 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/02 18:13:25 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "msh.h"

int				fill_line(t_dl *dl, t_ak ak[17])
{
	int			ret1;
	int			ret;

	ft_memset(dl->buff, 0, 4);
	dl->line = NULL;
	dl->ctrl_set = 0;
	dl->comple_hist = NULL;
	dl->pos_curs = 0;
	while ((ret = read(0, dl->buff, 3)) > 0)
	{
//		ft_putnbr(dl->buff[0]);
//		ft_putchar(' ');
//		ft_putnbr(dl->buff[1]);
//		ft_putchar(' ');
//		ft_putnbr(dl->buff[2]);
		if (!(dl->line))
			dl->pos_curs = 0;
		if (((ret1 = edit_line(dl, ak)) == 1 || ret1 == -1 || ret1 == 3))
			return (ret1);
		if (ret1 != 2)
			ft_memset(dl->buff, 0, 4);
		else
		{
			ft_putchar('\n');
			return (0);
		}
	}
	return (0);
}

int				line_fill(t_dl *dl, t_ak ak[17], t_ab ab[7])
{
	int			ret;

	if ((ret = fill_line(dl, ak)) != 0)
	{
		if (ret == 3)
			return (0);
		free_list(dl->cmd_hist);
		free_ab(ab);
		return (ret);
	}
	return (0);
}

int				edit_line_and_hist(t_dl *dl, t_ak ak[12], t_ab ab[7])
{
	int			ret;

	if ((ret = line_fill(dl, ak, ab)) != 0)
		return (ret);
	if ((dl->cmd_hist == NULL && dl->line != NULL) ||
			(dl->line && (ft_strcmp(dl->cmd_hist->content, dl->line))))
		ft_lstadd_double(&(dl->cmd_hist),
				ft_lstnew(dl->line, ft_strlen(dl->line) + 1));
	return (0);
}

int				while_msh(t_list **my_env)
{
	t_dl		dl;
	t_ak		ak[17];
	t_ab		ab[7];
	int			ret;

	dl.cmd_hist = NULL;
	dl.buff_cpy = NULL;
	init_ak(ak);
	if (init_ab(ab) == -1)
		return (-1);
	dl.ret_cmd = 32;
	while (42)
	{
		dl.mark_set_to = -1;
		prompt_turfu(*my_env);
		ft_putstr_color(" % ", dl.ret_cmd);
		if ((ret = edit_line_and_hist(&dl, ak, ab)) != 0)
			return (ret);
/*
  check line for editing line with putstr(dl.line);
*/
		ft_putstr(dl.line);
/*
   reflechir a comment utiliser mes donnes par rapport a l ast et la tokenisation
*/

/*
   after editing go token
*/

/*
   and after token go exec
*/
		free(dl.line);
	}
	return (0);
}
