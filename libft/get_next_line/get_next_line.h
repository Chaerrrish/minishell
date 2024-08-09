/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:25 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/10 21:47:15 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *str);
char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
char	*gnl_strdup(char *s1);

#endif