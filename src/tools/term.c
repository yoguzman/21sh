/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:38:14 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/03 16:44:54 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "libft.h"
#include <term.h>
#include <sys/ioctl.h>

int					lol(int a)
{
	ft_putchar(a);
	return (0);
}

void	len_col()
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	ft_putnbr(w.ws_col);
}

void	set_rev()
{
	char			*res;

	res = tgetstr("mr", NULL);
	tputs(res , 1, &lol);

}

void				deset_rev()
{
	char			*res;

	res = tgetstr("me", NULL);
	tputs(res , 1, &lol);

}

int					set_termi(void)
{
	struct termios	term;
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (ft_puterr("tcgetattr fail in set_term\n"));
	term.c_lflag &= ~(ECHO | ICANON | ISIG | VINTR);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (ft_puterr("tcgetattr fail in set_term\n"));
	return (0);
}

int					unset_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (ft_puterr("tcgetattr fail in set_term\n"));
	term.c_lflag |= (ECHO | ICANON | ISIG | VINTR);
	if (tcsetattr(0, 0, &term) == -1)
		return (ft_puterr("tcgetattr fail in set_term\n"));
	return (0);
}
