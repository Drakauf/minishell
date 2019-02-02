/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quote.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:28:16 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/02 13:20:28 by shthevak    ###    #+. /#+    ###.fr     */
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
			str[m + *i + 1] <= 13) || str[m + *i + 1] == ' '))
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
			str[m + *i + 1] <= 13) || str[m + *i + 1] == ' '))
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

int		ft_last_snquote(char *str, char c, int *i)
{
	int		m;
	int		l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c)
		{
			while (str[m + *i + 1] && !((str[m + *i + 1] >= 9 &&
			str[m + *i + 1] <= 13) || str[m + *i + 1] == ' '))
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

void	ft_last_squote(char *str, char c, int *i, int *k)
{
	int		m;
	int		l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c)
		{
			while (str[m + *i + 1] && !((str[m + *i + 1] >= 9 &&
			str[m + *i + 1] <= 13) || str[m + *i + 1] == ' '))
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
