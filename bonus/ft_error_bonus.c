/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:35:52 by jojo              #+#    #+#             */
/*   Updated: 2024/12/12 13:55:45 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(int ac, char **av)
{
	pid_t	pid;
	char	**args;

	if (ac < 5)
		msg_error("Number of argument not correct.");
	else if (access(av[1], F_OK) == -1)
		msg_error("File 1");
	args = ft_alloc("touch ", av[ac - 1]);
	if (args == NULL)
	{
		ft_cleartab(args);
		msg_error("Can't malloc args.");
	}
	else if (access(av[ac - 1], F_OK) == -1)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_cleartab(args);
			msg_error("Erreur fork.");
		}
		if (pid == 0)
			execve("/usr/bin/touch", args, NULL);
	}
	ft_cleartab(args);
}
