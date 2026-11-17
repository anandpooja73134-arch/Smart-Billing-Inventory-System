#include<stdio.h>
#include<stdlib.h>
struct Product
{
    int code;
    char name[50];
    float price;
    int stock;
};
int main()
{
    struct product*p;
    int n, i, choice, code, qty, found;
    float total, discount, tax, bill;
    printf("Enter number of products: ");
    scanf("%d", &n);
    p = (struct Product*)malloc(n * sizeof(struct Product));
    if (p == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("\nEnter product code: ");
        scanf("%d", &p[i].code);
        printf("Enter product name: ");
        scanf("%49s", p[i].name);
        printf("Enter price: ");
        scanf("%f", &p[i].price);
        printf("Enter stock: ");
        scanf("%d", &p[i].stock); 
    }
    do
    {
        printf("\n\n--- INVENTORY MANAGEMENT ---");
        printf("\n1. Display Products");
        printf("\n2. Search Product");
        printf("\n3. Update Product");
        printf("\n4. Generate Bill");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            for (i = 0; i < n; i++)
            {
                printf("\nCode: %d", p[i].code);
                printf("\nName: %s", p[i].name);
                printf("\nPrice: %.2f", p[i].price);
                printf("\nStock: %d\n", p[i].stock);
            }
            break;
            case 2:
            printf("Enter product code: ");
            scanf("%d", &code);
            found =0;
            for (i = 0; i < n; i++)
            {
                if (p[i].code == code)
                {
                    printf("\nProduct Found!");
                    printf("\nName: %s", p[i].name);
                    printf("\nPrice: %.2f", p[i].price);
                    printf("\nStock: %d", p[i].stock);
                    found =1;
                    break ;
                }
            }
            if (!found)
            printf("\nProduct not found!");
            break;
            case 3:
            printf("Enter product code: ");
            scanf("%d", &code);
            found =0;
            for(i=0;i<n;i++)
            {
                if (p[i].code == code)
                {
                    printf("Enter new price: ");
                    scanf("%f", &p[i].price);
                    printf("Enter new stock: ");
                    scanf("%d", &p[i].stock);
                    printf("Product updated successfully!");
                    found = 1;
                    break;
                }
            }
            if (!found)
            printf("Product not found!");
            break;
            case 4: 
            total =0;
            do
            {
                printf("\nEnter product code (0 to finish): ");
                scanf("%d", &code);
                if( code ==0)
                   break;
                found =0;
                for( i=0;i<n;i++)
                {
                    if (p[i].code == code)
                    {
                        found=1;
                        printf("Enter quantity: ");
                        scanf("%d", &qty);
                        if (qty > 0 && qty <= p[i].stock)
                        { 
                            total += p[i].price * qty;
                            p[i].stock = qty;
                            printf("Item added to bill!"); 
                        }
                        else
                        {
                            printf("Insufficient stock!");
                        }
                        break;
                    }
                }
                if (!found)
                printf("Product not found!");
            }while (code != 0);
            if (total >= 1000)
                discount = total * 0.10;
            else
              discount=0;
            tax = (total - discount) * 0.05;
            bill = total - discount + tax;
            printf("\n\n------ CUSTOMER BILL ------");
            printf("\nTotal Amount: Rs. %.2f", total);
            printf("\nDiscount: Rs. %.2f", discount);
            printf("\nTax (5%%): Rs. %.2f", tax);
            printf("\nFinal Bill: Rs. %.2f", bill);
            break;
            case 5;
                 printf("\nThank You!");
                 break;
            default:
               printf("\nInvalid choice!");
        }
    }while(choice !=5);
     free(p);
     return 0;
}

                       
