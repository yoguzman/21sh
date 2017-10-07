/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:21:44 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/03 16:44:22 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include <signal.h>
# include "libft.h"

# define BEGIN 0
# define LAST 1

typedef struct	s_data_line
{
	t_list		*cmd_hist;
	t_list		*comple_hist;
	int			mark_set_to;
	char		*buff_cpy;
	int			ctrl_set;
	int			pos_curs;
	char		buff[4];
	char		*line;
	int			ret_cmd;
}				t_dl;

typedef struct	s_array_bultin
{
	int			(*f)(t_list **my_env, char **tab, t_dl *dl,
						struct s_array_bultin *ab);
	char		*bultins;
}				t_ab;

typedef struct	s_array_key
{
	int			(*f)(t_dl *dl);
	char		buff[4];
}				t_ak;

t_list			*copy_env(char **env);
int				add_elem_to_env(t_list **my_env, char *add_env,
								int add_beg_or_last);
void			prompt_turfu(t_list *my_env);

void			free_tab(char **tab);
void			free_first_list(t_dl *dl);
void			free_char(char **str);
void			free_list(t_list *list);
void			free_ab(t_ab ab[7]);

void			catch_ctrlc();

int				while_msh(t_list **my_env);

int				init();
int				init_ab(t_ab ab[7]);
void			init_ak(t_ak ak[17]);
int				unset_term();
int				set_termi();

int				edit_line(t_dl *dl, t_ak ak[17]);
int				move_arrow_right(t_dl *dl);
int				move_arrow_left(t_dl *dl);
int				del_char(t_dl *dl);
int				new_line(t_dl *dl);
int				completion_down(t_dl *dl);
int				completion_up(t_dl *dl);
int				ctrl_d(t_dl *dl);
int				cpy_char(t_dl *dl);
void			move_l_or_r(int c_est_ma_direction);
int				ctrl_arrow(t_dl *dl);
int				ctrl_c(t_dl *dl);
int				home(t_dl *dl);
int				end(t_dl *dl);
int				activ_cpy(t_dl *dl);
int				cpy_mark(t_dl *dl);
int				stick_mark(t_dl *dl);
void			deset_rev();
void			set_rev();
void			move_cpy_one_left(t_dl *dl);
void			move_cpy_one_right(t_dl *dl);
void			ft_cpy_char_to_i(char *line, char c, int pos);
void			cut_copie_cut(t_dl *dl);
void			len_col();

int				ft_unsetenv(t_list **my_env, char **tab, t_dl *dl, t_ab ab[7]);
int				unsetenv_go(t_list **my_env, char *str);
int				ft_setenv(t_list **my_env, char **tab, t_dl *dl, t_ab ab[7]);
int				pos_eg(char *lol);
int				setenv_push(t_list **my_env, char *var, char *word);
int				ft_env(t_list **my_env, char **tab, t_dl *dl, t_ab ab[7]);
int				equal(char *str);
t_list			*strdup_lst(t_list *my_env);
void			disp_env(t_list *tmp);
int				ft_exit(t_list **my_env, char **tab, t_dl *dl, t_ab ab[7]);
int				ft_cd(t_list **my_env, char **tab, t_dl *dl, t_ab ab[7]);
int				ft_echo(t_list **my_env, char **tab, t_dl *dl, t_ab ab[7]);
int				go_octal(char *str, int *ai);


int				replace_tild(char **line, int *i, t_list *my_env);
int				tokenzer(char **line, t_list *my_env);

int				find_path(char **path, t_list *my_env, t_dl *dl);
int				check_blank_line(char *line);
int				check_bultins(char **tab, t_ab ab[7], t_list **my_env,
								t_dl *dl);
int				exec_cmd_if_ok(char *path, char **tab, t_list *my_env,
								t_dl *dl);
int				exec(char *cmd, t_list **my_env, t_dl *dl, t_ab ab[7]);
int				exec_cmd(t_ab ab[7], t_dl *dl, t_list **my_env);

#endif
