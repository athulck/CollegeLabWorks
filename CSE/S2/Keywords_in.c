#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{

	#if 0
	// 1. auto : Defines a local variable as having a local lifetime
	auto int v1 = 10;
	printf("\nauto int v1 = %d\n", v1);


	// 2. break : Passes control out of the compound statement (while, do, for or switch).
	while (1) {
		
		break;
		printf("\nThis statement won't even get executed! lol :) ");
	}


	// 3. const : Makes variable value or pointer parameter unmodifiable.
	const int v2 = 20;
	printf("\nconst int v2 = %d\n", v2);
	// v2 = 30; [error]
	/* [HACK]: "You can change the value of a const variable in C ;)" */
	*(int *)(&v2) = 40;
	printf("\n[Hacked] const int v2 = %d\n", v2);


	// 4. continue : Passes control to the begining of the loop.
	for (int i=0; i<10; i++) {

		continue;
		printf("\nThis statement won't even get executed! lol :) ");
	}


	// 5. do : just "do" it.
	do {
		printf("\nThis is getting 'done'.\n");
	} while(0);


	//6. double : double precision floating point data type.
	double v3 = 10.123456789;
	printf("\ndouble v3 = %lf\n", v3);

	// 7. enum : defines a set of constants of type int.
	enum week {Sun=1, Mon, Tue, Wed, Thu, Fri, Sat};
	printf("\nlist: {Sun:%d, Mon:%d, Tue:%d, Wed:%d, Thu:%d, Fri:%d, Sat:%d}\n", Sun, Mon, Tue, Wed, Thu, Fri, Sat);
	enum week today = Tue;
	printf("\nToday is: %d\n", today);
	// enum alpabets {
	// 	A='A', B='B', C='C', D='D', E='E', F='F', G='G', H='H', I='I', J='J', K='K', L='L', M='M', N='N', O='O', P='P', Q='Q', R='R', S='S', T='T', U='U', V='V', W='W', X='X', Y='Y', Z='Z',
	// };
	// printf("\nAlpabets %c : %d", A, A);


	// 8. extern : indicates that an identifier is defined elsewhere.
	int v4; // Allocates memory for a variable 'v4'; 
	// extern int v4; -// 'v4' is available in importing files too !
	printf("\nv4 = %d\n", v4);


	// 9. float : single precision floating point data type
	float v5 = 10.123456789;
	printf("\nfloat v5 = %lf\n", v5);


	// 10. for : loop
	for (printf("\n[for]init"); printf("\n[for]check"); printf("\n[for]update"))
	{
		break;
	}


	// 11. goto : Unconditionally transfer control to a label.
	int i;
	reinit:
	for (i=0; i<11; i++) {
		// printf("\n%d", i);
		if (i == 11)
			goto reinit;
	}


	// 12. if () else ...
	if (1) 
		if (1)
			if (0);
		else
			printf("\nFlasified !");  // will get printed !
	else
		printf("\nNope !");


	// 13. int
	// 14. char

	// 15. register : Tells the compiler to store the variable being declared in a CPU register.
	register int v6 = 20;

	// short, long, int, unsigned

	// 20. sizeof

	// 21. static : Preserves variable value to survive after its scope ends.


	
	
	#endif

	clock_t start = clock();
	/* playground */

	register int i = 0;
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	for (i; i<1000; i++)
		printf("\n%d", array[i%10]);

	printf("\nTime: %f ms\n", (float)(clock() - start) / CLOCKS_PER_SEC );

	printf("\n");

	// return : exits the funtion
	return 1;
}







