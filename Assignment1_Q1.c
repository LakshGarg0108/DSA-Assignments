#include <stdio.h>

int main() {
    int arr[10], size = 0, choice;
    int i, pos, value, found;

    while (1) {
        printf("MENU\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements: ");
            scanf("%d", &size);
            printf("Enter %d elements:\n", size);
            for (i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }
        } 
        else if (choice == 2) {
            if (size == 0) {
                printf("Array is empty.\n");
            } else {
                printf("Array elements are:\n");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        } 
        else if (choice == 3) {
            if (size >= 10) {
                printf("Array is full. Cannot insert.\n");
                continue;
            }
            printf("Enter position to insert (0 to %d): ", size);
            scanf("%d", &pos);
            if (pos < 0 || pos > size) {
                printf("Invalid position.\n");
            } else {
                printf("Enter value to insert: ");
                scanf("%d", &value);
                for (i = size; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                size++;
                printf("Value inserted.\n");
            }
        } 
        else if (choice == 4) {
            if (size == 0) {
                printf("Array is empty. Nothing to delete.\n");
                continue;
            }
            printf("Enter position to delete (0 to %d): ", size - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= size) {
                printf("Invalid position.\n");
            } else {
                for (i = pos; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                printf("Element deleted.\n");
            }
        } 
        else if (choice == 5) {
            if (size == 0) {
                printf("Array is empty.\n");
                continue;
            }
            printf("Enter value to search: ");
            scanf("%d", &value);
            found = 0;
            for (i = 0; i < size; i++) {
                if (arr[i] == value) {
                    printf("Value found at position %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Value not found in array.\n");
            }
        } 
        else if (choice == 6) {
            printf("Exiting program.\n");
            break;
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

