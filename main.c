/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/06 17:07:38 by mschippe		  #+#	#+#			 */
/*   Updated: 2025/01/06 18:46:01 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("43_with_nl", O_RDONLY);
	char *line = get_next_line(fd);
	// while (line)
	// {
	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
}