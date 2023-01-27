/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:07:08 by mgamil            #+#    #+#             */
/*   Updated: 2023/01/27 11:14:28 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_printf("[%i]={%s}\n", i, tab[i]);
}