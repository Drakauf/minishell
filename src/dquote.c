/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dquote.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:27:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 17:18:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_last_dnquote(char *str, char c, int *i)
{
	int		m;
	int		l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c && ((m + *i > 0 && str[m + *i - 1] != '\\') ||
		(str[m + *i - 1] != '\\' && (!str[m + *i + 1] || (str[m + *i + 1] <= 13
		&& str[m + *i + 1] >= 9) || str[m + *i + 1] == ' '))))
		{
			while (str[m + *i + 1] && !((str[m + *i + 1] >= 9 &&
			str[m + *i + 1] <= 13) || str[m + *i + 1] == ' '/* ||
						str[m + *i + 1] == '\'' || str[m + *i + 1] == '"'*/))
				m++;
			l = m;
			break ;
		}
		m++;
	}
	if (str[m + *i] == c)
		*i += l + 1;
	else
		*i += l;
	return (l);
}

void	ft_last_dquote(char *str, char c, int *i, int *k)
{
	int		m;
	int		l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c && ((m + *i > 0 && str[m + *i - 1] != '\\') ||
		(str[m + *i - 1] != '\\' && (!str[m + *i + 1] || (str[m + *i + 1] <= 13
		&& str[m + *i + 1] >= 9) || str[m + *i + 1] == ' '))))
		{
			while (str[m + *i + 1] && !((str[m + *i + 1] >= 9 &&
			str[m + *i + 1] <= 13) || str[m + *i + 1] == ' '/* ||
						str[m + *i + 1] == '\'' || str[m + *i + 1] == '"'*/))
				m++;
			l = m;
			break ;
		}
		m++;
	}
	if (str[m + *i] == c)
		*i += l + 1;
	else
		*i += l;
	*k += l;
}

int		ft_dquote_len(char *s, int *i, t_envlist **envir)
{
	int		m;
	int		l;

	m = *i;
	l = 0;
	while (s[++m])
	{
		if (s[m] == '"' && ((m > 0 && s[m - 1] != '\\') || (s[m - 1] != '\\' &&
						(!s[m + 1] || (s[m + 1] <= 13 && s[m + 1] >= 9)
						 || s[m + 1] == ' '))))
		{
			while (s[m + 1] && !((s[m + 1] >= 9 &&
							s[m + 1] <= 13) || s[m + 1] == ' ' ||
						s[m + 1] == '\'' || s[m + 1] == '"'))
			{
				l++;
				m++;
			}
			break ;
		}
		(s[m] == '$' && s[m - 1] != '\\') ? l += ft_var_len(s, &m, envir) : l++;
	}
	(s[m] == '"') ? (*i += m - *i + 1) : ((*i) += m - *i);
	return (l);
}
