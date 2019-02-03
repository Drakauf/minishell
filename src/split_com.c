/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_com.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 13:33:31 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/02 13:26:19 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_tab_len(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int		ft_wordlen(char *s, size_t i)
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
			s[j] == '"' ? k = ft_last_dnquote(s, s[j], &j): 0;
			s[j] == '\'' ? k = ft_last_snquote(s, s[j], &j): 0;
			break ;
		}
		else
			break ;
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
			i++;
		if (line[i])
		{
			while (line[i] && (line[i] >= 13 || line[i] <= 9)
					&& line[i] != ' ' && line[i] != '\'' && line[i] != '"')
				i++;
//			if ((line[i] == '\'' || line[i] == '"'))
//				ft_last_quote(line, line[i], &i, &g);
			line[i] == '\'' ? ft_last_squote(line, line[i], &i, &g) : 0;
			line[i] == '"' ? ft_last_dquote(line, line[i], &i, &g) : 0;
			s++;
			(line[i]) ? i++ : 0;
		}
	}
//	dprintf(1, "total words  = %d\n", s);
	return (s);
}

char	**ft_split_com(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(tab) * ft_words(str) + 1)))
		return (NULL);
	while (str[i])
	{
		while (str[i] && ((str[i] <= 13 && str[i] >= 9) || str[i] == ' '))
			i++;
		if (str[i] && (str[i] == '\''))
		{
//	dprintf(1, "pos bef  = %d\n", i);
			tab[j++] = ft_strsub(str, i, ft_last_snquote(str, str[i], &i) + 1);
//	dprintf(1, "pos aft  = %d\n", i);
		}
		else if (str[i] && (str[i] == '"'))
		{
//	dprintf(1, "pos bef  = %d\n", i);
			tab[j++] = ft_strsub(str, i, ft_last_dnquote(str, str[i], &i) + 1);
//	dprintf(1, "pos aft  = %d\n", i);
		}
			else if (str[i])
		{
			tab[j++] = ft_strsub(str, i, ft_wordlen(str, i));
//			dprintf(1, "wordlen = %d %c\n", ft_wordlen(str, i), str[i]);
			i += ft_wordlen(str, i);
		}
		str[i] ? i++: 0;
	}
	tab[j] = NULL;
	return (tab);
}
