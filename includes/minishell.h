/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 17:58:10 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../libft/includes/libft.h"

/*
********************************************************************************
**                                                                  Structures *
********************************************************************************
*/

/*
** List
*/

typedef	struct		s_comlist
{
	void			*content;
	struct s_comlist	*next;
}					t_comlist;

typedef	struct		s_envlist
{
	void			*var;
	void			*val;
	int				env;
	struct s_envlist	*next;
}					t_envlist;


/*
********************************************************************************
**                                                                   Fonction  *
********************************************************************************
*/

void					env_list_add(t_envlist **l, t_envlist *list);
t_envlist				*create_env_elem(char *var, char *val);
void					get_env_struct(char **str, t_envlist **list);
void					ft_free_tab(char **tab);
void					free_envlist(t_envlist **list);

/*
** V
*/

void				print_drak();
void				print_drakau();
void				print_char();
void				print_char();
void				print_chari();
void				print_chariz();
void				print_chariza();
void				print_charizar();
void				print_charizard();
void				print_shell();

#endif
