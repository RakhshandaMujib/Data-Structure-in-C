#include <stdio.h>
#include <stdlib.h>

typedef struct table
{
    int size; //Total size of the table.
    int occupied_space; //Size of the occupied space.
    int *content; //Pointer to the array.
}table;

void insert_item(table *tab, int x);
void delete_item(table *tab);
void print_content(table *tab);
void print_table_stats(table *tab);

int main()
{
    table *dynamic_table = (table*)malloc(sizeof(table));

    dynamic_table->size = 0;
    dynamic_table->occupied_space = 0;

    insert_item(dynamic_table, 1);
      print_content(dynamic_table);
    insert_item(dynamic_table, 2);
      print_content(dynamic_table);
    insert_item(dynamic_table, 3);
      print_content(dynamic_table);

    delete_item(dynamic_table);
      print_content(dynamic_table);
    delete_item(dynamic_table);
      print_content(dynamic_table);

    insert_item(dynamic_table, 4);
      print_content(dynamic_table);
    insert_item(dynamic_table, 5);
      print_content(dynamic_table);
    insert_item(dynamic_table, 6);
      print_content(dynamic_table);
    insert_item(dynamic_table, 7);
      print_content(dynamic_table);

    delete_item(dynamic_table);
      print_content(dynamic_table);
    delete_item(dynamic_table);
      print_content(dynamic_table);
    delete_item(dynamic_table);
      print_content(dynamic_table);
    delete_item(dynamic_table);
      print_content(dynamic_table);
    delete_item(dynamic_table);
      print_content(dynamic_table);

    print_table_stats(dynamic_table);

    free(dynamic_table);

    return 0;
}

void insert_item(table *tab, int x)
/**
* Brief: Inserts an item in the dynamic table. Takes
*        care of the expansion of table along with the
*        insertion operation.
*
* Argument(s):
*   tab - Pointer to the dynamic table.
*   x - New item to be inserted in the dynamic table.
*/
{
    int *temp, i;

    printf("\nInserting %d...\n", x);

    if(!tab->size) //If the table has not been initialized.
    {
        tab->size = 1; //Make its size 1.
        //Allocate unit space for the first fresh insertion.
        tab->content = (int *)calloc(tab->size, sizeof(int));
    }

    //Expansion condition:
    if(tab->occupied_space == tab->size)
    {
        tab->size *= 2; //Double the size of the table.
        //Allocate a temporary space for future insertion.
        temp = (int *)calloc(tab->size, sizeof(int));

        if(!temp) //If space is unavailable...
        {
            printf("ERROR: Out of memory!\n");
            return;
        }

        //Copy the old contents of the table:
        for(i = 0; i < tab->occupied_space; i++)
            temp[i] = tab->content[i];

        free(tab->content); //Free the old table.
        tab->content = temp; //Reinitialize the table pointer.
    }

    tab->content[tab->occupied_space] = x; //Insert the new item.
    tab->occupied_space += 1; //Update the size of occupied space.
}

void delete_item(table *tab)
/**
* Brief: Delete an item from the dynamic table. Takes
*        care of the contraction of table along with the
*        deletion operation.
*
* Argument(s):
*   tab - Pointer to the dynamic table.
*/
{
    float alpha;
    int *temp, i;


    if(!tab->occupied_space) //Underflow condition.
    {
        printf("Table is empty! Insert to delete items. \n");
        return;
    }

    //Initialize the load factor:
    alpha = (tab->occupied_space - 1) / (float)tab->size;

    printf("\nDeleting %d...\n", tab->content[tab->occupied_space - 1]);

    //Contraction condition:
    if(alpha <= 0.25)
    {
        //Allocate half the size of the old table:
        tab->size /= 2;
        temp = (int*)calloc(tab->size, sizeof(int));

        if(!temp) //If space is unavailable...
        {
            printf("ERROR: Out of memory!\n");
            return;
        }

        //Copy the old contents of the table:
        for(i = 0; i < tab->occupied_space; i++)
            temp[i] = tab->content[i];

        free(tab->content); //Free the old table.
        tab->content = temp; //Reinitialize the table pointer.
    }

    tab->content[tab->occupied_space - 1] = 0; //Delete the last item.
    tab->occupied_space -= 1; //Update the size of occupied space.
}

void print_content(table *tab)
/**
* Brief: Utility function. Prints the contents of the
*        dynamic table (the vacant/ unoccupied spaces are
*        represented by 0).
*
* Argument(s):
*   tab - Pointer to the dynamic table.
*/
{
    int i;

    printf("Current contents of the table:\n");

    for(i = 0; i < tab->size; i++)
        printf("\t%d", tab->content[i]);

    printf("\n");
}

void print_table_stats(table *tab)
/**
* Brief: Utility function. Prints the statistics of the
*        dynamic table namely, the total size of the table
*        (including the unoccupied available spaces), occu
*        -pied spaces, and alpha (ratio between the occupi
*        -ed size and total size.
*
* Argument(s):
*   tab - Pointer to the dynamic table.
*/
{
    printf("\n\n*** - - - - - TABLE STATS - - - - - ***\n");
    printf("\tTable size = %d\n", tab->size);
    printf("\tOccupied space = %d\n", tab->occupied_space);
    printf("\tAlpha = %d/%d\n\n", tab->occupied_space, tab->size);
}