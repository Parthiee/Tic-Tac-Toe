#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int board[3][3];
int i,j;
void showboard() {
     for(i=0;i<3;++i) {
        for(j=0;j<3;++j) {
            printf("%d ",board[i][j]);
        }
    printf("\n");
     }
// printf("\n--------------------------------\n");
}

int sys_x() {
    int x;
    x=rand()%3;
    return x;
}
int sys_y() {
    int y;
    y=rand()%3;
    return y;
}
int user_x() {
    int x;
    printf("\nEnter \"x\" coordinate: ");
    scanf("%d",&x);
    return x;

}
int user_y() {
    int y;
    printf("\nEnter \"y\" coordinate: ");
    scanf("%d",&y);
    return y;

}
bool check_winner() {
        //Checking winner for system
        if (board[0][0]==2 && board[1][0]==2 && board[2][0]==2) {
         printf("COMPUTER WINS\n");
         return true; }
        else if (board[0][1]==2 && board[1][1]==2 && board[2][1]==2){
         printf("COMPUTER WINS\n");
         return true; }
        else if (board[0][2]==2 && board[1][2]==2 && board[2][2]==2){
         printf("COMPUTER WINS\n");
         return true; }
        else if (board[0][0]==2 && board[1][1]==2 && board[2][2]==2) {
         printf("COMPUTER WINS\n");
         return true; }
        else if (board[0][2]==2 && board[1][1]==2 && board[2][0]==2) {
         printf("COMPUTER WINS\n");
         return true; }
         else if (board[0][0]==2 && board[0][1]==2 && board[0][2]==2){
         printf("COMPUTER WINS\n");
         return true; }
         else if (board[1][0]==2 && board[1][1]==2 && board[1][2]==2){
         printf("COMPUTER WINS\n");
         return true; }
         else if (board[2][0]==2 && board[2][1]==2 && board[2][2]==2){
         printf("COMPUTER WINS\n");
         return true; }
        //Checking winner for user
        else if (board[0][0]==1 && board[1][0]==1 && board[2][0]==1) {
         printf("USER WINS\n");
         return true; }
        else if (board[0][1]==1 && board[1][1]==1 && board[2][1]==1) {
         printf("USER WINS\n");
         return true; }
        else if (board[0][2]==1 && board[1][2]==1 && board[2][2]==1) {
         printf("USER WINS\n");
         return true; }
        else if (board[0][0]==1 && board[1][1]==1 && board[2][2]==1) {
         printf("USER WINS\n");
         return true; }
        else if (board[0][2]==1 && board[1][1]==1 && board[2][0]==1) {
         printf("USER WINS\n");
         return true; }
         else if (board[0][0]==1 && board[0][1]==1 && board[0][2]==1){
         printf("USER WINS\n\n");
         return true; }
         else if (board[1][0]==1 && board[1][1]==1 && board[1][2]==1){
         printf("USER WINS\n\n");
         return true; }
         else if (board[2][0]==1 && board[2][1]==1 && board[2][2]==1){
         printf("USER WINS\n\n");
         return true; }      
}

int main() {
    int i,x,y;
    while(true) {
        showboard();
        printf("\nUser's turn\n ");
        x=user_x();
        y=user_y();
        //Avoiding overlapping of values for user
        if(board[y][x]!=0) {
            while(1) {
                printf("Can't place here, try different coordinates\n");
                x=user_x();
                y=user_y();
                if(board[y][x]==0) break;
            }
        }
        board[y][x]=1;
        if(check_winner()){
            showboard();
            break;
        }
        else showboard();

        printf("\nComputer's turn\n");
        x=sys_x();
        y=sys_y();
        //Avoiding overlapping of values for computer
        if(board[y][x]!=0) {
            while(1) {
               x=sys_x();
               y=sys_y(); 
               if(board[y][x]==0) break;
            }
        }
        board[y][x]=2;
        if(check_winner()){
            showboard();
            break;
        }
    }
printf("\nGame Over!\n");
return 0;
}