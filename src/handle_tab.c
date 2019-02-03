/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/02 10:55:59 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/03 15:46:12 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_arg_len(char *str, t_envlist **envir)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] != '\\' && str[i] != '$' && str[i] != '\'' && str[i] != '"')
			l++;
		else if (str[i] == '\\')
		{
			l++;
			i++;
		}
		else if (str[i] == '\'')
		{
//		dprintf(1, "|i = %d| l = %d\n", i, l);
			l += ft_last_snquote(str, str[i], &i);
//		dprintf(1, "|i = %d| l = %d\n", i, l);
		}
		else if (str[i] == '"')
		{
//		dprintf(1, "BEF |i = %d| l = %d\n", i, l);
			l += ft_dquote_len(str,  &i, envir);
//		dprintf(1, "AFT |i = %d| l = %d\n", i, l);
		}
		if (str[i])
			i++;
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
	while(tab[i])
	{
		dprintf(1, "%s, |i = %d| line len =%i\n", tab[i], i, ft_arg_len(tab[i], envir));
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	ft_free_tab(tab);
	tab = NULL;
	return (new);
}
