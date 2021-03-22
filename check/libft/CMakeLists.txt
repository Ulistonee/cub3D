
cmake_minimum_required(VERSION 3.17)

project(libft C)

set(CMAKE_C_STANDARD 11)

add_library(libft STATIC
        ft_isascii.c
        ft_memcmp.c
        ft_strrchr.c
        ft_atoi.c
        ft_isdigit.c
        ft_memcpy.c
        ft_strlcpy.c
        ft_tolower.c
        ft_bzero.c
        ft_isprint.c
        ft_memmove.c
        ft_toupper.c
        ft_isalnum.c
        ft_memccpy.c
        ft_memset.c
        ft_strncmp.c
        ft_isalpha.c
        ft_memchr.c
        ft_strchr.c
        ft_strnstr.c
        ft_calloc.c
        ft_strdup.c
        ft_putnbr_fd.c
        ft_strlen.c
        ft_putchar_fd.c
        ft_strlcat.c
        ft_putstr_fd.c
        ft_putendl_fd.c
        ft_substr.c
        ft_strjoin.c
        ft_strtrim.c
        ft_split.c
        ft_strmapi.c
        ft_itoa.c
        ft_free_mem.c
        ft_itoa_base.c
        ft_itoa_uhex.c
        ft_itoa_u.c
        libft.h)
