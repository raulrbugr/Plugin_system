/*
 *  Created on: 24 de may. de 2017
 *      Author: Raul Ruiz Bueno
 *
 *
 * Project that contains Plugin system using shared libraries with dlfcn.h
 */

#include <stdlib.h>
#include <stdio.h>
#include "plugin.h"


int main(){
		int i = 3;

	printf("Results for ’ %d’:\n", i);
	
	call("b", i);

	printf("New call\n");
	call("b",4);
	return 0;



}
