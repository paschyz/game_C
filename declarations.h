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
    int maxhp;

};
typedef struct character character;

void runTxt();
void loadCharaTxt(character * charaTab,int size);
void loadMonsterTxt(character *monsterBoard,int size);
int askMenuTxt();
void menuResolutionTxt(int response, character *charaTab,character *board, int sizeChara);
void resetHPTxt(character *board);
void startPlayingTxt(character *charaTab,character *board,int sizeChara);
void printAllBoardTxt(character *board);
void printCharaTxt(character selectedChara);
void printMultCharaTxt(character *charaTab,int sizeChara);
void seeCharaTxt(character *charaTab,int sizeChara);
void printTypeTxt(int typeNumber);
void printSkillTxt(int skillNumber);
int selectBoardSlotTxt(character *board,character *charaTab,int sizeChara);
void assignToSlotTxt(character *board,character *charaTab,int sizeChara,int slot,int *alreadyUsed);
void removeFromSlotTxt(character *board,int slot);
void firstLoadCharaBoardTxt(character *boardChara);
void startGameTxt(character *board);
int countTotalHp(character *board);
void allAttacksTxt(character *board);
void doDamage(character *board,int target,int attacker);
void doSkills(character *board);
void gameDescription();
void winConditionTxt(character *board);

#endif //PROJET_2A_CLION_DECLARATIONS_H


