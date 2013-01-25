#include <stdio.h>
int masu[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int player = 0;
int win = 0;

void print_masu(void);
int check_win(void);

int main(void) {
	int i = 0;
	int put = 0;
	int yoko = 0;
	int tate = 0;
	printf("\n[○☓ゲーム]\n");
	for( i = 0; i<9 && win==0; i++) {
		print_masu();
		player = i%2 + 1;
		do{
			printf("あなたのシンボルマーク:[ %c ]\n"
				   "プレイヤー%dのターン / マス番号を入力:",(player ==2)?'X':'0', player);
			while(1){
				if (scanf("%d", &put) != 1){
					scanf("%*s");
					if(feof(stdin)){
					}
					continue;
				}
				if (put<10 || put>0){
					break;
				}
			}
			yoko = (put-1)/3;
			tate = (put-1)%3;
			if(masu[yoko][tate]>'9')
				printf("%c正しく入力してください\n",masu[yoko][tate]);
		}
		while(put<0 || put>9 || masu[yoko][tate]>'9');
		masu[yoko][tate] = (player == 2) ? 'X' : 'O';
		check_win();
	}
	printf("\n ▽リザルト▽\n");
	print_masu();
	if(win == 0)
		printf("\a両者引き分け\n");
	else
		printf("\a\a勝者:プレイヤー %d\n", win);
	return(0);
}
void print_masu(void){
	printf("┏━┳━┳━┓\n");
	printf("┃%2c┃%2c┃%2c┃\n",masu[0][0],masu[0][1],masu[0][2]);
	printf("┣━╋━╋━┫\n");
	printf("┃%2c┃%2c┃%2c┃\n",masu[1][0],masu[1][1],masu[1][2]);
	printf("┣━╋━╋━┫\n");
	printf("┃%2c┃%2c┃%2c┃\n",masu[2][0],masu[2][1],masu[2][2]);
	printf("┗━┻━┻━┛\n\n");
}
int check_win(void){
	int line = 0;
	if((masu[0][0] == masu[1][1] && masu[0][0] == masu[2][2]) ||
		(masu[0][2] == masu[1][1] && masu[0][2] == masu[2][0]))
		win = player;
	else
		for(line = 0; line <= 2; line ++)
			if((masu[line][0] == masu[line][1] && masu[line][0] == masu[line][2])||
			  (masu[0][line] == masu[1][line] && masu[0][line] == masu[2][line]))
			  win = player;
	return(win);
}