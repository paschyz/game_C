#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
#include <string.h>
#include <time.h>

static int boardSize=7;


int main() {
    int verifLaunch=0;
    int verifQuit;
    do {
        verifLaunch = askLaunch();
        launch(verifLaunch);
        verifQuit = quit();
    }while(verifQuit==1);

}

int askLaunch(){
    int response;
    do {
        printf("How do you want to launch: \n0.text \n1.graphical\n2.cancel\n");
        //fflush(stdin);
        scanf("%d", &response);
        if(response<0||response>2)
            printf("Wrong Answer!!!\n");
    }while(response<0||response>2);
    return response;

}
void launch(int verif){
    switch (verif) {
        case 0:
            runTxt();//this line must be removed with a function call
            break;
        case 1 :
            printf("graphical version is still in dev\n quitting\n");//this line must be removed with a function call
            break;
        case 2:
            printf("quitting\n");
            break;
        default:
            printf("How did you manage to get a different response???\n");
    }
}

int quit(){
    int response=0;
    do {
        printf("Do you really want to quit?  : \n 0.yes \n 1.no\n");
        fflush(stdin);
        scanf("%d", &response);
        if(response!=0&&response!=1)
            printf("Wrong Answer!!!\n");
    }while(response!=0&&response!=1);
    return response;
}

void runTxt(){
    int responseMenu=askMenuTxt();
    if(responseMenu!=4) {
        do {
            int sizeChara = 6/*remplacer par le nombre de personnages jouables de la BD*/;
            character charaTab[sizeChara];
            loadCharaTxt(charaTab, sizeChara);
            character board[2][boardSize];
            menuResolutionTxt(responseMenu, charaTab, board[0], sizeChara);
            responseMenu=askMenuTxt();
        }while(responseMenu!=4);

    }
}
int askMenuTxt(){
    int response;
    do{
        printf("\nWelcome to \"the best unknown game\"\n What do you want to do?\n\n1)Play\n2)Character description\n3)How to play\n4)exit\n");
        fflush(stdin);
        scanf("%d",&response);
        if(response>4||response<1)
            printf("\nNah wrong answer!!! Try again\n");
    }while(response>4||response<1);
    return response;

}
void menuResolutionTxt(int response, character *charaTab,character *board,int sizeChara){
    switch (response) {
        case 1:
            startPlayingTxt(charaTab,board,sizeChara);
            break;
        case 2:
            seeCharaTxt(charaTab,sizeChara);
            break;
        case 3:
            gameDescription();
            break;
        default:
            printf("You should be quitting right now");
            break;

    }
}
void gameDescription(){
    printf("In this game, you'll have to battle again %d enemies. Don't worry, you'll have %d heros to place against the evil \nforces of computer science.\nEvery hero have a skill that boost him and nearby friend(one left,one right). \nBut beware of monsters, they can have boost too\n\n\n\n",boardSize,boardSize);
    fflush(stdin);
    getchar();
}
void loadCharaTxt(character *charaTab,int size){
    for(int i=0;i<size;i++){
        strcpy((*(charaTab+i)).name,"aaa\0"/*remplacer a\0 par le nom dans la BD*/);
        (*(charaTab+i)).maxhp/*de là*/=12+i/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).hp=(*(charaTab+i)).maxhp;
        (*(charaTab+i)).att/*de là*/=5+i/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).skill/*de là*/=(0+i)%5/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).type/*de là*/=0/*à là, remplacer par un appel de bd*/;
    }
}

