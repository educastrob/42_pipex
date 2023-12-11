/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:55:24 by educastro         #+#    #+#             */
/*   Updated: 2023/12/11 17:30:38 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *delimiter, t_pipex *d)
{
	int		here_doc;
	char	*line;

	line = NULL;
	here_doc = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (here_doc < 0)
		is_error("heredoc error", d);
	while (1)
	{
		write(1, "here_doc > ", 11);
		line = get_next_line(0);
		if (!ft_strncmp(line, delimiter, ft_strlen(delimiter)))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, here_doc);
		free(line);
	}
	close(here_doc);
	d->fd[0] = open(".heredoc_tmp", O_RDONLY);
	if (d->fd[0] < 0)
	{
		unlink(".heredoc_tmp");
		is_error("heredoc error", d);
	}
}