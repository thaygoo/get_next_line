/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huburton <huburton@student.s19.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:42:12 by huburton          #+#    #+#             */
/*   Updated: 2025/01/10 13:24:18 by huburton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
 {
    int    fd;
    char *line;
    
	fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free(line);
            break;
        }
        printf("%s", line);
        free(line);
    }
    close(fd);

	fd = open("files/empty", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free(line);
            break;
        }
        printf("%s", line);
        free(line);
    }
    close(fd);

	fd = open("files/big_line_no_nl", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free(line);
            break;
        }
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
