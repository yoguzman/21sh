/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:38:04 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/02 18:12:51 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "msh.h"

int				init(void)
{
	if (signal(SIGINT, &catch_ctrlc) == SIG_ERR)
		ft_puterr("signal fail in while_msh");
	if (set_termi() == -1)
		return (-1);
	return (0);
}

int				init_ab(t_ab ab[7])
{
	ab[0].f = &ft_echo;
	if ((ab[0].bultins = ft_strdup("echo")) == NULL)
		return (-1);
	ab[1].f = &ft_cd;
	if ((ab[1].bultins = ft_strdup("cd")) == NULL)
		return (-1);
	ab[2].f = &ft_exit;
	if ((ab[2].bultins = ft_strdup("exit")) == NULL)
		return (-1);
	ab[3].f = &ft_env;
	if ((ab[3].bultins = ft_strdup("env")) == NULL)
		return (-1);
	ab[4].f = &ft_setenv;
	if ((ab[4].bultins = ft_strdup("setenv")) == NULL)
		return (-1);
	ab[5].f = &ft_unsetenv;
	if ((ab[5].bultins = ft_strdup("unsetenv")) == NULL)
		return (-1);
	ab[6].f = NULL;
	ab[6].bultins = NULL;
	return (0);
}

void			init_ak_next(t_ak ak[17])
{
	ak[4].f = NULL;
	ak[4].buff[0] = 0;
	ak[4].buff[1] = 0;
	ak[4].buff[2] = 0;
	ak[5].f = &completion_up;
	ak[5].buff[0] = 27;
	ak[5].buff[1] = 91;
	ak[5].buff[2] = 65;
	ak[6].f = &completion_down;
	ak[6].buff[0] = 27;
	ak[6].buff[1] = 91;
	ak[6].buff[2] = 66;
	ak[7].f = &move_arrow_right;
	ak[7].buff[0] = 27;
	ak[7].buff[1] = 91;
	ak[7].buff[2] = 67;
	ak[8].f = &move_arrow_left;
	ak[8].buff[0] = 27;
	ak[8].buff[1] = 91;
	ak[8].buff[2] = 68;
	ak[9].f = &ctrl_arrow;
	ak[9].buff[0] = 27;
	ak[9].buff[1] = 91;
	ak[9].buff[2] = 49;
	ak[10].f = &home;
	ak[10].buff[0] = 27;
	ak[10].buff[1] = 91;
	ak[10].buff[2] = 72;
	ak[11].f = &end;
	ak[11].buff[0] = 27;
	ak[11].buff[1] = 91;
	ak[11].buff[2] = 70;
	ak[12].f = &activ_cpy;
	ak[12].buff[0] = 0;
	ak[12].buff[1] = 0;
	ak[12].buff[2] = 0;
	ak[13].f = &stick_mark;
	ak[13].buff[0] = 16;
	ak[13].buff[1] = 0;
	ak[13].buff[2] = 0;
	ak[14].f = &cpy_mark;
	ak[14].buff[0] = 25; 
	ak[14].buff[1] = 0;
	ak[14].buff[2] = 0;
	ak[15].f = NULL;
	ak[15].buff[0] = 59; 
	ak[15].buff[1] = 53;
	ak[15].buff[2] = 68;
	ak[16].f = NULL;
	ak[16].buff[0] = 59; 
	ak[16].buff[1] = 53;
	ak[16].buff[2] = 67;
}

void			init_ak(t_ak ak[17])
{
	ak[0].f = &del_char;
	ak[0].buff[0] = 127;
	ak[0].buff[1] = 0;
	ak[0].buff[2] = 0;
	ak[1].f = &ctrl_d;
	ak[1].buff[0] = 4;
	ak[1].buff[1] = 0;
	ak[1].buff[2] = 0;
	ak[2].f = &new_line;
	ak[2].buff[0] = 10;
	ak[2].buff[1] = 0;
	ak[2].buff[2] = 0;
	ak[3].f = &ctrl_c;
	ak[3].buff[0] = 3;
	ak[3].buff[1] = 0;
	ak[3].buff[2] = 0;
	init_ak_next(ak);
}
