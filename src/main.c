/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 18:24:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 18:42:09 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		next_comma(int i, char c, char *line)
{
	int	k;

	k = 1;
	while (line[i + k])
	{
		if (line[i + k] == c && (i + k - 1 >= 0 && line[i + k - 1] != '\\'))
		{
			break;
		}
		k++;
	}
	if (line[i + k])
		return (i + k);
	else
		return (i);
}

int		separate_comma(char *line, int k)
{
	int		i;

	i = 0;
	while (line[k + i])
	{
		if (line[k + i] == '\'')
			i = next_comma(i, '\'', line);
		else if (line[k + i] == '\"')
			i = next_comma(i, '\"', line);
		else if (line[k + i] == ';' && ((k + i == 0) || (line[k + i - 1] && line[k + i - 1] != '\\')))
			return (k + i);
		if (line[i + k])	
			i++;
	}
	return (k + i);
}

int		ft_last_nquote(char *str, char c, int *i)
{
	int		m;
	int 	l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c && (((m + *i) > 0 && str[m + *i - 1] != '\\') || (!str[m + *i + 1])))
		{
			l = m;
			break ;
		}
		m++;
	}
	*i += l + 1;
	return (l);
}

void		ft_last_quote(char *str, char c, int *i, int *k)
{
	int		m;
	int 	l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c && (((m + *i) > 0 && str[m + *i - 1] != '\\') || (!str[m + *i + 1])))
		{
			l = m;
			break ;
		}
		m++;
	}
	*i += l + 1;
	*k += l;
}

int	ft_var_len(char *com, int i, t_envlist **envir)
{
	char	**tab;
	t_envlist *list;

	list = *envir;
	tab = ft_strsplit(com + i +1, ' ');
	while (list)
	{
		if (ft_strcmp(tab[0], list->var) == 0)
		{
			ft_free_tab(tab);
			return (ft_strlen(list->val));
		}
		list = list->next;
	}
	ft_free_tab(tab);
	return (0);
}
void	ft_command_len(char **str, t_envlist **envir, int *l)
{
	int		i;
	char	*com;

	i = 0;
	com = *str;
	while (com[i])
	{
		if (com[i] != '\\' && com[i] != '$' && com[i] != '\'' && com[i] != '"')
			(*l)++;
		else if (com[i] == '\\')
		{
			(*l)++;
			i++;
		}
		else if (com[i] == '"' || com[i] == '\'')
			ft_last_quote(com, com[i], &i, l);
		else if (com[i] == '$')
		{
			(*l) += ft_var_len(com, i, envir);
			while (com[i + 1] && (com[i + 1] >= 13 || com[i + 1] <= 9 )
					&& com[i + 1] != ' ')
				i++;
		}
		com[i] ? i++ : 0;
	}
}

void	ft_getin_quote(char **str, char **new, int *i, int *j)
{
	int k;
	int	m;
	char	c;

	k = 0;
	m = 0;
	c = (*str)[(*i)];
	ft_last_quote((*str) + (*i + 1), c, &m, &k);
	if (k != 0)
	{
		while ((*str)[*i])
		{
			if ((*str)[*i] == '\\' && !((*str)[(*i) + 1] == c && !((*str)[(*i) + 2])))
				(*new)[(*j)++] = (*str)[++(*i)];
			else if ((*str)[*i] == c)
				break ;
			else
				(*new)[(*j)++] = (*str)[*i];
			(*i)++;
		}
	}
}

int	ft_getvar(char	**str, char **new, int *i, t_envlist **envir)
{
	char	**tab;
	t_envlist *list;

	list = *envir;
	tab = ft_strsplit((*str) + *i + 1, ' ');
	while (list)
	{
		if (ft_strcmp(tab[0], list->var) == 0)
		{
			*new = ft_strcat(*new, list->val);
			(*i) += ft_strlen(tab[0]);
			ft_free_tab(tab);
			return (ft_strlen(list->val));
		}
		list = list->next;
	}
	ft_free_tab(tab);
	while ((*str)[*i] && ((*str)[*i] <= 9 || (*str)[*i] >= 13) && (*str)[*i] != ' ')
	{
		(*i)++;
	}
	return (0);
}

