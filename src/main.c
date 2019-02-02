/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 18:24:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/02 13:11:33 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
//		else if (com[i] == '"' || com[i] == '\'')
//			ft_last_dquote(com, com[i], &i, l);
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
//	ft_last_quote((*str) + (*i + 1), c, &m, &k);
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

void	ft_parse_line(char *line, t_envlist **envir)
{
	char	*str;
	char	**tab;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	str = NULL;
//	int k;
	while (line[i])
	{
		i = separate_scolon(line, i);
		((str = ft_strsub(line, j, i))) ? 0: exit(0);
//		dprintf(1, "Here");
		tab = ft_split_com(str);
/****************/

//		tab ? tab = ft_handle_tab(tab) : 0;
/****************/
/**/
		int k;
		k = 0;
		if (tab)
		{
			while (tab[k])
			{
				dprintf(1, "|%s|\n", tab[k]);
				k++;
			}
		}

/**/
//		ft_handle_command(&str, envir);
		str ? free(str): 0;
		ft_free_tab(tab);
		line[i] ? i++: 0;
		j = i;
	}
}

int		ft_prompt(t_envlist **envir)
{
	static int	i = 1;
	char	*line;

	line = NULL;
	if (i)
	{
		/**** Print Dir ****/
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
