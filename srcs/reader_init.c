/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:16:30 by pducos            #+#    #+#             */
/*   Updated: 2022/09/15 00:19:30 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_reader.h"
#include <stdbool.h>
#include <unistd.h>

bool	reader_init(t_reader *r, int fd)
{
	r->fd = fd;
	if (read(r->fd, 0, 0) != -1)
	{
		r->sv.buf = NULL;
		r->sv.size = 0;
		r->checked = 0;
		r->cap = 0;
		return (true);
	}
	write(STDERR_FILENO, "reader_init error\n", 18);
	return (false);
}
