#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "action.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
    color(15,0);
	List *moi = stackfile();
	Element *actual = moi->first;

    menu(moi);

return 0;
}
