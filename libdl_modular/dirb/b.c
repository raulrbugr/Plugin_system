#include <stdio.h>
#include "../plugin.h"
#include "b.h"

void b(int i){
	printf("b ( %d) returns '%d' \n", i, b2(i));
}

// We need this constructor to mount in the plugin system
static void init() __attribute__((constructor));

static void init(){
	plugin_register("b", &b);
}
