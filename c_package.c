#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int id;
    char name[100];
    int quantity;
    int price, payment_type;
};

void add_item(struct Item *items)
{
    printf("Enter the item ID: ");
    scanf("%d", &items->id);
    printf("Enter the item name: ");
    scanf("%s", items->name);
    printf("Enter the quantity: ");
    scanf("%d", &items->quantity);
    printf("Enter the item price: ");
    scanf("%d", &items->price);
    printf("Item added successfully!!!\n\n");
}

void delete_item(struct Item *items, int n)
{
    int id, i;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++)
    {
        if (items[i].id == id)
        {
            items[i].quantity = 0;
            printf("Item deleted successfully!!!\n");
            return;
        }
    }
    printf("Item not found!!\n");
}

void display_items(struct Item *items, int n)
{
    int i;
    printf("\n----------ITEMS-----------\n");
    printf("Id \t Name \tQuantity \n\n");
    for (i = 0; i < n; i++)
    {
        if (items[i].quantity > 0)
        {
            printf("%d \t %s \t %d\n", items[i].id, items[i].name, items[i].quantity);
        }
    }
}

float revenue_calc(struct Item *items, int n)
{
    float totalRevenue = 0.0;
    for (int i = 0; i < n; i++)
    {
        totalRevenue += (items[i].quantity * items[i].price);
    }
    printf("Total amount=%.2f\n", totalRevenue);
    return totalRevenue;
}

void payment_calc(float totalRevenue, struct Item *items, int n)
{
    int payment_type, total;
    printf("Payment Details\n");
    printf("Select payment method: \n");
    printf("1. Credit card\n");
    printf("2. Debit Card / ATM card\n");
    printf("3. Net Banking\n");
    printf("4. By cash\n");
    printf("Your choice: ");
    scanf("%d", &payment_type);
    switch (payment_type)
    {
        case 1:
            printf("Enter credit card details:\n");
            total = revenue_calc(items, n);
            printf("Payment Successful!!!\n");
            printf("Thank you!!! Visit Again!!!\n");
            break;
        case 2:
            printf("Enter debit card /ATM card details:\n");
            total = revenue_calc(items, n);
            printf("Payment Successful!!!\n");
            printf("Thank you!!! Visit Again!!!\n");
            break;
        case 3:
            printf("Enter net banking details:\n");
            total = revenue_calc(items, n);
            printf("Payment Successful!!!\n");
            printf("Thank you!!! Visit Again!!!\n");
            break;
        case 4:
            total = revenue_calc(items, n);
            printf("Thank you!!! Visit Again!!!\n");
            break;
        default:
            printf("Invalid payment type selected. Please try again.\n");
            break;
    }
}

int main()
{
    int n, option, i;
    int totalRevenue;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter item id details:\n");
        add_item(&items[i]);
    }

    while (1)
    {
        printf("\n1. Add item");
        printf("\n2. Delete item");
        printf("\n3. Display items");
        printf("\n4. Total amount");
        printf("\n5. Payment method");
        printf("\n6. Exit");
        printf("\n");
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                add_item(&items[n]);
                n++;
                break;
            case 2:
                delete_item(items, n);
                break;
            case 3:
                display_items(items, n);
                break;
            case 4:
                totalRevenue = revenue_calc(items, n);
                break;
            case 5:
                payment_calc(totalRevenue, items, n);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid option");
                break;
        }
    }
    return 0;
}
