#include "../inc/push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int is_sign(char c)
{
    int i;

    i = 0;
    if (c == '+' || c == '-')
            i++;
    return (i);
}

int count_signs(char *str)
{
    int i;
    int c;

    i = -1;
    c = 0;
    while (str[++i])
        c += is_sign(str[i]);
    return (c);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int check_white_spaces(char *str)
{
    int i;

    i = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '\0')
        return (0);
    return (1);
}

char    *str_join(char *s1, char *s2)
{
    char    *s3;
    int     i;
    int     j;

    if (!s2 || s2[0] == '\0'|| !check_white_spaces(s2))
    {
        write(2, "Error\n", 6);
        return (NULL);
    }
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
    if (!s3)
        return (free(s1), s1 = NULL, NULL);
    i = -1;
    while (s1[++i])
        s3[i] = s1[i];
    s3[i] = ' ';
    i++;
    j = -1;
    while (s2[++j])
        s3[i + j] = s2[j];
    s3[i + j] = '\0';
	free(s1);
    return (s3);
}