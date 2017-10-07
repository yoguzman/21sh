#include <unistd.h>
#include "msh.h"

void	find_word_right(t_dl *dl)
{
	while (dl->line[dl->pos_curs] && ft_isalpha(dl->line[dl->pos_curs]))
	{
		move_cpy_one_right(dl);
		move_l_or_r((int)dl->buff[2]);
		++dl->pos_curs;
	}
	while (dl->line[dl->pos_curs] && (ft_isalpha(dl->line[dl->pos_curs]) == 0))
	{
		move_cpy_one_right(dl);
		move_l_or_r((int)dl->buff[2]);
		++dl->pos_curs;
	}
}

void	find_word(t_dl *dl, int dir)
{
	if (dir == 1)
	{
		if (dl->pos_curs > 0 && ft_isalpha(dl->line[dl->pos_curs]))
		{
			move_cpy_one_left(dl);
			move_l_or_r((int)dl->buff[2]);
			--dl->pos_curs;
		}
		while (dl->pos_curs > 0 && (ft_isalpha(dl->line[dl->pos_curs]) == 0))
		{
			move_cpy_one_left(dl);
			move_l_or_r((int)dl->buff[2]);
			--dl->pos_curs;
		}
		while (dl->pos_curs > 0 && ft_isalpha(dl->line[dl->pos_curs]) && ft_isalpha(dl->line[dl->pos_curs - 1]))
		{
			move_cpy_one_left(dl);
			move_l_or_r((int)dl->buff[2]);
			--dl->pos_curs;

		}
	}
	else if (dir == 0)
		find_word_right(dl);
}

int		ctrl_arrow(t_dl *dl)
{
	if (dl->ctrl_set == 0)
	{
		dl->ctrl_set = 1;
		return (0);
	}
	else
		dl->ctrl_set = 0;
	if (dl->buff[2] == 67 && dl->line)
		find_word(dl, 0);
	else if (dl->buff[2] == 68 && dl->line)
		find_word(dl, 1);
	else if (dl->buff[2] == 65)
		ft_putstr("up");
	else if (dl->buff[2] == 66)
		ft_putstr("down");
	return (0);
}
