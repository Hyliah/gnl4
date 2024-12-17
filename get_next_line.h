/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:33:43 by hlichten          #+#    #+#             */
/*   Updated: 2024/12/16 19:46:34 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// a supprimer pour les tests
#include <stdio.h> 
#include <stdio.h>
#include <fcntl.h>

int				ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
char *			get_next_line(int fd);
char *			ft_strchr(const char *s, int c);
char *			ft_strjoin(char *s1, char *s2);

#endif