void	ft_copy_com(char **str, char **new, t_envlist **envir)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while((*str)[i])
	{
		if ((*str)[i] != '\\' && (*str)[i] != '$' && (*str)[i] != '\'' && (*str)[i] != '"')
			(*new)[j++] = (*str)[i];
		else if ((*str)[i] == '\\')
		{
			i++;
			(*new)[j++] = (*str)[i];
		}
		else if ((*str)[i] == '\'' || (*str)[i] == '"')
			ft_getin_quote(str, new, &i, &j);
		else if ((*str)[i] == '$')
			j += ft_getvar(str, new, &i, envir);
		if ((*str)[i])
			i++;
	}
}

size_t	ft_wordlen(char *s, size_t i)
{
	size_t j;

	j = 0;
	while (s[i + j] && (s[i + j] <= 9 || s[i + j] >= 13) && s[i + j] != ' ')
		j++;
	return (j);
}

char	**ft_com_exe(char *s)
{
	int i;
	int j;
	char **tab;

	i = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		i++;
	j = ft_wordlen(s, i);
	if (!j)
		return (NULL);
	if (!((tab) = malloc(sizeof(char *) * 3)))
		return (NULL);
	tab[2] = NULL;
	if (!((tab[0]) = ft_strsub(s, i, j)))
			return (NULL);
//	dprintf(1, "tab0 =%s\n", (tab)[0]);
	i += j;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		i++;
	if (!((tab[1]) = ft_strsub(s, i, ft_strlen(s))))
	{
			ft_free_tab(tab);
			return (NULL);
	}
//	dprintf(1, "tab1 =%s\n", (tab)[1]);
	ft_free_tab(tab);
	tab = NULL;
	return (tab);
}

void	ft_handle_command(char **str, t_envlist **envir)
{
	int		l;
	char	*com;
	char	**ctab;

	l = 0;
	ft_command_len(str, envir, &l);
	com = ft_strnew(l);
	ft_copy_com(str, &com, envir);
//	dprintf(1, "%s\n", com);
	ctab = ft_com_exe(com);
	free(com);
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
//			dprintf(1, "|word0|\n");
			i++;
		}
		if (line[i])
		{
			if (line[i] && (line[i] == '\'' || line[i] == '"'))
			{
				ft_last_quote(line, line[i], &i, &g);
				i++;
			}
			else
			{
				while (line[i] /*&& (line[i] >= 13 || line[i] <= 9) && line[i] != ' '*/)
					i++;
			}
			s++;
		(line[i]) ? i++ : 0;
		}
	}
//	dprintf(1, "|word1|\n");
	return (s);
}

char	**ft_commandetab(char *str)
{
	int i;
	int j;
	char	**tab;

	i = 0;
	j = 0;
//	dprintf(1, "|test0|\n");
	if (!(tab = malloc(sizeof(tab) * ft_words(str) + 1)))
		return (NULL);
//	dprintf(1, "|test1|\n");
	while (str[i])
	{
		dprintf(1, "%d\n", i);
		while (str[i] && (str[i] <= 13 && str[i] >= 9) && str[i] == ' ')
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
//	dprintf(1, "|test2|\n", tab[i]);
	tab[j] = NULL;
	return (tab);
}

void	ft_parse_line(char *line, t_envlist **envir)
{
	char	*str;
	char	**tab;
	int 	i;
	int 	j;


	i = 0;
	j = 0;
	str = NULL;
//	tab = ft_commandetab(line);
//	while (tab[i])
//	{
//		dprintf(1, "|%s|\n", tab[i]);
//		i++;
//	}
//	i = 0;
//	dprintf(1, "words = %i\n", ft_words(line));
/*	while (line[i])
	{
		i = separate_comma(line, i);
		str = ft_strsub(line, j, i);
		ft_handle_command(&str, envir);
		if (str)
			free(str);
		if (line[i])
			i++;
		j = i;
	}*/
}

int		ft_prompt(t_envlist **envir)
{
	static int	i = 1;
	char	*line;

	line = NULL;
	if (i)
	{
		ft_putstr("$> ");
		i = 0;
	}
	if (get_next_line(0, &line))
	{
		ft_parse_line(line, envir);
		if (ft_strcmp("exit", line) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = NULL;
		i = 1;
	}
	return (1);
}

int main(int argc, char **argv, char **env)
{
	t_envlist	*env_list;
	print_drak();
	env_list = NULL;
	get_env_struct(env, &env_list);
	while (1)
	{
		if (!(ft_prompt(&env_list)))
			break;
	}
	free_envlist(&env_list);
	return (0);
}
