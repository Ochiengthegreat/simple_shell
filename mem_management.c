#include "shell.h"

/**
**_realloc_ -  Reallocates a memory block using malloc and free
*@ptr: Pointer pointing to previous block
*@old_size: Previous size of the pointer
*@new_size: New size of the pointer
*Return: Void pointer rellocated memory
*/
void *_realloc_(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}
/**
* _memcpy - Copy Byte from source to destination
* @dest: Destination pointer
* @src: Source pointer
* @n: Size (how much you will copy)
*Return: Void pointer
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
* fill_array - Fill an Array by constant Byte
* @ptr:Void pointer
* @lx: Int
* @len:Length Int
*Return: Void pointer
*/
void *fill_array(void *ptr, int lx, unsigned int len)
{
	char *px = ptr;

	unsigned int i = 0;

	while (i < len)
	{
		*px = lx;
		px++;
		i++;
	}
	return (ptr);
}
