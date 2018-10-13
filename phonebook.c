/*
  CECS-130 Intro to Programming Languages
  Author: Mohamed Ali Mohamed
  Purpose: Lab Assignment 6
  Date: October 05, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold the contact of a single contact */
typedef struct phoneBook {
  char firstName[17];
  char lastName[17];
  char phoneNumber[17];

} contact;

void addFriend(contact *, int *);    // Function prototype
void deleteFriend(contact *, int *); // Function prototype
void showFriend(contact *, int *);   // Function prototype

int main() { // Main function

  int dataEntry = 0;
  int iselection = 0;
  contact *num;
  num = (contact *)malloc(sizeof(contact));
  do {
    printf(
        "\nPhone Book Application\n[1]\tAdd Friend\n[2]\tDelete "
        "Friend\n[3]\tShow Phonebook\n[0]\tExit\n\nWhat do you want to do: ");
    scanf("%d", &iselection);

    switch (iselection) {
    case 1: {
      printf("\nYou selected \"Add Friend\"\n");
      dataEntry++;
      addFriend(num, &dataEntry);
      break;
    }
    case 2: {
      printf("You selected \"Delete Friend\"\n");
      deleteFriend(num, &dataEntry);
      break;
    }
    case 3: {
      printf("\nYou selected \"Show Phonebook\"\n");
      showFriend(num, &dataEntry);
      break;
    }
    }
  } while (iselection != 0);

  printf("\nHave a great day...!\n\n");
  return 0;
} // End of main function

/* FUNCTION DEFINITIONS */
void addFriend(contact *num, int *dataEntry) {
  if (*dataEntry == 0) {

    num = (contact *)realloc(num, (sizeof(contact) * 2));
  } else if (*dataEntry > 0) {
    num = (contact *)realloc(num, (sizeof(contact) * (*dataEntry)) +
                                      sizeof(contact));
  }
  if (num != NULL) {
    printf("\nEnter First Name: ");
    scanf("%s", num[*dataEntry].firstName);
    printf("Enter Last Name: ");
    scanf("%s", num[*dataEntry].lastName);
    printf("Enter Phone Number (Format: xxx-xxxx):");
    scanf("%s", num[*dataEntry].phoneNumber);
  } else
    printf("\nSorry! Not enough memory");
}

void deleteFriend(contact *num, int *dataEntry) {
  int x;
  int delNum;
  char tempFName[15] = {'\0'};
  char tempLName[15] = {'\0'};
  char tempPhone[15] = {'\0'};
  int selection = 0;
  printf("\nFirst Name: ");
  scanf("%s", tempFName);
  printf("Last Name: ");
  scanf("%s", tempLName);
  for (x = 0; x <= *dataEntry + 1; x++) {
    if (strcmp(tempFName, num[x].firstName) == 0 &&
        strcmp(tempLName, num[x].lastName) == 0) {
      delNum = x;
      printf("\nDelete Entry Number:%d\nFirst Name:\t%s\nLast Name:\t%s\nPhone "
             "Number:\t%s",
             x, num[x].firstName, num[x].lastName, num[x].phoneNumber);
      printf("\n\n[1]\tYes\n[2]\tNo\nChoose a selection: ");
      scanf("%d", &selection);
      switch (selection) {
      case 1: {
        for (x = delNum + 1; x <= *dataEntry + 1;
             x++) // Shift all entries after deleted entry up
        {
          strcpy(num[x - 1].firstName, num[x].firstName);
          strcpy(num[x - 1].lastName, num[x].lastName);
          strcpy(num[x - 1].phoneNumber, num[x].phoneNumber);
        }
        *dataEntry = *dataEntry - 1;

        if (*dataEntry != 0) {
          num = (contact *)realloc(num, (sizeof(contact) * (*dataEntry + 1)));

        } else if (dataEntry > 0) {
          num = (contact *)realloc(num, 2 * (sizeof(contact)));
        }
        break;
      }
      case 2: {
        printf("\nDeletion Aborted...!\n");
        break;
      }
      }
      break;

    } else if (x > *dataEntry) {
      printf("No matching entry found!");
    }
  }
}
void showFriend(contact *num, int *dataEntry) {
  int x;
  for (x = 1; x <= *dataEntry; x++) {
    printf("\nEntry Number: %d\nFirst Name:\t%s\nLast Name:\t%s\nPhone "
           "Number:\t%s\n",
           x, num[x].firstName, num[x].lastName, num[x].phoneNumber);
  }
}