void loadMonsterTxt(character *boardMonster,int sizeMonster){
    int randValue;
    printf("placing monster on board\n");
    for(int i=0;i<boardSize;i++){
        srand(time(NULL));
        randValue=rand()%(sizeMonster);
        strcpy((*(boardMonster+i)).name,"bbb\0"/*remplacer b\0 par le nom dans la BD*/);
        (*(boardMonster+i)).maxhp/*de là*/=20+(i*randValue)+randValue/*à là, remplacer par un appel de bd avec randValue*/;
        (*(boardMonster+i)).hp=(*(boardMonster+i)).hp;
        (*(boardMonster+i)).att/*de là*/=1+i/*à là, remplacer par un appel de bd avec randValue*/;
        (*(boardMonster+i)).skill/*de là*/=randValue/*à là, remplacer par un appel de bd avec randValue*/;
        (*(boardMonster+i)).type/*de là*/=0/*à là, remplacer par un appel de bd avec randValue*/;
    }
}
void firstLoadCharaBoardTxt(character *boardChara){
    for(int i=0;i<boardSize;i++){
        strcpy((*(boardChara+i)).name,"empty");
        (*(boardChara+i)).hp=-1;
        (*(boardChara+i)).maxhp=0;
        (*(boardChara+i)).att=0;
        (*(boardChara+i)).skill;
        (*(boardChara+i)).type;
    }
}
void printMultCharaTxt(character *charaTab,int sizeChara){
    int i;
    printf("List of characters:\n");
    for(i=0;i<sizeChara;i++){
        printf("%d)%s\n",i,(*(charaTab+i)).name);
    }
    printf("%d)Exit\n",i);

}
void printCharaTxt(character selectedChara){
    printf("Name: %s\nMax HP: %d\nAttack: %d\nType: ",selectedChara.name,selectedChara.maxhp,selectedChara.att);
    printTypeTxt(selectedChara.type);
    printf("Skill: ");
    printSkillTxt(selectedChara.skill);
    fflush(stdin);
    getchar();

}
void printTypeTxt(int typeNumber){
    switch(typeNumber){
        case 1:
            printf("damage\n");
            break;
        case 2:
            printf("tank\n");
            break;
        default:
            printf("normal\n");
            break;
    }
}
void printSkillTxt(int skillNumber){
    switch(skillNumber){
        case 1:
            printf("Up Att and HP by 1\n\n");
            break;
        case 2:
            printf("Up HP by 3\n\n");
            break;
        case 3:
            printf("Up Att by 2\n\n");
            break;
        case 4:
            printf("Raise HP by 10 percent\n\n");
            break;
        default:
            printf("Nothing\n\n");
            break;
    }
}
void seeCharaTxt(character *charaTab,int sizeChara){
    int numberSelect;
    int continueResponse=0;
    do {
        printMultCharaTxt(charaTab, sizeChara);
        do {
            printf("Select a character with his number\n");
            fflush(stdin);
            scanf("%d", &numberSelect);
            if (numberSelect < 0 || numberSelect > sizeChara+1)
                printf("Stop messing with numbers");
        } while (numberSelect < 0 || numberSelect > sizeChara+1);
        if(numberSelect!=sizeChara) {
            printCharaTxt(*(charaTab + numberSelect));
            printf("Do you want to continue looking at HEROES?? \n0.Yes\n1.No\n");
            fflush(stdin);
            scanf("%d", &continueResponse);
        }
        else
            continueResponse=1;
    }while(continueResponse==0);

}

void startPlayingTxt(character *charaTab,character *board,int sizeChara){
    int setupResponse;
    int sizeMonster = 6/*remplacer par le nombre de monstres de la BD*/;
    loadMonsterTxt(board+boardSize, sizeMonster);
    resetHPTxt((board+boardSize));
    firstLoadCharaBoardTxt(board);
    printAllBoardTxt(board);
    setupResponse=selectBoardSlotTxt(board,charaTab,sizeChara);
    if(setupResponse) {
        startGameTxt(board);
    }

}


int selectBoardSlotTxt(character *board,character *charaTab,int sizeChara){
    int response;
    int alreadyUsed[sizeChara];
    for (int i = 0; i < sizeChara; ++i) {
        alreadyUsed[i]=-1;
    }
    printf("This is your board. Select a hero by his number\n");
    do {
        do {
            for (int i = 0; i < boardSize; i++) {
                printf("%d)%s\n",i,(*(board+i)).name);
            }
            printf("%d)Play\n%d)Cancel\n", boardSize, boardSize + 1);
            fflush(stdin);
            scanf("%d", &response);
            if (response > boardSize+1 || response < 0)
                printf("Nah wrong answer!!! Try again\n");
        } while (response > boardSize +1|| response < 0);
        if (response != boardSize + 1 && response != boardSize) {
            assignToSlotTxt(board, charaTab, sizeChara, response,alreadyUsed);
        }
    }while (response!=boardSize&&response!=boardSize+1);
    if(response==boardSize){
        return 1;
    }
    return 0;

}
void assignToSlotTxt(character *board,character *charaTab, int sizeChara,int slot,int *alreadyUsed){
    int response;
    int responseUsed=0;
    printf("Choose the hero you want to put in slot %d\n",slot);
    do{
        for ( int i = 0; i < sizeChara; i++) {

            printf("%d)%s\n",i,(*(charaTab+i)).name);
        }
        printf("%d)Empty\n",sizeChara);
        printf("%d)Cancel\n",sizeChara+1);
        fflush(stdin);
        scanf("%d",&response);
        if(response>sizeChara+1||response<0)
            printf("Nah wrong answer!!! Try again\n");
    }while(response>sizeChara+1||response<0);
    if (response!=6&&response!=7) {

        if(alreadyUsed[response]==-1){
            *(board + slot) = *(charaTab + response);
            *(alreadyUsed + response) = slot;
        }
        else if(alreadyUsed[response]!=slot){
            printf("This hero is used on board slot %d. Do you want to remove it for this slot?:\n0)no\n1)yes\n",alreadyUsed[response]);
            fflush(stdin);
            scanf("%d",&responseUsed);
            if(responseUsed) {
                *(board + slot) = *(charaTab + response);
                removeFromSlotTxt(board, alreadyUsed[response]);
                *(alreadyUsed + response) = slot;
            }
        }

    }
    else if(response==6) {
        removeFromSlotTxt(board,slot);
    }
}
void removeFromSlotTxt(character *board,int slot){
    strcpy((*(board+slot)).name,"empty");
    (*(board+slot)).hp=-1;
    (*(board+slot)).maxhp=0;
    (*(board+slot)).att=0;
    (*(board+slot)).skill;
    (*(board+slot)).type;
}


