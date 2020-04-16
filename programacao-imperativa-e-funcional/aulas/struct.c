#include <stdio.h>

int main(){

	/* Basico */

	struct mystruct{  // É possivel criar sem nome, mas n da pra criar uma instancia por fora
		int int_member;
		double double_member;
		char string_member[25];
	}; // É possivel definir instancias antes do ;

	struct mystruct struct_var;
	
	mystruct.int_member = 0;
	mystruct.double_member = 1.1;
	mystruct.string_member = "oi";

	mystruct = {2, 10.12, "atribuicao rapida"};
}