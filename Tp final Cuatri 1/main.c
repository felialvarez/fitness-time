#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "menu.h"

stUsuario usuarios[20];

int main()
{

    inicio();
    if (!usuarioRegistrado())
    {
        registrarse();
    }
    else
    {
        registrarseOlogin();
    }
    return 0;
}



