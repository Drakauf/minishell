/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 18:24:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 17:59:55 by shthevak    ###    #+. /#+    ###.fr     */
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

void		ft_last_quote(char *str, char c, int *i, int *k)
{
	int		m;
	int 	l;

	m = 1;
	l = 0;
	while (str[m + *i])
	{
		if (str[m + *i] == c)
			l = m - 1;
		m++;
	}
	*i += l + 1;
	*k += l;
}
/*
   int		ft_new_str_len(char *str, int i, int j)
   {
   int		k;
   int		r;

   k = 0;
   r = 0;
   while (j + k < i)
   {

   if (str[j + k] != '\0'&& str[j + k] != '\"' && str[j + k] != '\\' && str[j + k] != '\'' && str[j + k] != ';')
   r++;
   if ((str[j + k] == '\\' || str[j + k] == '\'') && (j + k -1 >= 0 && str[j + k - 1] == '\\'))
   r++;
   if (str[j + k] == '\'' && ((j + k -1 >= 0 && str[j + k - 1] == '\\')))*/
//					
//		{
//			r += ft_next_quote(str, '\'', i, j + k);
//			k += ft_next_quote(str, '\'', i, j + k) + 1;
//		}
//		if (str[j + k] == '"' /*&& ((j + k -1 >= 0 && str[j + k - 1] == '\\'))*/)
//		{
//			r += ft_next_quote(str, '\"', i, j + k);
//			k += ft_next_quote(str, '\'', i, j + k) + 1;
//		}
//		if (str[j + k] == ';' && (j + k -1 >= 0 && str[j + k - 1] == '\\'))
//			r++;
//		k++;
//	}
//	return (r);
//}
//
//char	*ft_get_command(char *str, int	i, int j)
//{
//	char	*new;
//	int		k;
//	int		c;
//	int		d;
//
//	k = ft_new_str_len(str, i, j);
//	dprintf(1, "len = %i\n", k);
//	if (k == 0 || !(new = malloc(sizeof(char) * (k + 1))))
//		return (NULL);
//	k = 0;
//	c = 0;
//	while (j + k < i)
//	{
//		dprintf(1, "char %c\n", str[j + k]);
//		if (str[j + k] != '\0'&& str[j + k] != '\"' && str[j + k] != '\\' && str[j + k] != '\'' && str[j + k] != ';')
//			new[c++] = str[j + k];
//		if ((str[j + k] == '\\' || str[j + k] == '\'')&& (j + k -1 >= 0 && str[j + k - 1] == '\\'))	
//		{
//			dprintf(1, "d2 =\n", d);
//			if (c > 0 && new[c - 1] != '\\')
//				new[c++] = str[j + k];
//		}
//		if (str[j + k] == '\'' && (d = ft_next_quote(str, '\'', i, j + k)))
//		{
//				dprintf(1, "d1 = %d\n", d);
//			while(d-- > 0)
//			{
//				new[c++] = str[j + 1 + k++];
//			}
//		}
//		if (str[j + k] == '\"' && (d = ft_next_quote(str, '\"', i, j + k)))
//			while(d--)
//				new[c++] = str[j + 1 + k++];
//		if (str[j + k] == ';' && (j + k -1 >= 0 && str[j + k - 1] == '\\'))
//			new[c++] = str[j + k];
//		k++;
//	}
//	new[c] = '\0';
//	return (new);
//}

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
			dprintf(1, "ret = %d\n" ,ft_strlen(list->val));
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
			while (com[i + 1] && com[i + 1] != '\t' && com[i + 1] != '\f' && com[i + 1] != '\v'
					&& com[i + 1] != '\n' && com[i + 1] != '\r' && com[i + 1] != ' ')
				i++;
		}
		com[i] ? i++ : 0;
	}
}

void	ft_handle_command(char **str, t_envlist **envir)
{
	int		l;

	l = 0;
	ft_command_len(str, envir, &l);
}

void	ft_parse_line(char *line, t_envlist **envir)
{
	char	*str;
	int 	i;
	int 	j;


	i = 0;
	j = 0;
	str = NULL;
	while (line[i])
	{
		i = separate_comma(line, i);
		str = ft_strsub(line, j, i);
		ft_handle_command(&str, envir);
		//	dprintf(1, "%i %s\n", i, str);
		if (str)
			free(str);
		if (line[i])
			i++;
		j = i;
	}
}

void	ft_prompt(t_envlist **envir)
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
		free(line);
		line = NULL;
		i = 1;
	}
}

int main(int argc, char **argv, char **env)
{
	t_envlist	*env_list;
	print_drak();
	env_list = NULL;
	get_env_struct(env, &env_list);
	////
/*	t_envlist	*enviro = env_list;

	while (enviro)
	{
		dprintf(1, "%s = %s\n", enviro->var, enviro->val);
		enviro = enviro->next;
	}
*/	///
	while (1)
	{
		ft_prompt(&env_list);
	}
	free_envlist(&env_list);
	return (0);
}
