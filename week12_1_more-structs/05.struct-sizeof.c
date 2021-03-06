#include <stdio.h>

/* Try to uncomment and run. What do you see? 
 * So "pragma pack" commands packs up (squizes) the structs.
 */
//#pragma pack (1) 

typedef struct x
{
	short s; /* 2 bytes */
			 /* 2 padding bytes */
	int   i; /* 4 bytes */
	char  c; /* 1 byte */
			 /* 3 padding bytes */
} X;

/* This is struct X in your RAM: (1 cell = 1 Byte)
+-------+-------+-------+-------+
|       s       |     pad1      |
+-------+-------+-------+-------+
|               i               |
+-------+-------+-------+-------+
|   c   |         pad2          |
+-------+-------+-------+-------+
*/



typedef struct y
{
	int   i; /* 4 bytes */
	char  c; /* 1 byte */
			 /* 1 padding byte */
	short s; /* 2 bytes */
} Y;

/* This is struct Y in your RAM: (1 cell = 1 Byte)
+-------+-------+-------+-------+
|               i               |
+-------+-------+-------+-------+
|   c   | pad1  |       s       |
+-------+-------+-------+-------+
*/


typedef struct z
{
	int   i; /* 4 bytes */
	short s; /* 2 bytes */
	char  c; /* 1 byte */
			 /* 1 padding byte */
} Z;

/* This is struct Z in your RAM: (1 cell = 1 Byte)
+-------+-------+-------+-------+
|               i               |
+-------+-------+-------+-------+
|       s       |   c   | pad1  |
+-------+-------+-------+-------+
*/



typedef struct s{
	char a[3];
	short b;
	long c;
	char d[3];
} S;

/* This is struct S in your RAM: (1 cell = 1 Byte)
+-------+-------+-------+-------+
|           a           | pad1  |
+-------+-------+-------+-------+
|       b       |     pad2      |
+-------+-------+-------+-------+
|               c               |
+-------+-------+-------+-------+
|           d           | pad3  |
+-------+-------+-------+-------+
*/


typedef struct student {
  char name[50];
  int bday;
  short int id;
  double gpa;
} Student;

/* This is struct Student in your RAM: (1 cell = 1 Byte)
B   0       1       2       3
+-------+-------+-------+-------+
|                               |
|                               |
|                               |
|                               |
|                               |
|                               |
|             name              |
|                               |
|                               |
|                               |
|                               |
|                               |
|               |     pad       |   
+-------+-------+-------+-------+
|            bday               |
+-------+-------+-------+-------+
|       id      |      pad      |
|              pad              |
+-------+-------+-------+-------+
|      g                  a     |
|               p               |
+-------+-------+-------+-------+

Explanation:
1.  name is finished at bytes [#0~#49], so next available byte is #50. But for bday 50%sizeof(bday) != 0, so 2 bytes of padding.
2.  so bday should begin at byte #52, which is divisible by 4. So, bday is at bytes [#52~#55]. So, next available byte is #56.
3.  id is short, and 56%sizeof(id)=0, therefore id begins at #56. So, id is at bytes [#56~#57].  So, next available byte is #58. But 58%sizeof (gpa)!=0, so 6 bytes of padding.
4. Therefore, gpa begins at #64. So, gpa is at bytes [#64~#71] 
*/


int main()
{
	const int sizeX = sizeof(X); 
	const int sizeY = sizeof(Y); 
	const int sizeZ = sizeof(Z); 
	const int sizeS = sizeof(S);
	const int sizeStd = sizeof(Student);

	printf("size of X: %u\n", sizeX); /* = 12 */
	printf("size of Y: %u\n", sizeY); /* = 8 */
	printf("size of Z: %u\n", sizeZ); /* = 8 */
	printf("size of S: %u\n", sizeS); /* = 16 */
	
	printf("size of Student: %u\n", sizeStd); /* = 72 */
}

