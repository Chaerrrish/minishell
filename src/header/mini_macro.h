/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_macro.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:30:29 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 14:07:59 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define T_NULL 0
# define T_WORD 1

# define T_BULTIN 2
# define T_EXECUTE 3

# define T_PIPE 4
# define T_REDIR_IN 5
# define T_REDIR_OUT 6
# define T_REDIR_HERE 7
# define T_REDIR_APPEND 8
# define T_REDIR_ERR 9

# define T_SINGLE_QUOTE 10
# define T_DOUBLE_QUOTE 11

#endif