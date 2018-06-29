#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int luyThua(int n) {
	long int sum = 1;

	while (n > 0) {
		sum *= 16;
		n--;
	}
	return sum;
}

int charToNum(char hex[]) {
	int dec = 0;
	int k = 0;
	for (int i = strlen(hex) - 1; i--; i > 1) {
		switch (hex[i])
		{
		case 48:
			dec += 0 * luyThua(k);
			k++;
			break;
		case 49:
			dec += 1 * luyThua(k);
			k++;
			break;
		case 50:
			dec += 2 * luyThua(k);
			k++;
			break;
		case 51:
			dec += 3 * luyThua(k);
			k++;
			break;
		case 52:
			dec += 4 * luyThua(k);
			k++;
			break;
		case 53:
			dec += 5 * luyThua(k);
			k++;
			break;
		case 54:
			dec += 6 * luyThua(k);
			k++;
			break;
		case 55:
			dec += 7 * luyThua(k);
			k++;
			break;
		case 56:
			dec += 8 * luyThua(k);
			k++;
			break;
		case 57:
			dec += 9 * luyThua(k);
			k++;
			break;
		case 65:
			dec += 10 * luyThua(k);
			k++;
			break;
		case 66:
			dec += 11 * luyThua(k);
			k++;
			break;
		case 67:
			dec += 12 * luyThua(k);
			k++;
			break;
		case 68:
			dec += 13 * luyThua(k);
			k++;
			break;
		case 69:
			dec += 14 * luyThua(k);
			k++;
			break;
		case 70:
			dec += 15 * luyThua(k);
			k++;
			break;
		}
	}
	return dec;
}

//float numToHex(char hex[]) {
//	int dec = 1;
//	int k = 0;
//	for (int i = strlen(hex) - 1; i--; i > 1)
//	{
//		dec += hex[i] * (10 ^ k);
//		k++;
//	}
//	return  dec;
//}

int main() {
	char hex[10] = "0xCAFE";
	printf("%d", charToNum(hex));
	system("pause");
}
