/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoung <jyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:26:24 by jyoung            #+#    #+#             */
/*   Updated: 2019/09/20 15:50:14 by jyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

int		get_next_line(const int fd, char **line);

#endif
