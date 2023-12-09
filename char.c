#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Enum to represent character classes (warrior, rogue, ranger, mage)
enum CharacterClass {
    WARRIOR,
    ROGUE,
    RANGER,
    MAGE
    // Add more classes as needed
};

enum AttackType {
    STANDARD,
    RANGED
    // Add more if needed, perhaps damage types (fire, ice, nature, poison, etc.)
};

struct Character {
    char name[50];
    int health;
    int attack;
    int defense;
    int level;
    int experience;
    enum CharacterClass characterClass;
    enum AttackType attackType;
};

// Function to display character information
void displayInfo(struct Character *character) {
    printf("Name: %s\n", character->name);
    printf("Class: %d\n", character->characterClass);
    printf("Attack Type: %d\n", character->attackType);
    printf("Health: %d\n", character->health);
    printf("Attack: %d\n", character->attack);
    printf("Defense: %d\n", character->defense);
    printf("Level: %d\n", character->level);
    printf("Experience: %d\n\n", character->experience);
}

struct Character createCharacter() {
    struct Character character;

    printf("Enter character name: ");
    scanf("%s", character.name);

    // Randomize character classes
    int classChoice = rand() % 4; // Number obviously needs to be changed if more classes are added
    switch (classChoice) {
    case 0:
        character.characterClass = WARRIOR;
        character.attackType = STANDARD;
        break;
    case 1:
        character.characterClass = ROGUE;
        character.attackType = STANDARD;
        break;
    case 2:
        character.characterClass = RANGER;
        character.attackType = RANGED;
        break;
    case 3:
        character.characterClass = MAGE;
        character.attackType = RANGED;
        break;
    // Add more classes as needed
    default:
        break;
    }

    srand((unsigned)time(NULL)); // Seed the random number generator

    character.health = rand() % 11 + 30; // Random number between 30 and 40
    character.defense = rand() % 8 + 8;  // Random number between 8 and 15

    // Set attack based on class
    if (character.characterClass == RANGER || character.characterClass == MAGE) {
        character.attack = rand() % 5 + 8; // Random number between 8 and 12
    } else {
        // Standard attack for warriors and rogues
        character.attack = rand() % 7 + 12; // Random number between 12 and 18
    }

    return character;
}

int askUserIfLiked(const char *characterName) {
    char response;
    printf("Do you like the character %s? (y/n): ", characterName);
    scanf(" %c", &response);
    return (response == 'y' || response == 'Y');
}

void displayCharacterDetails(const struct Character *character) {
    printf("Name: %s\n", character->name);
    printf("Health: %d\n", character->health);
    printf("Attack: %d\n", character->attack);
    printf("Defense: %d\n\n", character->defense);

    // Display the character's class
    const char *className;
    switch (character->characterClass) {
    case WARRIOR:
        className = "Warrior";
        break;
    case ROGUE:
        className = "Rogue";
        break;
    case RANGER:
        className = "Ranger";
        break;
    case MAGE:
        className = "Mage";
        break;
    }

    printf("Class: %s\n\n", className);
}

int main() {
    struct Character characters[3];

    for (int i = 0; i < 3; i++) {
        struct Character newCharacter;
        int userLikesCharacter = 0;

        while (!userLikesCharacter) {
            newCharacter = createCharacter();

            // Create a function to display character details
            displayCharacterDetails(&newCharacter);

            userLikesCharacter = askUserIfLiked(newCharacter.name);
        }

        characters[i] = newCharacter;
    }

    printf("All characters created:\n");
    for (int i = 0; i < 3; i++) {
        printf("Character %d:\n", i + 1);
        printf("Name: %s\n", characters[i].name);
        printf("Health: %d\n", characters[i].health);
        printf("Attack: %d\n", characters[i].attack);
        printf("Defense: %d\n\n", characters[i].defense);
    }

    return 0;
}
