/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_write_trunk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:25:09 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 12:15:48 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "hered.h"

void	open_to_read(t_element *element)
{
	element->fd = open(element->arg[1], O_RDONLY);
	if (element->fd < 0)
	{
		g_state = errno;
		ft_putstr_fd("SFH: ", 2);
		ft_putstr_fd(element->arg[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		exit (g_state);
	}
	else
		dup2(element->fd, STDIN_FILENO);
	close(element->fd);
}

void	open_to_write(t_element *element)
{
	element->fd = open(element->arg[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (element->fd < 0)
	{
		g_state = errno;
		ft_putstr_fd("SFH: ", 2);
		ft_putstr_fd(element->arg[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		exit (g_state);
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

void	open_to_trunk(t_element *element)
{
	element->fd = open(element->arg[1], O_APPEND | O_RDWR | O_CREAT, 0644);
	if (element->fd < 0)
	{
		g_state = errno;
		ft_putstr_fd("SFH: ", 2);
		ft_putstr_fd(element->arg[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		exit (g_state);
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}
