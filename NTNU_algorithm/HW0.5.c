#include<stdio.h>
//#include<math.h>

int main() {
	int line, Fn, Fnplus1;
	//unsigned int total= 0;//使用無號數
	scanf("%u", &line);//要幾行
	int Fibonacci ;
	if (line <= 100000) {
		for (int i = 1; i <= line; i++) {
			scanf("%u %u", &Fn, &Fnplus1);
			Fibonacci = Fn + Fnplus1;
			printf("%u\n", Fibonacci);
		}
	}
	else {
		printf("error");
	}
	return 0;
}