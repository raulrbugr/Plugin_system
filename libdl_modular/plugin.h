/*
 * Plugin header file
 */

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>


void plugin_register(char* key, void (*function)(int));
void plugin_unregister(char* key);
void call(char* key, int i);
