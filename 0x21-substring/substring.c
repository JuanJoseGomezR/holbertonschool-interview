#include "substring.h"

/**
 * is_a_match - check wheter is a match between s and the stings in words
 * @s: the string to scan
 * @words: the array of words all substringsmust be a concatenation
 * arrangement of
 * @nb_words: the number of elements in the array words that are not NULL
 * @len_word: the lenght of the strings in words
 * @n: the number of elements in the array words
 * Return: 1 if it is a macthc, otherwise 0
 */
int is_a_match(char const *s, char **words, int nb_words, int len_word, int n)
{
	int i, match;
	char *tmp;

	if (nb_words == 0)
		return (1);

	for (i = 0; i < n; i++)
	{
		if (words[i] != NULL && memcmp(s, words[i], len_word) == 0)
		{
			tmp = words[i];
			words[i] = NULL;
			match = is_a_match(s + len_word, words, nb_words - 1, len_word, n);
			words[i] = tmp;
			return (match);
		}
	}
	return (0);
}

/**
 * find_substring - function that finds all the possible substrings
 * containing a list of words, within a given string
 * @s: the string to scan
 * @words: the array of words all substringsmust be a concatenation
 * arrangement of
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store the number of elements
 * in the returned array
 * Return: return an allocated array, storing each index in s, at which
 * a substring was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, len_s, len_word, len_result = 0, *result;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	len_s = strlen(s);
	result = malloc(len_s * sizeof(int));
	len_word = strlen(words[0]);
	for (i = 0; i < len_s - (len_word * nb_words) + 1; i++)
	{
		if (is_a_match(s + i, (char **)words, nb_words, len_word, nb_words))
		{
			result[len_result++] = i;
		}
	}
	*n = len_result;
	return (result);
}
