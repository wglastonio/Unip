#include <stdio.h>
#include <stdlib.h>



/* Fun��o para validar entrada de Menu */

int coletaOpcaoMenu()

{
int opcaoNum;

      if (scanf("%d", &opcaoNum) < 1 ) {
          while(getchar() != '\n' );
      }
      else {
         return opcaoNum;
      }
}
