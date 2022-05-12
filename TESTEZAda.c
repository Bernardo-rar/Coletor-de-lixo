#include <stdio.h>
#include <stdlib.h>
#include "coletlixo.h"

int main(){
	
	int *i=(int*)malloc2(sizeof(int));
	int *j=(int*)malloc2(sizeof(int));
	
 	dump();
	atribui(i,j);
	dump();
}
