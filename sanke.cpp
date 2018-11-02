//--------------------------------------------------------------------LIBRARY INCLUDATIONS
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
//--------------------------------------------------------------------DEFINES
#define SNAKELEN 20
#define SNAKENULPOS 333
//--------------------------------------------------------------------NAMESPACE DECLARATION
using namespace std;
//--------------------------------------------------------------------VARIABLE DECLEARATION
int snkpos[SNAKELEN][2];
int applex,appley;

int snkhrzntlspace=0,snkvrtclspace=0;
//--------------------------------------------------------------CHANGE POSITTION OF SNAKE FUNCTIONS
int snakelen();
void updatesnk();
void right(){

  snkhrzntlspace++;
  updatesnk();
  snkpos[0][0]=snkpos[0][0]+1;

}
void left(){
  snkhrzntlspace--;

  if(snkhrzntlspace<0) snkhrzntlspace=0;
  updatesnk();
  snkpos[0][0]=snkpos[0][0]-1;
  if(snkpos[0][0]<0) snkpos[0][0]=0;
}
void down(){

  snkvrtclspace++;
  updatesnk();
  snkpos[0][1]=snkpos[0][1]+1;

}
void up(){
  snkvrtclspace--;
  if(snkvrtclspace<0) snkvrtclspace=0;
  updatesnk();
  snkpos[0][1]=snkpos[0][1]-1;
  if(snkpos[0][1]<0) snkpos[0][1]=0;
}
//--------------------------------------------------------------------
void updatesnk(){
  for(int i=snakelen();i>0;i--){
    for(int y=0;y<2;y++){
      snkpos[i][y]=snkpos[i-1][y];
    }
  }
}

void shiftarray(){
  for(int x=snakelen();x>=0;x--){
    for (int y=0;y<2;y++){
      snkpos[x+1][y]=snkpos[x][y];
    }
  }
}


int snakelen(){
  for (int x=SNAKELEN-1;x>=0;x--){
    if(snkpos[x][1]!=SNAKENULPOS){
      //cout<<x;
       return x;
     }
  }
}
int minline(int n){
  int min=333;
  for(int i=0;i<SNAKELEN;i++){
    if(min>snkpos[i][0] && snkpos[i][1]==n) min=snkpos[i][0];
  }
  return min;
}
int nline(int n){
  int x=0;
  for(int i=0;i<SNAKELEN;i++){
    if(snkpos[i][1]==n) x++;
  }
  return x;
}
bool haveline(int n){
  for(int i=0;i<=snakelen();i++){
    if(snkpos[i][1]==n) return true;

  }
   return false;
}
void printline(int a,int n){
  for(int i=0;i<a;i++)
    cout<<" ";
  for(int i=0;i<n;i++)
    cout<<"#";
}
void update(){
  //clrscr();
  system ("CLS");
  int l=0;
  for(int x=0;x<SNAKELEN;x++){

      if(haveline(x)&&appley==x){
        if(minline(x)<applex){
          printline(minline(x),nline(x));
          for(int i=0;i<applex-nline(x)-minline(x);i++)
            cout<<" ";
          for(int i=0;i<1;i++)
            cout<<"@";
        }
        if(minline(x)>applex){

          for(int i=0;i<applex;i++)
            cout<<" ";
          for(int i=0;i<1;i++)
            cout<<"@";
          printline(minline(x)-applex,nline(x));
        }
      }
      else if(haveline(x)){
        if(x==appley) l=1;
        else l=0;
        printline(minline(x),nline(x));
        l=0;
    }
      else if(appley==x){
        for(int i=0;i<applex;i++)
          cout<<" ";
        for(int i=0;i<1;i++)
          cout<<"@";
      }
    cout<<endl;
  }
  cout<<snkpos[2][0];
  /*for(int i=0;i<snkpos[0][0];i++){
    cout<<" ";
  }
  cout<<"#";*/

}
void apple(){
  if(snkpos[0][0]==applex && snkpos[0][1]==appley){
  applex=(rand()%107)+4;
  appley=(rand()%20)+1;
  snkpos[snakelen()+1][0]=0;
  snkpos[snakelen()+1][1]=0;
  updatesnk();
}

}


int main(){

  snkhrzntlspace=0;
  snkvrtclspace=0;
  srand(time(NULL));

  for(int x=0;x<SNAKELEN;x++){
    for (int y=0;y<2;y++){
      snkpos[x][y]=SNAKENULPOS;
    }
  }
  snkpos[0][0]=0;
  snkpos[0][1]=0;
  snkpos[1][0]=1;
  snkpos[1][1]=1;
  applex=(rand()%120)+4;
  appley=(rand()%20)+1;
  cout<<endl;
  cout<<string(40,' ');
  cout<<"WELCOME TO SNAKE (BETA VERSION)  ;)";
  cout<<endl;
  cout<<"INTRODUCTION:";
  cout<<endl;
  cout<<"\t\tYOU ARE THE SNAKE AND YOU SHOULD EAT APPLES IN PLAY GROUND YOU SHOUL MOVE WITH THE WSDA KEYS";
  cout<<"MANUAL:";
  cout<<endl;
  cout<<"\t\tW BUTTUN=SNAKE GOING UP \t S BUTTUN=SNAKE GOING DOWN  ";
  cout<<endl;
  cout<<"\t\tD BUTTUN=SNAKE GOING RIGHT \t A BUTTUN=SNAKE GOING LEFT  ";
  cout<<endl;
  cout<<"IF YOU ARE READY PRESS Y AND THEN PRESS D OR IF YOU ARE NOT PRESS N ";
  cout<<endl;
  cout<<"WRITTEN BY MR.FULSH ;)";
  switch(getch()){
    case 'y':
      system("CLS");
      break;
    case 'n':
      exit(1);
      break;
    default:
      exit(1);
  }
  while(1){
  switch(getch()){
    case 'w':
      up();
      break;
    case 's':
      down();
      break;
    case 'd':
      right();
      break;
    case 'a':
      left();
      break;
  }
  apple();

  update();
}
}
