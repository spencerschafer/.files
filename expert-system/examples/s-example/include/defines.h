/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:18:55 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/12 09:16:39 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define UNKNOWN 2
# define UNDETERMINED 6
# define ADD 3
# define GET 4
# define SETUP 5
# define REMOVE 6

# define LOGICS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define SIGN "+|^"

# define WHY "why is [A-Z] (true|false|undetermined|True|False|Undetermined|FALSE|TRUE|UNDETERMINED)"
# define WHAT "what is the value of [A-Z]"
# define SET "add fact [A-Z] is (true|false|True|False|TRUE|FALSE)"
# define UNSET "remove fact [A-Z]"
# define REG_COM "Error Compiling Regex"

# define KGREEN "\x1B[32m"
# define KRED "\x1B[31m"
# define KBLUE "\x1B[34m"
# define NONE "\033[0m"
# define RESET "\x1b[0m"
# define KMAG "\x1B[35m"

#endif
