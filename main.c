#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"




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
    int sizeChara=1/*remplacer par le nombre de personnages jouables de la BD*/;
    character charaTab[sizeChara];
    loadCharaTxt(charaTab,sizeChara);
    character board[2][5];
    int sizeMonster=1/*remplacer par le nombre de monstres*/;
    loadMonsterTxt(board[1],sizeMonster);



}

void loadCharaTxt(character *charaTab,int size){
    printf("loading character\n");
    for(int i=0;i<size;i++){
        (*(charaTab+i)).name/*de là*/[0]="a"/*à là, remplacer par un appel de bd*/;
        (*(charaTab+i)).hp/*de là*/=0/*à là, remplacer par un appel de bd*/;
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
        (*(boardMonster+randValue)).name/*de là*/[0]="a"/*à là, remplacer par un appel de bd*/;
        (*(boardMonster+randValue)).hp/*de là*/=0/*à là, remplacer par un appel de bd*/;
        (*(boardMonster+randValue)).att/*de là*/=0/*à là, remplacer par un appel de bd*/;
        (*(boardMonster+randValue)).skill/*de là*/=0/*à là, remplacer par un appel de bd*/;
        (*(boardMonster+randValue)).type/*de là*/=0/*à là, remplacer par un appel de bd*/;
    }
}