/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:19:22 by selhanda          #+#    #+#             */
/*   Updated: 2022/02/06 13:17:50 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	first_p(int *fd, char **argve, char **envp, char **argv)
{
	pid_t	pid_1 ;
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		f_eroor(argv[1]);
	pid_1 = fork();
	if (pid_1 < 0)
		f_eroor("pid_1");
	if (pid_1 == 0)
	{
		dup2(file1, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		if (execve("/bin/bash", argve, envp) == -1)
			f_eroor("command not found\n");
	}
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
}

void	second_p(int *fd, char **argve2, char **envp, char **argv)
{
	pid_t	pid_2 ;
	int		file2;

	file2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		f_eroor(argv[4]);
	pid_2 = fork();
	if (pid_2 < 0)
		f_eroor("pid_2");
	if (pid_2 == 0)
	{
		dup2(file2, 1);
		dup2(fd[0], 0);
		if (execve("/bin/bash", argve2, envp) == -1)
			f_eroor("command not found\n");
	}
	close(fd[0]);
	waitpid(pid_2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	char	**argve;
	char	**argve2;

	if (argc != 5)
	{
		write(2, "Invalid argument\n", 17);
		exit(EXIT_FAILURE);
	}
	argve = getarge(argv[2]);
	argve2 = getarge(argv[3]);
	if (pipe(fd) == -1)
		f_eroor("pipe");
	first_p(fd, argve, envp, argv);
	second_p(fd, argve2, envp, argv);
}
