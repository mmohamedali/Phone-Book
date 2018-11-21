/*
  Author: Mohamed Ali Mohamed
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Structure to hold the contact of a single contact */
typedef struct phoneBook {
  char firstName[17];
  char lastName[17];
  char phoneNumber[17];

} contact;

void addFriend(contact *, int *);      // Function prototype
void deleteFriend(contact *, int *);   // Function prototype
void showFriend(contact *, int *);     // Function prototype
void findFriend(contact *, int *);     // Function prototype
void randomCalling(contact *, int *);  // Function prototype
void sortingAlpha(contact *, int *);   // Function prototype
void clearPhoneBook(contact *, int *); // Function prototype
void savePhoneBook(contact *, int *);  // Function prototype
contact *loadBook(contact *, int *);   // Function prototype

int main() { // Main function

  int dataEntry = 0;
  int iselection = 0;
  contact *num;
  num = (contact *)malloc(sizeof(contact));
  do {
    printf("\nPhone Book Application\n[1]\tAdd Friend\n[2]\tDelete "
           "Friend\n[3]\tShow Phonebook\n[4]\tSearch Phonebook\n[5]\tPhonebook "
           "Sorting\n[6]\tRandom Calling\n[7]\tClear "
           "Phonebook\n[8]\tSave Phoneook\n[9]\tLoad "
           "Phonebook\n[0]\tExit\n\nWhat do you want to "
           "do: ");
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
    case 4: {
      printf("\nYou selected \"Search Phonebook\"\n");
      findFriend(num, &dataEntry);
      break;
    }
    case 5: {
      printf("\nYou selected \"Sort Phonebook Alphabetically\"\n");
      sortingAlpha(num, &dataEntry);
      break;
    }
    case 6: {
      printf("\nYou selected \"Random Calling\"\n");
      randomCalling(num, &dataEntry);
      break;
    }
    case 7: {
      printf("\nYou selected \"Clear Phonebook\"\n");
      clearPhoneBook(num, &dataEntry);
      break;
    }
    case 8: {
      printf("\nYou selected \"Save Phonebook\"\n");
      savePhoneBook(num, &dataEntry);
      break;
    }
    case 9: {
      printf("\nYou selected \"Save Phonebook\"\n");
      num = loadBook(num, &dataEntry);
      break;
    }
    default: {
      printf("\nINVALID OPTION!\n");
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
void findFriend(contact *phoneBook, int *dataEntry) {
  int num;
  int delNum;
  char tempFName[15] = {'\0'};
  char tempLName[15] = {'\0'};

  printf("\nFirst Name: ");
  scanf("%s", tempFName);
  printf("Last Name: ");
  scanf("%s", tempLName);
  for (num = 0; num <= *dataEntry + 1; num++) {
    if (strcmp(tempFName, phoneBook[num].firstName) == 0 &&
        strcmp(tempLName, phoneBook[num].lastName) == 0) {
      delNum = num;
      printf("\nEntry Number:%d\nFirst Name:\t%s\nLast Name:\t%s\nPhone "
             "Number:\t%s\n",
             num, phoneBook[num].firstName, phoneBook[num].lastName,
             phoneBook[num].phoneNumber);
      break;

    } else if (num > *dataEntry) {
      printf("No matching entry found!");
    }
  }
}
void randomCalling(contact *phoneBook, int *dataEntry) {
  srand(time(NULL));
  int num;
  num = (rand() % (*dataEntry)) + 1;
  printf(
      "\nEntry Number:%d\nFirst Name:\t%s\nLast Name:\t%s\nPhone Number:\t%s\n",
      num, phoneBook[num].firstName, phoneBook[num].lastName,
      phoneBook[num].phoneNumber);
}

void sortingAlpha(contact *phoneBook, int *dataEntry) {
  contact *sortingAlpha;
  sortingAlpha = (contact *)malloc(sizeof(contact) * (*dataEntry + 1) * 2);
  int x, y, z;
  contact temp;
  int byfirstname = 0;
  int comparison;
  int selection;

  printf("\n[1]\tBy First name\n[2]\tBy Last name\nChoose a selection: ");
  scanf("%d", &selection);
  switch (selection) {
  case 1:
    byfirstname = 1;
    break;
  case 2:
    byfirstname = 0;
    break;
  default:
    printf("Try again\n");
    return;
  }
  for (x = 1; x < *dataEntry; x++) {
    for (y = x + 1; y <= *dataEntry; y++) {
      if (byfirstname) {
        comparison = strcmp(phoneBook[x].firstName, phoneBook[y].firstName) > 0;
      } else {
        comparison = strcmp(phoneBook[x].lastName, phoneBook[y].lastName) > 0;
      }
      if (comparison) {
        strcpy(temp.firstName, phoneBook[x].firstName);
        strcpy(temp.lastName, phoneBook[x].lastName);
        strcpy(temp.phoneNumber, phoneBook[x].phoneNumber);

        strcpy(phoneBook[x].firstName, phoneBook[y].firstName);
        strcpy(phoneBook[x].lastName, phoneBook[y].lastName);
        strcpy(phoneBook[x].phoneNumber, phoneBook[y].phoneNumber);

        strcpy(phoneBook[y].firstName, temp.firstName);
        strcpy(phoneBook[y].lastName, temp.lastName);
        strcpy(phoneBook[y].phoneNumber, temp.phoneNumber);
      }
    }
  }
  for (x = 1; x <= *dataEntry; x++) {
    printf("\nFirst Name: %s\nLast Name: %s\nPhone Number: %s\n\n",
           phoneBook[x].firstName, phoneBook[x].lastName,
           phoneBook[x].phoneNumber);
  }
}

void clearPhoneBook(contact *phoneBook, int *dataEntry) {
  *dataEntry = 0;
  phoneBook =
      (contact *)realloc(phoneBook, (sizeof(dataEntry) * (*dataEntry + 1)));
  printf("\nPHONEBOOK CLEARED\n");
}

void savePhoneBook(contact *phoneBook, int *dataEntry) {
  int selection;
  FILE *phoneFile;
  int num;
  char location[100] = {'\0'};

  do {
    printf("\nChoose Location to Save File:\n[1]\tDefault Location\n[2]\tUser "
           "Specified Location\n[0]\tCancel Save\nChoose an option: ");
    scanf("%d", &selection);
    switch (selection) {
    case 1: {
      phoneFile = fopen("phonebook.txt", "w");
      if (phoneFile == NULL) {
        printf(
            "\nERROR: FILE CAN NOT BE OPENED!\n Returning to Phone Book Menu.");
        break;
      }
      for (num = 1; num <= *dataEntry; num++) {
        fprintf(phoneFile, "%s\t%s\t%s\n", phoneBook[num].firstName,
                phoneBook[num].lastName, phoneBook[num].phoneNumber);
      }
      fclose(phoneFile);
      printf("\nFile Saved in Default Directory!");
      break;
    }
    case 2: {
      printf("\nPlease type file name to save and don't use spaces!\nWARNING: "
             "BE CAREFUL NOT TO TYPE THE "
             "WHOLE PATH OF YOUR FILE.\nEnter your file name Example "
             "(mycontacts.txt): ");
      scanf("%s", location);

      phoneFile = fopen(location, "w");
      if (phoneFile == NULL) {
        printf(
            "\nERROR: FILE CAN NOT BE OPENED!\n Returning to Phone Book Menu.");
        break;
      }
      for (num = 1; num <= *dataEntry; num++) {
        fprintf(phoneFile, "%s\t%s\t%s\n", phoneBook[num].firstName,
                phoneBook[num].lastName, phoneBook[num].phoneNumber);
      }
      fclose(phoneFile);
      printf("\nFile Saved in %s!\n", location);
      break;
    }
    case 0: {
      printf("\nSave Cancelled!\n");
      break;
    }
    default: {
      printf("\nINVALID OPTION");
      selection = -1;
    }
    }
  } while (selection == -1);
}
contact *loadBook(contact *phoneBook, int *dataEntry) {
  FILE *phoneFile;
  int selection = -1;
  int num = 1;

  char location[100] = {'\0'};
  do {
    printf("\nChoose Location to Load File:\n[1]\tDefault Location\n[2]\tUser "
           "Specified Location\n[0]\tCancel Load\nChoose an option: ");
    scanf("%d", &selection);
    if (selection == 1 || selection == 2) {
      *dataEntry = 0;
      phoneBook = (contact *)realloc(phoneBook, (sizeof(contact)));
    }

    switch (selection) {
    case 1: {
      phoneFile = fopen("phonebook.txt", "r");
      if (phoneFile == NULL) {
        printf(
            "\nERROR: FILE CAN NOT BE OPENED!\n Returning to Phone Book Menu.");
        break;
      }

      while (!feof(phoneFile)) {

        *dataEntry = (*dataEntry) + 1;
        phoneBook = realloc(phoneBook, (sizeof(contact) * (*dataEntry + 1)));
        if (phoneBook == NULL) {
          printf("\nFAILURE");
        }
        fscanf(phoneFile, "%s\t%s\t%s\n", phoneBook[(*dataEntry)].firstName,
               phoneBook[(*dataEntry)].lastName,
               phoneBook[(*dataEntry)].phoneNumber);
      }
      fclose(phoneFile);
      printf("\nPhone Book Loaded from Default Directory!\n");
      break;
    }
    case 2: {
      printf("\nPlease type file name to load from and don't use "
             "spaces!\nWARNING: BE "
             "CAREFUL NOT TO TYPE THE "
             "WHOLE PATH OF YOUR FILE.\nEnter your file name Example "
             "(loadmycontacts.txt): ");
      scanf("%s", location);

      phoneFile = fopen(location, "r");
      if (phoneFile == NULL) {
        printf("\nERROR: FILE CAN NOT BE OPENED!\nReturning to Phone Book "
               "Menu.\n");
        break;
      }
      while (!feof(phoneFile)) {

        *dataEntry = (*dataEntry) + 1;
        phoneBook = realloc(phoneBook, (sizeof(contact) * (*dataEntry + 1)));
        if (phoneBook == NULL) {
          printf("\nFAILURE");
        }
        fscanf(phoneFile, "%s\t%s\t%s\n", phoneBook[(*dataEntry)].firstName,
               phoneBook[(*dataEntry)].lastName,
               phoneBook[(*dataEntry)].phoneNumber);
      }
      fclose(phoneFile);
      printf("\nFile Loaded from %s!\n", location);
      break;
    }
    case 0: {
      printf("\nLoad Cancelled!\n");
      break;
    }
    default: {
      printf("\nINVALID OPTION\n");
      selection = -1;
    }
    }
  } while (selection == -1);

  return phoneBook;
}
