/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_com.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:33:31 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 14:29:02 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_wordlen(char *s, size_t i)
{
		int j;
		int	k;

			j = i;
			k = 0;
			while (s[j])
			{
				while (s[j] && (s[j] <= 9 || s[j] >= 13) && s[j] != ' ' &&
						s[j] != '\'' && s[j] != '"')
							j++;
				if (s[j] && (s[j] == '"' || s[j] == '\''))
				{
					k = ft_last_nquote(s, s[j], &j);
					break ;
				}
			}
					return (j - i);
}

int		ft_words(char *line)
{
	int i;
	int g;
	int s;

	i = 0;
	g = 0;
	s = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		while (line[i] && ((line[i] <= 13 && line[i] >= 9) || line[i] == ' '))
		{
			i++;
		}
		if (line[i])
		{
				while (line[i] && (line[i] >= 13 || line[i] <= 9)
						&& line[i] != ' ' && line[i] != '\'' && line[i] != '"')
					i++;
			if ((line[i] == '\'' || line[i] == '"'))
			{
				ft_last_quote(line, line[i], &i, &g);
			}
			s++;
			(line[i]) ? i++ : 0;
		}
	}
	return (s);
}


char	**ft_split_com(char *str)
{
	int i;
	int j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(tab) * ft_words(str) + 1)))
		return (NULL);
	while (str[i])
	{
		while (str[i] && ((str[i] <= 13 && str[i] >= 9) || str[i] == ' '))
			i++;
		if (str[i] && (str[i] == '\'' || str[i] == '"'))
			tab[j++] = ft_strsub(str, i, ft_last_nquote(str, str[i], &i) +1);
		else if (str[i])
		{
			tab[j++] = ft_strsub(str, i, ft_wordlen(str, i));
			i += ft_wordlen(str, i);
		}
		if (str[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
