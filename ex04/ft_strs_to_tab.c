/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:03:49 by tchumbas          #+#    #+#             */
/*   Updated: 2025/08/20 14:01:17 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (ft_lenght(str) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					i;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (NULL);
		arr[i].size = ft_lenght(av[i]);
		arr[i].str = ft_strdup(av[i]);
		arr[i].copy = ft_strdup(av[i]);
		if (!arr[i].str || !arr[i].copy)
			return (NULL);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

/* void	print_array(t_stock_str *str)
{
	int	i;

	i = 1;
	while (str[i].str != NULL)
	{
		printf("Indice: %d - Size: %d - String: %s - Copy: %s\n",
		i, str[i].size,	str[i].str, str[i].copy);
			i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	print_array(ft_strs_to_tab(argc, argv));
} */