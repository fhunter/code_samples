#include <stdio.h>
#include <dlfcn.h>

int
main (int argc, char **argv)
{
  void *plugin1_handle = NULL, *plugin2_handle = NULL;
  int (*plugin1_function)(int) = NULL;
  int (*plugin2_function)(int) = NULL;
  int i=2;

  plugin1_handle=dlopen("plugin1.so",RTLD_NOW|RTLD_LOCAL);
  plugin2_handle=dlopen("plugin2.so",RTLD_NOW|RTLD_LOCAL);

  plugin1_function=dlsym(plugin1_handle, "output_data");
  plugin2_function=dlsym(plugin2_handle, "output_data");

  printf("Plugin1 output_data function called with i=2 returns:\n");
  printf("%d\n",plugin1_function(i));
  printf("Plugin2 output_data function called with i=2 returns:\n");
  printf("%d\n",plugin2_function(i));
  
  dlclose(plugin1_function);
  dlclose(plugin2_function);

  return 0;
};
