#include<stdio.h>
#include<stdlib.h>

int digitalRiver(int num);
bool check(int a, int b);

int main() {
	int a;
	scanf("%d", &a);
	int index = 1;
	while (index < a) {
		if (check(index, a) == 1) {
			printf("YES\n");
			break;
		}
		else if (check(index, a) == 0&&index==a-1) {
			printf("NO\n");
			break;
		}
		
		index++;
	}
	//printf("%d", check(23, 24));
	system("pause");
}
//int main() {
//	int a;
//	scanf("%d", &a);
//	int index = 1;
//	while (index < a) {
//		if (check(a, index) == 1) {
//			printf("YES\n");
//			break;
//		}
//		else if (index == a && check(a,index) == 0)
//			printf("NO\n");
//		index++;
//	}
//	system("pause");
//}

int digitalRiver(int num)
{
	int plus = 0;
	int temp = num;
	while (temp > 0) {
		plus += temp - temp / 10 * 10;
		temp /= 10;
	}
	return num + plus;
}

bool check(int a, int b)
{
	int index = 1;
	while (a != b&&index<2000) {
		if (a < b) a = digitalRiver(a);
		else if (a > b) b = digitalRiver(b);
		else;
		index++;
	}
	if (a == b) return 1;
	else return false;
}


