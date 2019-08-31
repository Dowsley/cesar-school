#include <stdio.h>
#include <string.h>

int main () {

   union rank {
	   int num;
	   char letter;
   };

   enum suits {hearts, diamonds, clubs, spades};

   struct card{
	   union rank r;
	   enum suits s;
   };

   struct card deck[52];

   deck[0].r.num = 2;
   deck[0].s = clubs;

   printf("%d\n",deck[0].r.num);
   printf("%zu\n",sizeof(int));
   printf("%zu\n",sizeof(char));
   printf("%zu\n",sizeof(union rank));
   printf("%zu\n",sizeof(enum suits));
   printf("%zu\n",sizeof(struct card));

   return 0;
}
