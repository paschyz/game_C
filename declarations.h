//
//

#ifndef PROJET_2A_CLION_DECLARATIONS_H
#define PROJET_2A_CLION_DECLARATIONS_H
void launch(int verif);
int askLaunch();
int quit();
struct character{
    char name[32];
    int hp;
    int att;
    int skill;
    int type;

};
typedef struct character character;
void runTxt();
void loadCharaTxt(character * charaTab,int size);
void loadMonsterTxt(character *monsterBoard,int size);
#endif //PROJET_2A_CLION_DECLARATIONS_H


