#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct {

	float re;
	float im;
} complex;

/* function prototype*/
complex* createComplexArray(float* re_array,float* im_array,size_t size);
complex createComplexNumber(float re, float im);
complex addComplexNumber(const complex* num1,const complex* num2);
complex multiplyComplexNumber(const complex* num1,const complex* num2);
void displayComplexNumber(const complex* num);
int main() {

	complex a[2]= {{2.3,1.5},{4.6,6.4}};

	complex *ptr_a[2]={&a[0],&a[1]};

	complex sum= addComplexNumber(ptr_a[0],ptr_a[1]);
	complex product= multiplyComplexNumber(ptr_a[0],ptr_a[1]);
	
	printf("Sum of complex number: ");
	displayComplexNumber(&sum);
	
	printf("Product of complex number:");
	displayComplexNumber(&product);

	complex num1=createComplexNumber(3.0,-2.0);
	complex num2=createComplexNumber(1.0,4.0);
	complex* complexArray=createComplexArray((float[]){1.0,-2.1,3.3},(float[]){3.0,4.5,-5.0},3);

	printf("Complex number1: \n");
	displayComplexNumber(&num1);

	printf("Complex number2: \n");
	displayComplexNumber(&num2);

	printf("Complex number array:\n");
	for(size_t i=0;i<3;i++){
		displayComplexNumber(&complexArray[i]);
	}

//	free(complexArray);
return 0;
}

complex createComplexNumber(float re, float im)
{
	complex num;
	num.re=re;
	num.im=im;
	return num;
}
complex* createComplexArray(float* re_array,float* im_array,size_t size)
{

	complex* complexArray=malloc(sizeof(complex)*size);
	if(complexArray==NULL){
		fprintf(stderr,"Error malloc\n");
		exit(EXIT_FAILURE);
		
	}
	for (size_t i = 0; i <size; i++)
	{
		complexArray[i].re=re_array[i];
		complexArray[i].im=im_array[i];
	}
	return complexArray;
	
}
void displayComplexNumber(const complex* num)
{
	if(num->im >=0){
	printf("%.2f + %.2fi\n",num->re,num->im);
} else {
	printf("%.2f - %.2fi\n",num->re,-num->im);
}

}
complex addComplexNumber(const complex* num1,const complex* num2)
{
	complex result;
	result.re=num1->re + num2->re;
	result.im=num1->im + num2->im;
	return result;

}
complex multiplyComplexNumber(const complex* num1,const complex* num2)
{
	complex result;
	result.re=num1->re *num2->re -num1->im* num2->im;
	result.im=num1->re*num2->im + num1->im * num2->re;
	return result;
}