void printAllBoardTxt(character *board){
   for (int j=0;j<2;j++) {
       for (int i = 0; i < boardSize; i++) {
           printf("%c%c\t", (*(board + i +boardSize -(boardSize*j))).name[0], (*(board + i + boardSize -(boardSize*j))).name[1]);
       }
       printf("\n");
       for (int i = 0; i < boardSize; i++) {
           printf("%d/%d\t", (*(board + i + boardSize -(boardSize*j))).hp, (*(board + i + boardSize -(boardSize*j))).maxhp);
       }
       printf("\n");
       for (int i = 0; i < boardSize; i++) {
           printf("%d\t", (*(board + i + boardSize -(boardSize*j))).att);
       }
       printf("\n\n\n\n\n\n");
   }
}
void resetHPTxt(character *board){
    for (int i=0;i<boardSize;i++){
        (*(board+i)).hp=(*(board+i)).maxhp;
    }
}

void startGameTxt(character *board){
    int totalHpAllieBoard;
    int totalHpEnemieBoard;
    doSkills(board);
    resetHPTxt(board);
    resetHPTxt(board+boardSize);
    totalHpAllieBoard=countTotalHp(board);
    totalHpEnemieBoard=countTotalHp(board+boardSize);
    printAllBoardTxt(board);
    printf("Press enter after each attack\n\n");
    while(totalHpAllieBoard>0&&totalHpEnemieBoard>0){
        allAttacksTxt(board);
        totalHpAllieBoard=countTotalHp(board);
        totalHpEnemieBoard=countTotalHp(board+boardSize);
        printAllBoardTxt(board);
        fflush(stdin);
        getchar();
    }
    winConditionTxt(board);
    resetHPTxt(board);
}
int countTotalHp(character *board){
    int totalHp=0;
    for (int i=0;i<boardSize;i++){
        if((*(board+i)).hp>0)
            totalHp+=(*(board+i)).hp;
    }
    return totalHp;
}
void allAttacksTxt(character *board) {
    int randomAtt = 0;
    for (int j = 0; j < 2; j++) {
        if (countTotalHp(board+boardSize)>0&&countTotalHp(board)>0) {
            for (int i = 0; i < boardSize; i++) {
                if((*(board+i+(boardSize*j))).hp>0) {
                    do {
                        srand(time(NULL));
                        randomAtt = rand() % boardSize;
                        if ((*(board + boardSize + randomAtt - (boardSize * j))).hp > 0) {
                            printf("%s%d attacked %s%d. He did %d damage an took %d damage\n",
                                   (*(board + i + (boardSize * j))).name,
                                   i + 1,
                                   (*(board + boardSize + randomAtt - (boardSize * j))).name,
                                   randomAtt + 1,
                                   (*(board + i + (boardSize * j))).att,
                                   (*(board + boardSize + randomAtt - (boardSize * j))).att);

                            fflush(stdin);
                            getchar();
                        }
                    } while ((*(board + boardSize + randomAtt - (boardSize * j))).hp <= 0 &&
                             countTotalHp(board + boardSize - (boardSize * j)) > 0);
                    doDamage(board, randomAtt + boardSize - (boardSize * j), i + (boardSize * j));
                    if((*(board+i+(boardSize*j))).hp<=0&&countTotalHp((board+(boardSize*j)))>0){
                        printf("%s%d is dead!!!\n",(*(board+i+(boardSize*j))).name,i+1);
                    }
                    if((*(board+randomAtt+boardSize-(boardSize*j))).hp<=0 && countTotalHp((board+randomAtt+boardSize-(boardSize*j)))>0){
                        printf("%s%d is dead!!!\n",(*(board+randomAtt+boardSize-(boardSize*j))).name,randomAtt+1);
                    }
                }
            }
        }
    }
}
void doDamage(character *board,int target,int attacker) {
    (*(board + target)).hp -= (*(board + attacker)).att;
    (*(board + attacker)).hp -= (*(board + target)).att;
}
void doSkills(character *board){
    for (int j=0;j<2;j++){
        for(int i=0;i<boardSize;i++){
            if (i==0){
                switch((*(board+i+(boardSize*j))).skill) {
                    case 1:
                        (*(board + i+(boardSize*j))).maxhp += 1;
                        (*(board + i + 1+(boardSize*j))).maxhp += 1;
                        (*(board + i+(boardSize*j))).att += 1;
                        (*(board + i + 1+(boardSize*j))).att += 1;
                        break;
                    case 2:
                        (*(board + i+(boardSize*j))).maxhp += 3;
                        (*(board + i + 1+(boardSize*j))).maxhp += 3;
                        break;
                    case 3:
                        (*(board + i+(boardSize*j))).att += 2;
                        (*(board + i + 1+(boardSize*j))).att += 2;
                        break;
                    case 4:

                        (*(board + i+(boardSize*j))).maxhp += (int) (10 * ((double) ((*(board + i - 1+(boardSize*j))).maxhp) / 100));
                        (*(board + i + 1+(boardSize*j))).maxhp += (int) (10 * ((double) ((*(board + i - 1+(boardSize*j))).maxhp) / 100));
                        break;
                }
            }
            else if(i==boardSize-1){
                switch((*(board+i+(boardSize*j))).skill) {
                    case 1:
                        (*(board + i - 1+(boardSize*j))).maxhp += 1;
                        (*(board + i+(boardSize*j))).maxhp += 1;
                        (*(board + i - 1+(boardSize*j))).att += 1;
                        (*(board + i+(boardSize*j))).att += 1;
                        break;
                    case 2:
                        (*(board + i - 1+(boardSize*j))).maxhp += 3;
                        (*(board + i+(boardSize*j))).maxhp += 3;
                        break;
                    case 3:
                        (*(board + i - 1+(boardSize*j))).att += 2;
                        (*(board + i+(boardSize*j))).att += 2;
                        break;
                    case 4:
                        (*(board + i - 1+(boardSize*j))).maxhp += (int) (10 * ((double) ((*(board + i - 1+(boardSize*j))).maxhp) / 100));
                        (*(board + i+(boardSize*j))).maxhp += (int) (10 * ((double) ((*(board + i - 1+(boardSize*j))).maxhp) / 100));
                        break;
                }
            }
            else{
                switch((*(board+i+(boardSize*j))).skill){
                    case 1:
                        (*(board+i-1+(boardSize*j))).maxhp+=1;
                        (*(board+i+(boardSize*j))).maxhp+=1;
                        (*(board+i+1+(boardSize*j))).maxhp+=1;
                        (*(board+i-1+(boardSize*j))).att+=1;
                        (*(board+i+(boardSize*j))).att+=1;
                        (*(board+i+1+(boardSize*j))).att+=1;
                        break;
                    case 2:
                        (*(board+i-1+(boardSize*j))).maxhp+=3;
                        (*(board+i+(boardSize*j))).maxhp+=3;
                        (*(board+i+1+(boardSize*j))).maxhp+=3;
                        break;
                    case 3:
                        (*(board+i-1+(boardSize*j))).att+=2;
                        (*(board+i+(boardSize*j))).att+=2;
                        (*(board+i+1+(boardSize*j))).att+=2;
                        break;
                    case 4:
                        (*(board+i-1+(boardSize*j))).maxhp+=(int)(10*((double)((*(board+i-1+(boardSize*j)+(boardSize*j))).maxhp)/100));
                        (*(board+i+(boardSize*j))).maxhp+=(int)(10*((double)((*(board+i-1+(boardSize*j))).maxhp)/100));
                        (*(board+i+1+(boardSize*j))).maxhp+=(int)(10*((double)((*(board+i-1+(boardSize*j))).maxhp)/100));
                        break;
                }
            }
        }
    }
}
void winConditionTxt(character *board){
    if(countTotalHp(board)>0 && countTotalHp(board+boardSize)<=0){
        printf("Congratulations!!! You won!!!\n If you want to do another game, enemies will be randomised\n");
    }
    else if(countTotalHp(board)<=0 && countTotalHp(board+boardSize)>0){
        printf("Sorry... You lost...\n If you want try again, enemies will be randomised\n");
    }
    else if(countTotalHp(board)<=0 && countTotalHp(board+boardSize)<=0){
        printf("Wow!!! No one wins this game!!!\n If you want to do another game, enemies will be randomised\n");
    }
    else{
        printf("Error!!! Winning condition!!!\n WTF:42\n");
    }
}