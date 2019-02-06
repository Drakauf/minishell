/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/02 10:55:59 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 14:10:49 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_arg_copy(char *str, char **new, t_envlist **envir)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\\' && str[i] != '$' && str[i] != '\'' && str[i] != '"'
				&& str[i] != '~')
			(*new)[j++] = str[i];
		else if (str[i] == '\\')
		{
			i++;
			(*new)[j++] = str[i];
		}
		else if (str[i] == '\'')
			ft_getin_squote(str, new, &i, &j);
		else if (str[i] == '"')
			j += ft_getin_dquote(str, new, &i, envir);
		else if (str[i] == '$' || str[i] == '~')
			j += ft_copy_var(str, new, &i, envir);
		if (str[i])
			i++;
	}
}

int		ft_arg_len(char *str, t_envlist **envir)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] != '\\' && str[i] != '$' && str[i] != '\'' && str[i] != '"'
			&& str[i] != '~')
			l++;
		else if (str[i] == '\\')
		{
			l++;
			i++;
		}
		else if (str[i] == '\'')
			l += ft_last_snquote(str, str[i], &i);
		else if (str[i] == '"')
			l += ft_dquote_len(str, &i, envir);
		else if (str[i] == '$' || str[i] == '~')
			l += ft_var_len(str, &i, envir);
		str[i] ? i++ : 0;
	}
	return (l);
}

char	**ft_handle_tab(char **tab, t_envlist **envir)
{
	int		i;
	char	**new;

	i = ft_tab_len(tab);
	if (!(new = malloc(sizeof(char **) * (i + 1))))
	{
		ft_free_tab(tab);
		return (NULL);
	}
	new[i] = NULL;
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strnew(ft_arg_len(tab[i], envir));
		ft_arg_copy(tab[i], &(new[i]), envir);
		i++;
	}
	ft_free_tab(tab);
	tab = NULL;
	return (new);
}
