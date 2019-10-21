/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:54:08 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/18 16:45:49 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	printarray(int *arr, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		printf("%d", arr[i]);
		i++;
	}
}

void	ft_toupper2(unsigned int i, char *c)
{
	printf("%d\n", i);
	*c = ft_toupper(*c);
}

void	lst_free(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void	test_lst(void)
{
	t_list	*lst;
	t_list	*temp;
	int		i;
	char	str[] = "toto";

	i = 42;
	lst = ft_lstnew(str, sizeof(str));
	if (lst == NULL)
		return;
	if (ft_strcmp("toto", lst->content) == 0 && lst->content_size == 5 && lst->next == NULL)
		printf("ft_lstnew OK\n");
	else
	{
		printf("ft_lstnew FAIL, aborting following lst tests\n");
		return;
	}
	ft_lstadd(&lst, ft_lstnew(&i, sizeof(i)));
	if (*(int *)lst->content == 42 && strcmp("toto", lst->next->content) == 0)
		printf("ft_lstadd OK\n");
	else
	{
		printf("ft_lstadd FAIL, aborting following lst tests\n");
		return;
	}
	ft_lstadd(&lst, ft_lstnew("tatata", 7));
	temp = lst;
	lst = lst->next;
	ft_lstdelone(&temp, &lst_free);
	if (temp != NULL)
	{
		printf("ft_lstdelone FAIL, aborting following lst tests\n");
		return;
	}
	temp = lst;
	lst = lst->next;
	ft_lstdelone(&temp, &lst_free);
	if (temp != NULL)
	{
		printf("ft_lstdelone FAIL, aborting following lst tests\n");
		return;
	}
	if (ft_strcmp("toto", lst->content) == 0 && lst->content_size == 5 && lst->next == NULL)
		printf("ft_lstdelone OK\n");
	else
	{
		printf("ft_lstdelone FAIL, aborting following lst tests\n");
		return;
	}
	ft_lstadd(&lst, ft_lstnew("tatata", 7));
	ft_lstadd(&lst, ft_lstnew("doggo", 6));
	ft_lstadd(&lst, ft_lstnew("totoro", 7));
	ft_lstiter(lst, &ft_lsttoupper);
	asdasds
}

void	test_tolower(void)
{
	if (ft_tolower('a') == 'a' &&
		ft_tolower('A') == 'a' &&
		ft_tolower('5') == '5')
	{
		printf("ft_tolower OK\n");
	}
	else
		printf("ft_tolower FAIL\n");
}

void	test_toupper(void)
{
	if (ft_toupper('a') == 'A' &&
		ft_toupper('A') == 'A' &&
		ft_toupper('5') == '5')
	{
		printf("ft_toupper OK\n");
	}
	else
		printf("ft_toupper FAIL\n");
}

void	test_isprint(void)
{
	int	i;
	int	ret;
	int	ret2;

	i = 0;
	ret = 0;
	ret2 = 0;
	while (i < 128)
	{
		ret += isprint(i);
		i++;
	}
	i = 0;
	while (i < 128)
	{
		ret2 += ft_isprint(i);
		i++;
	}
	if (ret == ret2)
		printf("ft_isprint OK\n");
	else
	{
		printf("ft_isprint FAIL\n");
		printf("is %d", ret2);
		printf("should be %d\n", ret);
	}
}

void	test_isascii(void)
{
	int	i;
	int	ret;
	int	ret2;
	
	i = 0;
	ret = 0;
	ret2 = 0;
	while (i < 128)
	{
		ret += isascii(i);
		i++;
	}
	i = 0;
	while (i < 128)
	{
		ret2 += ft_isascii(i);
		i++;
	}
	if (ret == ret2)
		printf("ft_isascii OK\n");
	else
		printf("ft_isascii FAIL\n");
}

void	test_isalnum(void)
{
	int	ret;
	int	ret2;

	ret = isalnum('a');
	ret += isalnum('A');
	ret += isalnum('5');
	ret += isalnum('#');
	ret2 = ft_isalnum('a');
	ret2 += ft_isalnum('A');
	ret2 += ft_isalnum('5');
	ret2 += ft_isalnum('#');
	if (ret == ret2)
		printf("ft_isalnum OK\n");
	else
		printf("ft_isalnum FAIL\n");
}

void	test_isdigit(void)
{
	int	ret;
	int	ret2;

	ret = isdigit('a');
	ret += isdigit('A');
	ret += isdigit('5');
	ret2 = ft_isdigit('a');
	ret2 += ft_isdigit('A');
	ret2 += ft_isdigit('5');
	if (ret == ret2)
		printf("ft_isdigit OK\n");
	else
		printf("ft_isdigit FAIL\n");
}

void	test_isalpha(void)
{
	int	ret;
	int	ret2;

	ret = isalpha('a');
	ret += isalpha('A');
	ret += isalpha('5');
	ret2 = ft_isalpha('a');
	ret2 += ft_isalpha('A');
	ret2 += ft_isalpha('5');
	if (ret == ret2)
		printf("ft_isalpha OK\n");
	else
		printf("ft_isalpha FAIL\n");
}

void	test_atoi(void)
{
	if (atoi("  -8401") == ft_atoi("  -8401"))
		printf("ft_atoi OK\n");
	else
		printf("ft_atoi FAIL\n");
}

void	test_strncmp(void)
{
	int	ret;
	int	ret2;

	ret = strncmp("toto", "toto", 4);
	ret2 = ft_strncmp("toto", "toto", 4);
	ret += strncmp("a", "h", 1);
	ret2 += ft_strncmp("a", "h", 1);
	ret += strncmp("doggo", "abc", 3);
	ret2 += ft_strncmp("doggo", "abc", 3);
	if (ret == ret2)
		printf("ft_strncmp OK\n");
	else
		printf("ft_strncmp FAIL\n");
}

void	test_strcmp(void)
{
	int	ret;
	int	ret2;

	ret = strcmp("toto", "toto");
	ret2 = ft_strcmp("toto", "toto");
	ret += strcmp("a", "h");
	ret2 += ft_strcmp("a", "h");
	ret += strcmp("doggo", "abc");
	ret2 += ft_strcmp("doggo", "abc");
	if (ret == ret2)
		printf("ft_strcmp OK\n");
	else
		printf("ft_strcmp FAIL\n");
}

void	test_strnstr(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char	*ptr;

	ptr = ft_strnstr(largestring, smallstring, 4);
	if (ptr == NULL)
		printf("ft_strnstr OK\n");
	else
		printf("ft_strnstr FAIL\n");
}

void	test_strstr(void)
{
	const char haystack[20] = "TutorialsPoint";
	const char needle[10] = "Point";
	char *ret;
	char	*ret2;

	ret = strstr(haystack, needle);
	ret2 = ft_strstr(haystack, needle);
	if (strcmp(ret, ret2) == 0)
		printf("ft_strstr OK\n");
	else
		printf("ft_strstr FAIL\n");
}

void	test_strrchr(void)
{
	const char str[] = "bonjour";
	const char str2[] = "bonjour";
	const char ch = 'b';
	char *ret;
	char *ret2;

	ret = strrchr(str, ch);
	ret2 = ft_strrchr(str2, ch);
	if (strcmp(ret, ret2) == 0)
	{
		printf("ft_strrchr OK\n");
		printf("is %s", ret2);
		printf(" should be %s\n", ret);
	}
	else
	{
		printf("ft_strrchr FAIL\n");
		printf("is %s", ret2);
		printf(" should be %s\n", ret);
	}
}

void	test_strchr(void)
{
	const char str[] = "http://www.tutorialspoint.com";
	const char str2[] = "http://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;
	char *ret2;

	ret = strchr(str, ch);
	ret2 = ft_strchr(str2, ch);
	if (strcmp(ret, ret2) == 0)
		printf("ft_strchr OK\n");
	else
		printf("ft_strchr FAIL\n");
}

void	test_strncat(void)
{
	char	*dest;
	char	*dest2;

	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = strcpy(dest, "This is destination");
	dest2 = strcpy(dest2, "This is destination");
	dest = strncat(dest, "toto", 2);
	dest2 = ft_strncat(dest2, "toto", 2);
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_strncat OK\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_strncat FAIL\n");
}

void	test_strcat(void)
{
	char	*dest;
	char	*dest2;

	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = strcpy(dest, "This is destination");
	dest2 = strcpy(dest2, "This is destination");
	dest = strcat(dest, "toto");
	dest2 = ft_strcat(dest2, "toto");
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_strcat OK\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_strcat FAIL\n");
}

void	test_strncpy(void)
{
	char	*str;
	char	*str2;
	str = _strdup("This string");
	str2 = _strdup("This string");
	str = strncpy(str, "toto", 8);
	str2 = ft_strncpy(str2, "toto", 8);
	if (strcmp(str, str2) == 0)
	{
		printf("ft_strncpy OK\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_strncpy FAIL\n");
}

void	test_strcpy(void)
{
	char	*str;
	char	*str2;
	str = _strdup("This string");
	str2 = _strdup("This string");
	str = strcpy(str, "toto");
	str2 = ft_strcpy(str2, "toto");
	if (strcmp(str, str2) == 0)
	{
		printf("ft_strcpy OK\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_strcpy FAIL\n");
}

void	test_strdup(void)
{
	char	*str;
	char	*str2;
	str = _strdup("This string");
	str2 = ft_strdup("This string");
	str = strncpy(str, "toto", 4);
	str2 = strncpy(str2, "toto", 4);
	if (strcmp(str, str2) == 0)
	{
		printf("ft_strdup OK\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_strdup FAIL\n");
}

void	test_strlen(void)
{
	int	ret;
	int	ret2;

	ret = strlen("toto");
	ret2 = ft_strlen("toto");
	if (ret == ret2)
		printf("ft_strlen OK\n");
	else
		printf("ft_strlen FAIL\n");
}

void	test_memcmp(void)
{
	int	ret;
	int	ret2;

	ret = memcmp("toto", "toto", 4);
	ret2 = ft_memcmp("toto", "toto", 4);
	ret += memcmp("a", "h", 1);
	ret2 += ft_memcmp("a", "h", 1);
	ret += memcmp("doggo", "abc", 3);
	ret2 += ft_memcmp("doggo", "abc", 3);
	if (ret == ret2)
		printf("ft_memcmp OK\n");
	else
		printf("ft_memcmp FAIL\n");
}

void	test_memchr(void)
{
	const char str[] = "http://www.tutorialspoint.com";
	const char str2[] = "http://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;
	char *ret2;

	ret = memchr(str, ch, strlen(str));
	ret2 = ft_memchr(str2, ch, strlen(str2));
	if (strcmp(ret, ret2) == 0)
		printf("ft_memchr OK\n");
	else
		printf("ft_memchr FAIL\n");
}

void	test_memmove(void)
{
	char	*src;
	char	*src2;
	src = (char *)malloc(sizeof(char) * 50);
	src2 = (char *)malloc(sizeof(char) * 50);
	src = memmove(src + 5, src, strlen(src) + 1);
	src2 = ft_memmove(src2 + 5, src2, strlen(src2) + 1);
	if (strcmp(src, src2) == 0)
	{
		printf("ft_memmove OK\n");
		//free(src);
		//free(src2);
	}
	else
		printf("ft_memmove FAIL\n");
}

void	test_memccpy(void)
{
	const char	src[50] = "This test string";
	char		*dest;
	const char	src2[50] = "This test string";
	char		*dest2;
	char		*dptr;
	char		*dptr2;
	
	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = strcpy(dest, "bye");
	dest2 = strcpy(dest2, "bye");
	dptr = (char *)_memccpy(dest, src, 'e', 11);
	dptr2 = (char *)ft_memccpy(dest2, src2, 'e', 11);
	printf("%s\n", dest);
	printf("%s\n", dest2);
	printf("%s\n", dptr);
	printf("%s\n", dptr2);
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_memccpy OK\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_memccpy FAIL\n");
}

void	test_memcpy(void)
{
	const char	src[50] = "This test string";
	char		*dest;
	const char	src2[50] = "This test string";
	char		*dest2;
	dest = (char *)malloc(sizeof(char) * 50);
	dest2 = (char *)malloc(sizeof(char) * 50);
	dest = strcpy(dest, "bye");
	dest2 = strcpy(dest2, "bye");
	dest = (char *)memcpy(dest, src, 11);
	dest2 = (char *)ft_memcpy(dest2, src2, 11);
	if (strcmp(dest, dest2) == 0)
	{
		printf("ft_memcpy OK\n");
		free(dest);
		free(dest2);
	}
	else
		printf("ft_memcpy FAIL\n");
	


}

void	test_bzero(void)
{
	char	*str;
	char	*str2;
	str = _strdup("This string");
	str2 = _strdup("This string");
	ft_bzero(str, 5);
	ft_bzero(str2, 5);
	if (memcmp(str, str2, 11) == 0)
	{
		printf("ft_bzero OK\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_bzero FAIL\n");
}

void	test_memset(void)
{
	char	*str;
	char	*str2;
	str = _strdup("This string");
	str2 = _strdup("This string");
	str = (char *)memset(str, '$', 5);
	str2 = (char *)ft_memset(str2, '$', 5);
	if (strcmp(str, str2) == 0)
	{
		printf("ft_memset OK\n");
		free(str);
		free(str2);
	}
	else
		printf("ft_memset FAIL\n");
}

int		main(void)
{
	/*
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strchr();
	test_strrchr();
	test_strstr();
	test_strnstr();
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_isalpha();
	test_isdigit();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	*/
	test_lst();

	/*
	char	*dest;
	dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 0, 15);
	memset(dest, 's', 13);

	write(1, dest, 15);
	dest = ft_strncpy(dest, "lorem", 8);
	write(1, dest, 15);
	

	char **tab;

	tab = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');

	while (*tab)
	{
		printf("%s\n", *tab);
		tab++;
	}
*/
	system("pause");
	return (0);
}
