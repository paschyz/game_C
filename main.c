#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
#include <string.h>




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
    if(responseMenu!=3) {
        int sizeChara = 6/*remplacer par le nombre de personnages jouables de la BD*/;
        character charaTab[sizeChara];
        loadCharaTxt(charaTab, sizeChara);
        character board[2][5];
        board[1][0]=charaTab[0];
        menuResolutionTxt(responseMenu,charaTab,board[0],sizeChara);

    }
}
int askMenuTxt(){
    int response;
    do{
        printf("Welcome to \"the best unknown game\"\n What do you want to do?\n1)Play\n2)Character description\n3)exit\n");
        fflush(stdin);
        scanf("%d",&response);
        if(response>3||response<1)
            printf("Nah wrong answer!!! Try again\n");
    }while(response>3||response<1);
    return response;

}
void menuResolutionTxt(int response, character *charaTab,character *board,int sizeChara){
    switch (response) {
        case 1:
            break;
        case 2:
            seeCharaTxt(charaTab,sizeChara);
            break;
        default:
            printf("You should be quitting right now");
            break;

    }
}
void loadCharaTxt(character *charaTab,int size){
    printf("loading character\n");
    for(int i=0;i<size;i++){
        strcpy((*(charaTab+i)).name,"a\0"/*remplacer a\0 par le nom dans la BD*/);
        (*(charaTab+i)).hp/*de là*/=12/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).att/*de là*/=0/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).skill/*de là*/=0/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).type/*de là*/=0/*à là, remplacer par un appel de bd*/;
    }
}

void loadMonsterTxt(character *boardMonster,int sizeMonster){
    int randValue;
    printf("placing monster on board\n");
    for(int i=0;i<5;i++){
        randValue=rand()%(sizeMonster);
        strcpy((*(boardMonster+i)).name,"b\0"/*remplacer b\0 par le nom dans la BD*/);
        (*(boardMonster+i)).hp/*de là*/=0/*à là, remplacer par un appel de bd avec randValue*/;
        (*(boardMonster+i)).att/*de là*/=0/*à là, remplacer par un appel de bd avec randValue*/;
        (*(boardMonster+i)).skill/*de là*/=0/*à là, remplacer par un appel de bd avec randValue*/;
        (*(boardMonster+i)).type/*de là*/=0/*à là, remplacer par un appel de bd avec randValue*/;
    }
}

void startPlayingTxt(character *charaTab,character *board,int sizeChara){
    int sizeMonster = 6/*remplacer par le nombre de monstres de la BD*/;
    loadMonsterTxt(board+5, sizeMonster);
    printMultCharaTxt(charaTab,sizeChara);

}

void printMultCharaTxt(character *charaTab,int sizeChara){
    printf("List of characters:\n");
    for(int i=0;i<sizeChara;i++){
        printf("%d)%s\n",i,(*(charaTab+i)).name);
    }

}
void printCharaTxt(character selectedChara){
    printf("Name: %s\nHP: %d\nAttack: %d\nType: ",selectedChara.name,selectedChara.hp,selectedChara.att);
    printTypeTxt(selectedChara.type);
    printf("Skill: ");
    printSkillTxt(selectedChara.skill);

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
            printf("Do damage to all enemies\n\n");
            break;
        case 2:
            printf("Heal all allies instead of attacking\n\n");
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
            if (numberSelect < 0 || numberSelect > sizeChara)
                printf("Stop messing with numbers");
        } while (numberSelect < 0 || numberSelect > sizeChara);
        printCharaTxt(*(charaTab + numberSelect));
        printf("Do you want to continue looking at HEROES?? \n0.Yes\n1.No\n");
        fflush(stdin);
        scanf("%d",&continueResponse);
    }while(continueResponse==0);

}