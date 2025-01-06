/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 18:22:08 by mschippe		  #+#	#+#			 */
/*   Updated: 2025/01/06 19:01:59 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *s, int c);
char	*ft_substr(char *source, size_t start, size_t length);
size_t	ft_strlen(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t size);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);
char	*get_next_line(int fd);
#endif