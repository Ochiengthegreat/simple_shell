#include "shell.h"

/**
 * listt_length - This determines length of linked list
 * @h: The pointer to first node
 * Return: size of list
 */
size_t listt_length(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        h = h->next;
        i++;
    }
    return (i);
}

/**
 * listt_of_strings - This returns an array of strings of the list->str
 * @head: This is the pointer to first node
 * Return: This is an array of strings
 */
char **listt_of_strings(list_t *head)
{
    list_t *node = head;
    size_t i = listt_length(head), j;
    char **strs;
    char *str;

    if (!head || !i)
        return (NULL);
    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return (NULL);
    for (i = 0; node; node = node->next, i++)
    {
        str = malloc(_strlen(node->str) + 1);
        if (!str)
        {
            for (j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return (NULL);
        }

        str = _strcpy(str, node->str);
        strs[i] = str;
    }
    strs[i] = NULL;
    return (strs);
}

/**
 * printt_lists - This prints all elements of a list_t linked list
 * @h: This is the pointer to first node
 * Return: size of list
 */
size_t printt_lists(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts(convert_number_c(h->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }
    return (i);
}

/**
 * startt_node_is - This returns node whose string starts with prefix
 * @node: This is the pointer to list head
 * @prefix: This is the string to match
 * @c: This is the next character after prefix to match
 * Return: The match node or null
 */
list_t *startt_node_is(list_t *node, char *prefix, char c)
{
    char *p = NULL;

    while (node)
    {
        p = starts_with(node->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return (node);
        node = node->next;
    }
    return (NULL);
}

/**
 * gett_node_index - This gets the index of a node
 * @head: This is the pointer to list head
 * @node: This is the pointer to the node
 * Return: index of node or -1
 */
ssize_t gett_node_index(list_t *head, list_t *node)
{
    size_t i = 0;

    while (head)
    {
        if (head == node)
            return (i);
        head = head->next;
        i++;
    }
    return (-1);
}
