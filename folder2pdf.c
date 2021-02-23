#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <magic.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

_Bool DoesDirectoryExists(DIR* dir) {//dir is a struct from dirrent.h https://stackoverflow.com/questions/12510874/how-can-i-check-if-a-directory-exists*/
	if (diropen(dir)) {
    		closedir(dir);
		return FALSE
	} 
	else if (ENOENT == errno) {
    		return TRUE
	}
}

int DoesDirectoryHaveFiles(const char *path) { /*function that takes a path argument's location in memory*/
	/* https://rosettacode.org/wiki/Empty_directory#C */
	struct dirent *ent; /* initialize a variable to represent an directory entity */
	int ret = 1; /* this variable is spit out at the end of the function to main */
	DIR *d = opendir(path); /* create a new variable that is a pointerportal to the result of this function*/

	if (!d) { //if not d?
		fprint(stderr, "%s: ", path);
		perror(""); //prints a custom error? methinks its something to say "not a directory"
		return -1;
	}

	while ((ent=readdir(d))) { //set the pointer ent to point at the first directory entry in the stream
		if (!strcmp(ent->d_name, ".") || !(strcmp(ent->d_name,"..")))
			continue;
		/*dereference pointer ent structure to component d_name then compare the string with "." and ".."*/
/*if they dont compare continue*/
		ret = 0;
		break;
	}

	closedir(d);
	return ret;
}

/*A check if directory is empty */

_Bool DoesDirectoryContainImages(DIR* dir) { //s_ifmt(); how to use
		
}
