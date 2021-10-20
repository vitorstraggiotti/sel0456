#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <string.h>

typedef struct
{
	char data[4096];
	int key;
} item_t;


gint compare_item(gconstpointer a, gconstpointer b)
{
	if(((item_t *)a)->key < ((item_t *)b)->key)
		return -1;
	else if(((item_t *)a)->key > ((item_t *)b)->key)
		return 1;
	return 0;
}

void print_item(gpointer data, gpointer user_data)
{
	int *i = (int *) user_data;
	printf("No. %d -> key=%d: '%s'\n", *i + 1, ((item_t *)data)->key, ((item_t *)data)->data);
	(*i)++;
}

//void sort(item_t * a, int n);

item_t * item_init(char * data, int key)
{
	item_t * self = malloc(sizeof(item_t));
	self->key = key;
	self->data = strdup(data);
	return self;
}

void item_destroy(gpointer _self, gpointer unused_data)
{
	item_t * self = (item_t *) _self;
	free(self->data);
	free(self);
}

int main(void)
{
	GList *list;
	
	list = g_list_append(NULL, item_init("bill", 3));
	list = g_list_insert_sorted(list, item_init("neil", 4), compare_item);
	list = g_list_insert_sorted(list, item_init("john", 3), compare_item);
	list = g_list_insert_sorted(list, item_init("sara", 7), compare_item);
	list = g_list_insert_sorted(list, item_init("rick", 5), compare_item);
	list = g_list_insert_sorted(list, item_init("alex", 1), compare_item);
	
//	printf("The first item is '%s'\n", ((item_t *)g_list_first(list)->data)->data);
//	list = g_list_next(list);
//	printf("The second item is '%s'\n", ((item_t *)list->data)->data);
  
	list = g_list_first(list);
	
	int i = 0;
	g_list_foreach(list, print_item, &i);
	
	/* Limpando toda a lista e suas estruturas */
	list = g_list_first(list);
	g_list_foreach(list, item_destroy, NULL);
	g_list_free(list);
  
//	sort(array,5);
//	for(int i = 0; i < 5; i++)
//		printf("array[%d] = {%s, %d}\n", i, array[i].data, array[i].key);

	return 0;
}
//==============================================================================
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


