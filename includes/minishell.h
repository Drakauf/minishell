/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 01:50:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 13:46:24 by shthevak    ###    #+. /#+    ###.fr     */
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

typedef	struct			s_comlist
{
	void				*content;
	struct s_comlist	*next;
}						t_comlist;

typedef	struct			s_envlist
{
	void				*var;
	void				*val;
	int					env;
	struct s_envlist	*next;
}						t_envlist;

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
int						ft_last_snquote(char *str, char c, int *i);
void					ft_last_squote(char *str, char c, int *i, int *k);
int						ft_last_dnquote(char *str, char c, int *i);
void					ft_last_dquote(char *str, char c, int *i, int *k);
int						next_comma(int i, char c, char *line);
int						separate_scolon(char *line, int k);
char					**ft_split_com(char *str);
int						ft_words(char *line);
int						ft_wordlen(char *str, size_t i);
int						ft_tab_len(char **tab);
char					**ft_handle_tab(char **tab, t_envlist **envir);
int						ft_dquote_len(char *s, int *i, t_envlist **envir);
int						ft_var_len(char *com, int *i, t_envlist **envir);
char					*ft_split_var(char *c);
void					ft_arg_copy(char *str, char **ne, t_envlist**envir);
int						ft_copy_var(char *s, char **n, int *i, t_envlist **e);
void					ft_getin_squote(char *str, char **ne, int *i, int *j);
int						ft_getin_dquote(char *s, char **n, int *i,\
						t_envlist **e);
void					ft_to_execute(char **tab, t_envlist **envir);
int						ft_is_path(char *str);
int						ft_valid_path(char *str);
int						ft_valid_execp(char *str);
char					*ft_get_path(t_envlist **envir);
char					*ft_get_val(char *str, t_envlist **envir);
int						ft_is_builtin(char **tab, t_envlist **envir);
void					ft_change_env(char *var, char *val, t_envlist **env);
void					ft_print_env(t_envlist **env);
int						ft_cd(char **tab, t_envlist **env);
int						ft_env(char **tab, t_envlist **env);
int						ft_set_env(char **tab, t_envlist **env);
int						ft_unset_env(char **tab, t_envlist **env);

/*
** P
*/

void					print_drak();
void					print_drakau();
void					print_char();
void					print_char();
void					print_chari();
void					print_chariz();
void					print_chariza();
void					print_charizar();
void					print_charizard();
void					print_shell();

#endif
