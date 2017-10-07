#include "msh.h"

int			home(t_dl *dl)
{
	while (dl->pos_curs > 0)
	{
		move_cpy_one_left(dl);
		move_l_or_r(68);
		--dl->pos_curs;
	}
	return (0);
}

int			end(t_dl *dl)
{
	while (dl->line[dl->pos_curs])
	{
		move_cpy_one_right(dl);
		move_l_or_r(67);
		++dl->pos_curs;
	}
	return (0);
}
