#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Creating the struct
struct Student
{
    char name[50];
    char gender;
    struct Student *next;
};

struct Student *current_linked_list;
struct Student *after;
 struct Student *before;
struct Student *insertNode(char *name,
                           char gender, struct Student *list)
{
    struct Student *s;
    // Allocate memory for node (malloc operation)
    s = malloc(sizeof(struct Student));
    if (s == NULL)
    {
        printf("Memory allocation failed.");
        return list;
    }
    strcpy(s->name, name);
    s->gender = gender;
    s->next = list; // list is the start of the list
    list = s;

    return list;
}

//function that decides which of the two elements sent to the function comes first
int isBefore(struct Student *a, struct Student *b) 
{
    if (a->gender == 'F' && b->gender == 'M')
    {
        return 1;
    }
    else if (a->gender == 'M' && b->gender == 'F')
    {
        return 0;
    }
    else if (a->gender == 'F')
    {
        return strcmp(a->name, b->name) < 0; // assign the name of a to b
    }
    else
    {
        return strcmp(b->name, a->name) < 0; // assign the name of b to a
    }
}

// Sorting function
struct Student *sortList(struct Student *list)
{
    int sorted = 0;
    
	while (!sorted) 
    {
       sorted = 1;
       current_linked_list = list; //We are assigning a list to the globally defined current linked list
        while (current_linked_list->next != NULL) //continue linked list next until it is different from NULL
        {
            if (isBefore(current_linked_list->next, current_linked_list))  //Here it calculates which of the element in the linked list and the next element comes first or after alphabetically
            {
               
               
    after = current_linked_list->next; //We are assigning a current linked list to the globally defined after linked list
    if (list == current_linked_list) // if two linked lists are equal
    {
        current_linked_list->next = after->next;
        after->next = current_linked_list;

       list= after;
    }
    else
    {
       before = list;//We are assigning a before to the list
        while (before->next != current_linked_list) // until next of before is different from current
        {
            before = before->next; //go to next before
        }

        if (after->next != NULL)
        {
            current_linked_list->next = after->next; //If the next of after is different from null,continuo
        }
        else
        {

            current_linked_list->next = NULL;
        }
        after->next = current_linked_list;
        before->next = after;
         
    }
               
                sorted = 0;
            }
            if (current_linked_list->next == NULL) // Exit the loop if current in next is equal to null
            {
                break;
            }
            current_linked_list = current_linked_list->next; // we equated current to the next element
        }
    }

    return list; 
}

//REFERENCES
//1-https://www.codesdope.com/c-structure/
//2-https://www.geeksforgeeks.org/strcmp-in-c-cpp/


// Printing function
void printList(struct Student *list)
{
    while (list != NULL)
    {
        printf("%s\t%c\n", list->name, list->gender);
        list = list->next;
    }
}
int main()
{
    // Creating an Initial Node Variable
    struct Student *head = NULL;
    // Call to functions
    head = insertNode("Cenk", 'M', head);
    head = insertNode("Ceyda", 'F', head);
    head = insertNode("Esra", 'F', head);
    head = insertNode("Okan", 'M', head);
    head = insertNode("Tugce", 'F', head);
    head = insertNode("Mehmet", 'M', head);
    head = insertNode("Ayse", 'F', head);
    head = insertNode("Merve", 'F', head);
    head = insertNode("Sedat", 'M', head);
    head = insertNode("Ahmet", 'M', head);
    // call to sorting function
    head = sortList(head);
    printList(head);
}

//191180072
//Hilmi uður polat
