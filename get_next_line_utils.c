/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 18:33:10 by mschippe		  #+#	#+#			 */
/*   Updated: 2025/01/06 19:02:08 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *source, size_t start, size_t length) {
	char	*result;
	char 	*source_start;
	char 	*result_start;
	
	if (start >= ft_strlen(source))
		return (NULL);
	result = malloc(length + 1);
	if (!result)
		return (NULL);
	source_start = source + start;
	result_start = result;
	while (length-- > 0)
		*result++ = *source_start++;
	*result = '\0';
	return (result_start);
}

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size) {
	size_t	copy_size;
	size_t	i;
	if (new_size == 0)
		return(free(ptr), NULL);
	if (!ptr)
		return malloc(new_size);
	void *new_ptr = malloc(new_size);
	if (!new_ptr)
		return NULL;
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	i = 0;
	while (i < copy_size)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return new_ptr;
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	available_space;
	size_t	count;

	dstsize = 0;
	srcsize = 0;
	available_space = 0;
	count = 0;
	while (dst[dstsize] && dstsize < size)
		dstsize++;
	while (src[srcsize])
		srcsize++;
	if (dstsize == size)
		return (size + srcsize);
	available_space = size - dstsize - 1;
	while (src[count] && count < available_space)
	{
		dst[dstsize + count] = src[count];
		count++;
	}
	dst[dstsize + count] = '\0';
	return (dstsize + srcsize);
}
