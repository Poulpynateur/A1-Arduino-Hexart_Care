#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void color(int t,int f) //Couleur dans la console
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}


int main()
{
    int i = 0;
    int time = 300;
  while (1)
  {
color(4,0);printf("                                             \n\
                  S                            \n\
                 SS                             \n\
                 SSS                            \n\
                  SS             .             \n\
                   `SSS           .             \n\
                      SSS        s              \n\
                .        SS        '               \n\
                s         S                       \n");
color(15,0);printf("           ``.....-..-------.---....``            \n\
        .ydmmmmNNNNhmmmhmmmddmdNNNmmmdho          \n\
        :MMMMMMMMMMmNmmmNmmmmmdMMMMMMMMM/-`       \n\
        -MMMMMMMMMMMMMMNNNNNNNNMMMMMMMMNdmd/      \n\
         mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo -dM-     \n\
         oMMMMMMMMMMMMMMMMMMMMMMMMMMMMN.  hM/     \n\
         `dMMMMMMMMMMMMMMMMMMMMMMMMMMM/ .sMh`     \n\
          .mMMMMMMMMMMMMMMMMMMMMMMMMMh/smmo`      \n\
           .dMMMMMMMMMMMMMMMMMMMMMMNmdyo:`        \n\
            `oNMMMMMMMMMMMMMMMMMMMm:              \n\
              .sNMMMMMMMMMMMMMMNd+`               \n\
       `````````.+yhhhhddddhhyo:``````````        \n\
    +yhddddddmmmmmmmmmmmmmmmmmmmmmmmddddddhhs.    \n\
     `-:/+osyyhhdddmmmmmmmmmmmdddhhhysoo+/-.      \n");
    Sleep(time);
    system("cls");

color(4,0);printf("                                               \n\
                        s           .        \n\
                  .      SS          .       \n\
                .        S         s        \n\
                s       SS        '         \n\
                 '     SSS                   \n\
                '      SS                      \n\
                       S                        \n\
                      S                          \n");
color(15,0);printf("           ``.....-..-------.---....``            \n\
        .ydmmmmNNNNhmmmhmmmddmdNNNmmmdho          \n\
        :MMMMMMMMMMmNmmmNmmmmmdMMMMMMMMM/-`       \n\
        -MMMMMMMMMMMMMMNNNNNNNNMMMMMMMMNdmd/      \n\
         mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo -dM-     \n\
         oMMMMMMMMMMMMMMMMMMMMMMMMMMMMN.  hM/     \n\
         `dMMMMMMMMMMMMMMMMMMMMMMMMMMM/ .sMh`     \n\
          .mMMMMMMMMMMMMMMMMMMMMMMMMMh/smmo`      \n\
           .dMMMMMMMMMMMMMMMMMMMMMMNmdyo:`        \n\
            `oNMMMMMMMMMMMMMMMMMMMm:              \n\
              .sNMMMMMMMMMMMMMMNd+`               \n\
       `````````.+yhhhhddddhhyo:``````````        \n\
    +yhddddddmmmmmmmmmmmmmmmmmmmmmmmddddddhhs.    \n\
     `-:/+osyyhhdddmmmmmmmmmmmdddhhhysoo+/-.      \n");
    Sleep(time);
    system("cls");

color(4,0);printf("                                               \n\
                     S                  \n\
                      S                 \n\
                       SS                 \n\
                       SSS                  \n\
                        SS                   \n\
                      SSS       .               \n\
              .       SS        s                \n\
                    S          '              \n");
color(15,0);printf("           ``.....-..-------.---....``            \n\
        .ydmmmmNNNNhmmmhmmmddmdNNNmmmdho          \n\
        :MMMMMMMMMMmNmmmNmmmmmdMMMMMMMMM/-`       \n\
        -MMMMMMMMMMMMMMNNNNNNNNMMMMMMMMNdmd/      \n\
         mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo -dM-     \n\
         oMMMMMMMMMMMMMMMMMMMMMMMMMMMMN.  hM/     \n\
         `dMMMMMMMMMMMMMMMMMMMMMMMMMMM/ .sMh`     \n\
          .mMMMMMMMMMMMMMMMMMMMMMMMMMh/smmo`      \n\
           .dMMMMMMMMMMMMMMMMMMMMMMNmdyo:`        \n\
            `oNMMMMMMMMMMMMMMMMMMMm:              \n\
              .sNMMMMMMMMMMMMMMNd+`               \n\
       `````````.+yhhhhddddhhyo:``````````        \n\
    +yhddddddmmmmmmmmmmmmmmmmmmmmmmmddddddhhs.    \n\
     `-:/+osyyhhdddmmmmmmmmmmmdddhhhysoo+/-.      \n");
    Sleep(time);
    system("cls");

  }
return 0;
}