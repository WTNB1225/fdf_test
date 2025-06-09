/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:15:49 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/09 20:29:21 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *message, bool is_syscall)
{
	if (is_syscall)
		perror(message);
	else
		ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	exit_with_fd(char *message, bool is_syscall, int fd)
{
	if (close(fd) == -1)
		exit_error("Failed to close the file", true);
	exit_error(message, is_syscall);
}
