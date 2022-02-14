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
int askMenuTxt();
void menuResolutionTxt(int response, character *charaTab,character *board, int sizeChara);
void startPlayingTxt(character *charaTab,character *board,int sizeChara);
void printBoard(character *board);
void printCharaTxt();
void printMultCharaTxt(character *charaTab,int sizeChara);
void seeCharaTxt(character *charaTab,int sizeChara);
void printTypeTxt(int typeNumber);
void printSkillTxt(int skillNumber);


#endif //PROJET_2A_CLION_DECLARATIONS_H


