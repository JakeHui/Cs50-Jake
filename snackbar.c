/**
Welcome to Beach Burger Shack!
Choose from the following menu to order. Press enter when done.

Burger: $9.50
Vegan Burger: $11.00
Hot Dog: $5.00
Cheese Dog: $7.00
Fries: $5.00
Cheese Fries: $6.00
Cold Pressed Juice: $7.00
Cold Brew: $3.00
Water: $2.00
Soda: $2.00

Enter a food item: cold brew
Enter a food item: hot dog
Enter a food item:

Your total cost is: $8.00
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define NUM_ITEMS 5 // Number of menu items
typedef struct // Menu itmes have item name and price
{
    string item;
    float price;
}
menu_item;

menu_item menu[NUM_ITEMS]; // Array of menu items
void add_items(void); // Add items to menu
float get_cost(string item); // Calculate total cost
int main(void)
{
    add_items(); //add items to menu

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price); //print every element in the menu
    }
    printf("\n");

    float total = 0;
    while (true) // repeat until nothing is entered
    {
        string item = get_string("Enter a food item: "); // prompt user for item
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        total += get_cost(item); // find total
    }

    printf("Your total cost is: $%.2f\n", total);
}
void add_items(void) // Add at least the first for items to the menu array
{
    menu[0].item = "burger";
    menu[0].price = 9.50; //burger
    menu[1].item = "vegan burger";
    menu[1].price = 11.00; //vegan burger
    menu[2].item = "hot dog";
    menu[2].price = 5.00; //hot dog
    menu[3].item = "cheese dog";
    menu[3].price = 7.00; //cheese dog
    menu[4].item = "fries";
    menu[4].price = 5.00; //fries
    return;
}

float get_cost(string item) // Search through the menu array to find an item's cost
{
    float cost = 0;
    for(int a = 0; item[a]; a++)
    {
        item[a] = tolower(item[a]); // for uppercase and lowercase characters convert all into lower
    }

    for (int i = 0; i < NUM_ITEMS; i++) // iterate through all items in the array and check each item
    {
        if (strcmp(item, menu[i].item) == 0) // if item names are the same
        {
            return menu[i].price; // return the price of that item
        }
    }
    printf("Item not found\n"); // if nothing is returned prior say item not found
    return 0;
}
