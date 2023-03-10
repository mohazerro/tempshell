/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:14:05 by mgamil            #+#    #+#             */
/*   Updated: 2023/01/28 02:16:11 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checksyntax(char *s)
{
	// char	**tab;
	// int		len;
	// char	*temp;
	// int		i;

	// temp = ft_strtrim(s, " ");
	// len = ft_strlen(temp);
	// if (!len)
	// 	return (free(temp), free(s), 1);
	// i = -1;
	// while (METACHAR[++i])
	// 	if (METACHAR[i] == temp[len - 1])
	// 		return (free(temp), free(s),
	// 			ft_printf("bash: syntax error near unexpected token '%c'!\n",
	// 				METACHAR[i]));
	// i = 1;
	// while (METACHAR[++i])
	// 	if (METACHAR[i] == temp[0])
	// 		return (free(temp), free(s),
	// 			ft_printf("bash: syntax error near unexpected token '%c'!\n",
	// 				METACHAR[i]));
	// if (checkagain(temp, len))
	// 	return (free(s), 1);
	// free(temp);
	return (0);
}

int	checkquotes(char *s)
{
	int		quote;
	int		i;
	char	c;

	quote = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != SQUOTE && s[i] != DQUOTE)
			i++;
		if (s[i] && (s[i] == SQUOTE || s[i] == DQUOTE))
		{
			c = s[i];
			if (s[i++] == c)
				quote++;
			while (s[i] && (s[i] != c))
				i++;
			if (s[i++] == c)
				quote++;
			else
				break ;
		}
	}
	if (quote % 2)
		return (printf("unclosed quotes !\n"), free(s), 1);
	return (0);
}

int	checkagain(char *temp, int len)
{
	// int	i;
	// int	j;

	// i = 2;
	// while (METACHAR[++i])
	// {
	// 	j = -1;
	// 	while (temp[++j])
	// 		if (temp[j] == METACHAR[i])
	// 			return (free(temp),
	// 				printf("bash: syntax error near unexpected token '%c'\n",
	// 					METACHAR[i]));
	// }
	return (0);
}

int	isaredirection(char *s)
{
	if (!ft_strcmp(s, ">"))
		return (1);
	else if (!ft_strcmp(s, ">>"))
		return (2);
	else if (!ft_strcmp(s, "<"))
		return (3);
	else if (!ft_strcmp(s, "<<"))
		return (4);
	return (0);
}

int	syntax(t_data *data, char *str)
{
	if (!*str)
		return (1);
	if (checksyntax(str) || checkquotes(str) || !parsing(str))
	{
		data->status = 2;
		return (1);
	}
	if (!ft_strcmp(str, "exit"))
	{
		data->status = 0;
		return (2);
	}
	return (0);
}
