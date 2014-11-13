/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:40:08 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/14 00:18:40 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "includes/get_next_line.h"

static char			ft_getc(int fd)
{
	char		b[1];
	int			ret;

	ret = read(fd, b, 1);
	if (ret == 0)
		return (0);
	if (ret < 0)
		return (-1);
	else
		return (*b);
}

int			get_next_line(char **sp, int fd)
{
	char		*dest;
	char		*buffer;
	char		*end;
	int			c;

	dest = malloc(sizeof(char) * BUFF_SIZE);
	buffer = dest;
	end = buffer + BUFF_SIZE - 1;
	while ((c = ft_getc(fd)) != 0 && c != '\n' && buffer < end)
		*buffer++ = c;
	*buffer = '\0';
	*sp = ft_strdup(dest);
	return ((c == 0 && ft_strlen(buffer) == 0) ? 0 : 1);
}
