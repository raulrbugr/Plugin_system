/*
 * Plugin file
 */

#include "plugin.h"

#define PATH_MAX 200

 typedef struct plugin {
	 char* key;
	 void (*function)(int);
	 struct plugin* next;
 } plugin_t;

/*
 *Linked list with our plugins
 */

 static plugin_t* plugins;

/*
 * Function that regist the plugion funtion in the linked list
 */

 void plugin_register(char* key, void (*function)(int)) {

	 plugin_t* p = (plugin_t*) malloc(sizeof(plugin_t));
	 p->key = key;
	 p->function = function;
	 p->next = plugins;
	 plugins = p;
	 printf("** Plugin ’ %s’ successfully registered.\n", key);
 }

 void plugin_unregister(char* key) {

	 plugin_t *prev = NULL, *p = plugins;

	 while (p) {
		 if (0 == strcmp(p->key, key))
		 	break;

		 prev = p;
		 p = p->next;

	}

		if (!p)
		 return;

		if (prev)
		 prev->next = p->next;
		else
		 plugins = p->next;

		free(p);
}

/*
 * Function which find the register plugin in the linked list
 */

static plugin_t* plugin_find(char* key) {

		 plugin_t* p = plugins;
		 while (p) {
		 	if (0==strcmp(p->key, key))
			 break;

		 p = p->next;
	 }
	 return p;
 }

/*
 * Function that call the external function
 */

 void call(char* key, int i) {

	 plugin_t* p;

	 p = plugin_find(key);

	//If the plugin isn't in the linked list -> register

	 if (!p) {
		 char libname[PATH_MAX];
		 sprintf(libname, "./dir%s/lib%s.so", key, key);
		 printf("Trying load ’ %s’.\n", libname);
		 dlopen(libname, RTLD_LAZY);
		 p = plugin_find(key);
	 }
	
	//If yes -> call
	 if (p)
	 	p->function(i);
	 else
	 	fprintf(stderr, "Error: Plugin ’ %s’ not available.\n", key);
 }

