//1

/*#include <stdio.h>
int main () {
	int A=20 , B=5;
	int C=!--A/++!B;
	printf ("A=%d B=%d c=%d \n", A,B,C) ;
}*/




//2

/*#include <stdio.h>
int main () {
	int A=20 , B=5 , C= -10 , D =2;

	printf ("%d\n", !0&&C++&&!D++||A&&B) ;
	
	printf ("c=%d d=%d \n", C, D) ;
	printf("%d\n",C );
}*/




//3

/*#include <stdio.h>
int main () {
	int p[4]={1 , -2 ,3 ,4};
	int *q=p;
	printf ("c=%d\n", *++q**q++) ;
	printf ("c=%d \n" ,*q);
}*/



//4

/*#include <stdio.h>
int main () {
	int p [4]={1 , -2 ,3 ,4};
	int *q=p;
	int d=*q&*q++|*q++;
	printf ("d=%d\n", d) ;
	printf ("q=%d \n" ,*q);
}*/



//5

/*#include <stdio.h>
int main () {
	int a= -8 ,b =3;
	int c= ++a&&--b?b--:a++;
	printf ("a=%d b=%d c=%d\n",a,b,c) ;
}
*/



//6

/*#include <stdio.h>
int main () {
	int a= -8 ,b =3;
	a >>=2^b;
	printf ("a=%d\n",a) ;
}
*/