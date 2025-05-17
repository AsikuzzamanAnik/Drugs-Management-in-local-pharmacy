#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_CART_ITEMS 10
#define TAX_RATE 0.08

#define MAX_INPUT_LENGTH 100
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void register_admin() {
    FILE *fp = fopen("admins.txt", "a");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    char username[MAX_INPUT_LENGTH];
    char password[MAX_INPUT_LENGTH];
    char name[MAX_INPUT_LENGTH];
    char email[MAX_INPUT_LENGTH];
    char phone[MAX_INPUT_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter phone number: ");
    scanf("%s", phone);

    fprintf(fp, "%s %s %s %s %s\n", username, password, name, email, phone);
    fclose(fp);

    printf("Registration successful.\n");
}

int login_admin() {
    char username[MAX_INPUT_LENGTH];
    char password[MAX_INPUT_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("admins.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 0; // Indicate login failure
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        char usernameFromFile[MAX_INPUT_LENGTH];
        char passwordFromFile[MAX_INPUT_LENGTH];
        char *token = strtok(line, " ");
        if (token != NULL) {
            strncpy(usernameFromFile, token, sizeof(usernameFromFile) - 1);
            token = strtok(NULL, " ");
            if (token != NULL) {
                strncpy(passwordFromFile, token, sizeof(passwordFromFile) - 1);
                // Check if username and password match
                if (strcmp(username, usernameFromFile) == 0 && strcmp(password, passwordFromFile) == 0) {
                    fclose(fp);
                    return 1; // Indicate login success
                }
            }
        }
    }

    fclose(fp);
    return 0; // Indicate login failure
}


void register_customer() {
    FILE *fp = fopen("customers.txt", "a");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    char username[MAX_INPUT_LENGTH];
    char password[MAX_INPUT_LENGTH];
    char name[MAX_INPUT_LENGTH];
    char email[MAX_INPUT_LENGTH];
    char phone[MAX_INPUT_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter phone number: ");
    scanf("%s", phone);

    fprintf(fp, "%s %s %s %s %s\n", username, password, name, email, phone);
    fclose(fp);

    printf("Registration successful.\n");
}

int login_customer() {
    char username[MAX_INPUT_LENGTH];
    char password[MAX_INPUT_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 0; // Indicate login failure
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        char usernameFromFile[MAX_INPUT_LENGTH];
        char passwordFromFile[MAX_INPUT_LENGTH];
        char *token = strtok(line, " ");
        if (token != NULL) {
            strncpy(usernameFromFile, token, sizeof(usernameFromFile) - 1);
            token = strtok(NULL, " ");
            if (token != NULL) {
                strncpy(passwordFromFile, token, sizeof(passwordFromFile) - 1);
                // Check if username and password match
                if (strcmp(username, usernameFromFile) == 0 && strcmp(password, passwordFromFile) == 0) {
                    fclose(fp);
                    return 1; // Indicate login success
                }
            }
        }
    }

    fclose(fp);
    return 0; // Indicate login failure
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Medicine {
    char name[100];
    float price;
    int quantity;
};

struct Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

typedef struct {
    char name[100];
    float price;
    int quantity;
} CartItem;

CartItem cart[MAX_CART_ITEMS];
int num_cart_items = 0;

void add_medicine();
void delete_medicine();
void update_medicine();
void check_inventory();
void search_medicine();
void browse_medicines();
void add_to_cart();
void calculate_total();
void finalize_purchase();
void process_payment();

void save_medicines_to_file();
void load_medicines_from_file();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   printf("        power by T. K. group\n \n");
    int panel_choice;
    printf("\n Panel Selection\n");
    printf("  1. Admin Panel\n");
    printf("  2. Customer Panel\n");
    printf("  Enter your choice: ");
    scanf("%d", &panel_choice);

    switch (panel_choice) {
        case 1:
            {
                int admin_choice;
                printf("Admin Panel\n");
                printf("\n1. Register\n");
                printf("\n2. Login\n");
                printf("\nEnter your choice: ");
                scanf("%d", &admin_choice);

                switch (admin_choice) {
                    case 1:
                        register_admin();
                        break;
                    case 2:
                        if (login_admin()) {
                            printf("Login successful.\n");
                        } else {
                            printf("Invalid username or password.\n");
                        exit(0);
                       }
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            }
        case 2:
            {
                int customer_choice;
                printf("Customer Panel\n");
                printf("\n1. Register\n");
                printf("\n2. Login\n");
                printf("\nEnter your choice: ");
                scanf("%d", &customer_choice);

                switch (customer_choice) {
                    case 1:
                        register_customer();
                        break;
                    case 2:
                        if (login_customer()) {
                            printf("Login successful.\n");
                        } else {
                            printf("Invalid username or password.\n");

                            exit(0);
                        }
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            }
        default:
            printf("Invalid choice.\n");
    }





    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    load_medicines_from_file();

    int choice;
    printf("Welcome to the Pharmacy Management System\n");
    printf("1. Admin Panel\n");
    printf("2. Customer Panel\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Admin Panel
            do {
                printf(" \n\n\n=== Admin Panel ===\n\n\n");
                printf("1. Add Medicine\n");
                printf("2. Delete Medicine\n");
                printf("3. Update Medicine\n");
                printf("4. Check Inventory\n");
                printf("5. Search Medicine\n");
                printf("6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        add_medicine();
                        break;
                    case 2:
                        delete_medicine();
                        break;
                    case 3:
                        update_medicine();
                        break;
                    case 4:
                        check_inventory();
                        break;
                    case 5:
                        search_medicine();
                        break;
                    case 6:
                        printf("Exiting Admin Panel...\n");
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            } while (choice != 6);
            break;
        case 2:
            // Customer Panel
            do {
                printf("\n\n\n=== Customer Panel ===\n\n\n");
                printf("1. Browse Medicines\n");
                printf("2. Search Medicine\n");
                printf("3. Add to Cart\n");
                printf("4. Calculate Total\n");
                printf("5. Finalize Purchase\n");
                printf("6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        browse_medicines();
                        break;
                    case 2:
                        search_medicine();
                        break;
                    case 3:
                        add_to_cart();
                        break;
                    case 4:
                        calculate_total();
                        break;
                    case 5:
                        finalize_purchase();
                        break;
                    case 6:
                        printf("Exiting Customer Panel...\n");
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            } while (choice != 6);
            break;
        default:
            printf("Invalid choice.\n");
    }

    save_medicines_to_file();

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_medicine() {
    struct Medicine newMedicine;
    printf("Enter medicine details:\n");
    printf("Name: ");
    scanf("%s", newMedicine.name);
    printf("Price: ");
    scanf("%f", &newMedicine.price);
    printf("Quantity: ");
    scanf("%d", &newMedicine.quantity);

    // Check if the medicine already exists
    for (int i = 0; i < num_medicines; ++i) {
        if (strcmp(medicines[i].name, newMedicine.name) == 0) {
            // Medicine found, update its quantity and price
            medicines[i].quantity += newMedicine.quantity;
            medicines[i].price = newMedicine.price;
            printf("Medicine updated successfully.\n");
            return;
        }
    }

    // If medicine does not exist and there's space, add it
    if (num_medicines < MAX_MEDICINES) {
        medicines[num_medicines++] = newMedicine;
        printf("Medicine added successfully.\n");
    } else {
        printf("Maximum limit reached. Cannot add more medicines.\n");
    }
}

void delete_medicine() {
    char name[100];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            num_medicines--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Medicine deleted successfully.\n");
    } else {
        printf("Error: Medicine not found.\n");
    }
}

void update_medicine() {
    char name[100];
    printf("Enter medicine name to update: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter new medicine price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new medicine quantity: ");
            scanf("%d", &medicines[i].quantity);
           found = 1;
            break;
        }
    }

    if (found) {
        printf("Medicine updated successfully.\n");
    } else {
        printf("Error: Medicine not found.\n");
    }
}

void check_inventory() {
    printf("=== Inventory ===\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("Name: %s, Price: %.2f, Quantity: %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void search_medicine() {
    char name[100];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Name: %s, Price: %.2f, Quantity: %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Medicine not found.\n");
    }
}

void browse_medicines() {
    printf("=== Medicines List ===\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("Name: %s, Price: %.2f, Quantity: %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void add_to_cart() {
    if (num_cart_items >= MAX_CART_ITEMS) {
        printf("Error: Maximum number of cart items reached.\n");
        return;
    }

    char name[100];
    printf("Enter medicine name to add to cart: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            if (medicines[i].quantity <= 0) {
                printf("Error: Medicine out of stock.\n");
                return;
            }

            strcpy(cart[num_cart_items].name, name);
            cart[num_cart_items].price = medicines[i].price;
            cart[num_cart_items].quantity = 1;
            num_cart_items++;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Medicine not found.\n");
    }
}

void calculate_total() {
    float total = 0;
    for (int i = 0; i < num_cart_items; i++) {
        total += cart[i].price * cart[i].quantity;
    }

    float tax = total * TAX_RATE;
    float grand_total = total + tax;

    printf("Total: $%.2f\n", total);
    printf("Tax: $%.2f\n", tax);
    printf("Grand Total: $%.2f\n", grand_total);
}

void finalize_purchase() {
    if (num_cart_items == 0) {
        printf("Error: No items in cart.\n");
        return;
    }

    for (int i = 0; i < num_cart_items; i++) {
        for (int j = 0; j < num_medicines; j++) {
            if (strcmp(cart[i].name, medicines[j].name) == 0) {
                medicines[j].quantity -= cart[i].quantity;
                break;
            }
        }
    }

    printf("Purchase finalized successfully.\n");
    num_cart_items = 0;
}

void process_payment() {
    if (num_cart_items == 0) {
        printf("Error: No items in cart.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < num_cart_items; i++) {
        total += cart[i].price * cart[i].quantity;
    }

    printf("Payment processed successfully. Total amount: $%.2f\n", total);

    num_cart_items = 0;
}

void save_medicines_to_file() {
    FILE *fp = fopen("medicines.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < num_medicines; i++) {
        fprintf(fp, "%s %.2f %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }

    fclose(fp);
}

void load_medicines_from_file() {
    FILE *fp = fopen("medicines.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    while (fscanf(fp, "%s %f %d", medicines[num_medicines].name, &medicines[num_medicines].price, &medicines[num_medicines].quantity) != EOF) {
        num_medicines++;
    }

    fclose(fp);
}

