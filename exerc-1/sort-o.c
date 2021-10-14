#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char *data;
  int key;
} item_t;

/*
item_t array[] = {
  {"bill", 3},
  {"neil", 4},
  {"john", 2},
  {"rick", 5},
  {"alex", 1},
};
*/

void sort(item_t * a, int n);

// Create array object with given size
item_t *create_array(int size);

void destroy_array(item_t *array, int size);

// Add a new string/key pair on first free place
void add_element(item_t *array, int size, int key, const char *string);

int main(void)
{
	item_t *array;
	
	array = create_array(5);
	add_element(array, 5, 3, "bill");
	add_element(array, 5, 4, "neil");
	add_element(array, 5, 2, "john");
	add_element(array, 5, 5, "rick");
	add_element(array, 5, 1, "alex");
	add_element(array, 5, 6, "vitor");
	
	
	sort(array,5);
	
	for(int i = 0; i < 5; i++)
		printf("array[%d] = {%s, %d}\n", i, array[i].data, array[i].key);
	
	destroy_array(array, 5);
	
	return 0;
}

/******************************************************************************/
void sort(item_t * a, int n) 
{
  int i = 0, j = 0;
  int s = 1;

  for(; i < n && s != 0; i++) 
  {
    s = 0;
    for(j = 0; j < n-1; j++)
    {// Estava faltanto abertura de chave deste for 
      if(a[j].key > a[j+1].key) 
      {
        item_t t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        s++;
      }
//    n--;  // A subtração em n diminui o numero de comparações feitas de forma
			// que não garante o correto ordenamento. Realizando um numero de 
			// comparações inferior ao minimo necesssário para este agorítimo.
    }// Estava faltando fechamento de chave deste for
  }
}
//------------------------------------------------------------------------------
item_t *create_array(int size)
{
	item_t *array;
	
	array = malloc(size * sizeof(item_t));
	if(array == NULL)
	{
		printf("Could not allocate memory for array!");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < size; i++)
	{
		array[i].data = NULL;
		array[i].key = 0;
	}
	
	return array;
}
//------------------------------------------------------------------------------
void destroy_array(item_t *array, int size)
{
	for(int i = 0; i < size; i++)
	{
		free(array[i].data);
	}
	
	free(array);
}
//------------------------------------------------------------------------------
void add_element(item_t *array, int size, int key, const char *string)
{
	int freePosition = 0;
	int stringSize = 0;
	
	for(;; freePosition++)
	{
		if(freePosition >= size)
		{
			printf("Could not add new element. Full!\n");
			return;
		}
	
		if(array[freePosition].data == NULL)
			break;
	}
		
	for(;; stringSize++)
	{
		if(string[stringSize] == '\0')
			break;
	}
	
	array[freePosition].data = malloc((stringSize + 1) * sizeof(char));
	
	for(int i = 0; i < stringSize + 1; i++)
	{
		array[freePosition].data[i] = string[i];
	}
	array[freePosition].key = key;
}









