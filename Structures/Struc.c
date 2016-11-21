#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct sT
{
        char name[11];
        int damage;
}skillType;

typedef struct aT
{
        char name[11];
        int addPtsT;
        int addPts;
}armorType;

typedef struct hT
{
        char name[21];
        skillType skills[3];
        int age;
        int level;
        int hp;
        int mp;
        armorType armor[3];
}superHeroType;
//Prototypes
void skillmastery();
void attribute();
void armory();

int main(){
    superHeroType hero;
    printf("{{{{{Hero Factory}}}}}\nWelcome to the Hero Fac!!\n\n");
    printf("Enter Name: "); gets(hero.name);
    printf("Age: "); scanf("%d",&hero.age);
    printf("Level: "); scanf("%d",&hero.level);
    printf("HP: "); scanf("%d",&hero.hp);
    printf("MP: "); scanf("%d",&hero.mp);
    //print info
    system("cls");
    printf("Hero Created...\n\n");
    printf("Hero's name: "); puts(hero.name);
    printf("Hero's age: %d\n",hero.age); 
    printf("Level: %d\n",hero.level); 
    printf("HP: %d\n",hero.hp); 
    printf("MP: %d",hero.mp);
    getch();
    return 0;
}
