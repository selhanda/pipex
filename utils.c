/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:19:40 by selhanda          #+#    #+#             */
/*   Updated: 2022/02/06 13:20:03 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f_eroor(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	**getarge(char cmd[])
{
	char	**all;

	if (! *cmd)
	{
		write(2, "command not found\n", 18);
		exit (EXIT_FAILURE);
	}
	all = (char **)malloc(sizeof(char *) * 4);
	all[0] = "bash";
	all[1] = "-c";
	all[2] = cmd;
	all[3] = NULL;
	return (all);
}
