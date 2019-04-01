#include <stdio.h>
#include <stdlib.h>

typedef struct boxNode{
	int name;
	struct boxNode * link;
}boxNode;

typedef struct lineNode{
	struct boxNode * root;
	int size;
}lineNode;

int GoToRight(lineNode * pileArray, int lineSize,  int level, int place){

	int startPos = lineSize - 1;
	int count = -1;
	level++;
	
	if(place == lineSize - 1){
		return pileArray[place].size - level; 
	}
	if(level == 1){
		startPos = lineSize - 1;
	}
	if(pileArray[place + 1].size < level || pileArray[place - 1].size < level){
		startPos = place;
	}else{
		for(int i = place + 1; i <= lineSize - 1 ; i++){
			if(pileArray[i].size + 1 == level){
				startPos = i;
				break;
			}
		}
	}

	for(int i = startPos ; i >= place; i--){
		count = count + (pileArray[i].size - (level - 1));
	}

	return count;

}

int GoToLeft(lineNode * pileArray, int lineSize,  int level, int place){

	int startPos = 0;
	int count = -1;
	level++;
	if(place == 0){
		return pileArray[place].size - level; 
	}
	if(level == 1){
		startPos = 0;
	}
	if(pileArray[place + 1].size < level || pileArray[place - 1].size < level){
		startPos = place;
	}else{
		for(int i = place - 1; i >= 0 ; i--){
			if(pileArray[i].size + 1 == level){
				startPos = i;
				break;
			}
		}
	}

	for(int i = startPos ; i <= place; i++){
		count = count + (pileArray[i].size - (level - 1));
	}
	return count;

}

int findBox(lineNode * pileArray, int lineSize,  int level, int place){
	int fromRight = GoToRight(pileArray, lineSize, level, place);
	int fromLeft = GoToLeft(pileArray, lineSize, level, place);
	
	if(fromRight > fromLeft){
		return fromLeft;
	}else{
		return fromRight;
	}

}


int main(void){

	int boxIndex = 1;
	int ncaixas = 1;
	int npilhas = 1;
	int level;
	int place;

	lineNode * pileArray;
	boxNode * nodeArray;

	while(1){

		scanf("%d %d", &ncaixas, &npilhas);

		if(!ncaixas && !npilhas){
			break;
		}

		pileArray = (lineNode *)malloc(sizeof(lineNode) * npilhas);
		nodeArray = (boxNode *)malloc(sizeof(boxNode) * ncaixas);

		int nc = 0;

		for(int i = 0; i < npilhas ; i++){

			int pilesize;
			scanf("%d", &pilesize);
			
			pileArray[i].size = pilesize;

			for(int j = 0; j < pilesize ; j++){
				int name;
				scanf("%d", &name);
				if(name == boxIndex){
					level = j;
					place = i;
				}
				// push(pileArray[i], &nodeArray[nc], name);
				nodeArray[nc].name = name;

				if(pileArray[i].root == NULL){
					pileArray[i].root = &nodeArray[nc];
				}else{
					nodeArray[nc].link = pileArray[i].root;
					pileArray[i].root = &nodeArray[nc];
				}

				nc++;
			}
		}
		
		int removedBoxes = findBox(pileArray, npilhas, level, place);
		printf("%d\n", removedBoxes);
		
	}


}

