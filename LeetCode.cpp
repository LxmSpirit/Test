// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int* intersect2(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int compare(const void *a,const void *b);
int* plusOne(int* digits, int digitsSize, int* returnSize);
int* plusOne2(int* digits, int digitsSize, int* returnSize);
void moveZeroes(int* nums, int numsSize);
void moveZeroes2(int* nums, int numsSize);
void moveZeroes3(int* nums, int numsSize);

int main(int argc, char* argv[])
{
	//intersect
	/*
	int nums1[4] = {1,2,2,1};
	int nums2[2] = {2,2};
	int returnSize=0;
	//int* a = intersect(nums1,6,nums2,6,&returnSize);
	int* a = intersect2(nums1,4,nums2,2,&returnSize);
	printf("���\n");
	printf("returnSize: %d\n",returnSize);
	int i=0;//���ѭ��
	for(i=0;i<returnSize;i++)
	{
		printf("%d \n",a[i]);
	}
	
	*/
	//printf("Hello World!\n");
	//int nums3[3] = {1,2,9};

	/*
	int nums4[1] = {0};
	int b=0;
	//int *p = plusOne(nums3,3,&b);
	int *p = plusOne(nums4,1,&b);
	printf("---%d",b);
	*/

	/*
	int nums4[1] = {0};
	int b=0;
	//int *p = plusOne(nums3,3,&b);
	int *p = plusOne2(nums4,1,&b);
	printf("---\n %d \n",b);
	*/
	/*
	int nums6[5] = {0,2,4,0,9};
	moveZeroes(nums6,5);
	printf("\n---\n");
	int nums7[5] = {0,1,0,3,12};
	moveZeroes(nums7,5);
	*/
	/*
	int nums6[5] = {0,2,4,0,9};
	moveZeroes2(nums6,5);
	printf("\n---\n");
	int nums7[5] = {0,1,0,3,12};
	moveZeroes2(nums7,5);
	*/

	int nums6[5] = {0,2,4,0,9};
	moveZeroes3(nums6,5);
	printf("\n---\n");
	int nums7[5] = {0,1,0,3,12};
	moveZeroes3(nums7,5);

	return 0;
}



//��������Ľ���
/*
����������������?nums1 �� nums2 ��������������ʽ����������Ľ�����
���ؽ����ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������ж����ֵĴ���һ�£�������ִ�����һ�£�����ȡ��Сֵ����
���Բ�������������˳��

*/
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int i=0;//ѭ��1
	int j=0;//ѭ��2
	int z=0;//ѭ��res �Ƿ��Ѿ�����
	int k=0;//ѭ��res ȷ������
	bool exist = false;
	*returnSize = 0;//���
	int * p;
	if(nums1Size < nums2Size)
	{
		p =(int *)malloc(nums2Size);
		//printf("%d \n",nums2Size);
	}else
	{
		p =(int *)malloc(nums1Size);
		//printf("%d \n",nums1Size);
	}	
	//printf("%d \n",*returnSize);

	for(i=0;i<nums1Size;i++)//�ҵ����������ж����ڵ�����
	{
		exist = false;
		//printf("%d \n",nums1[i]);
		for(j=0;j<nums2Size;j++)
		{
			if(nums1[i] == nums2[j])
			{
				for(z=0;z<*returnSize;z++)
				{
					if(nums1[i]==p[z])
					{
						exist=true;
						break;
					}
				}
				if(!exist)
				{
					p[*returnSize] = nums1[i];
					*returnSize = *returnSize+1;
				}			
				
			}
		}
	}
    int newlen = *returnSize-1;
	for(k=0;k<*returnSize;k++)
	{
		int cout1=0;
		int cout2=0;		
		for(i=0;i<nums1Size;i++)
		{
			if(nums1[i] == p[k])
			{
				cout1= cout1+1;
			}
		}
		//printf("cout1: %d \n",cout1);

		for(j=0;j<nums2Size;j++)
		{
			if(nums2[i] == p[k])
			{
				cout2= cout2+1;
			}
		}
		//printf("cout2: %d \n",cout2);
		//printf("*returnSize: %d \n",*returnSize);
		//printf("newlen: %d \n",newlen);
		if(cout1<=cout2)
		{
			while(cout1>1)
			{
				newlen = newlen+1;			
				p[newlen] = p[k];
				//printf("p[newlen]: %d \n",p[newlen]);
				cout1 = cout1-1;
			}
		}else
		{
			while(cout2>1)
			{
				newlen = newlen+1;			
				p[newlen] = p[k];
				cout2 = cout2-1;
			}
		}

	
	}

	//printf("!!!!!!*returnSize: %d \n",*returnSize);
	//printf("!!!!!!newlen: %d \n",newlen);
	*returnSize = newlen+1;
	//printf("@@@@!!!!!!*returnSize: %d \n",*returnSize);

	return p;
}

 int compare(const void *a,const void *b) {
     return *(int*)a -  *(int*)b;
 }

int* intersect2(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int i=0;//ѭ��1
	int j=0;//ѭ��2
	int psum = 0;//���
	int * p;
	if(nums1Size < nums2Size)
	{
		p =(int *)malloc(nums2Size*sizeof(int));
		//printf("%d \n",nums2Size);
	}else
	{
		p =(int *)malloc(nums1Size*sizeof(int));
		//printf("%d \n",nums1Size);
	}

	//������
	qsort(nums1, nums1Size, sizeof(int), compare);
	qsort(nums2, nums2Size, sizeof(int), compare);
	
	/*
	 qsort��Ҫ��� int compare(const void *a,const void *b)����ʹ�� compare������const void * ����
	*/
	for(i=0;i<nums1Size-1;i++)
	{
		int index = i;
		int val = nums1[index+1];
		while(index>=0)
		{
			if(nums1[index]>val)
			{
				nums1[index+1] = nums1[index];
			}else
			{
				break;	
			}

			index = index-1;
		}
		nums1[index+1] = val;
	}

	for(j=0;j<nums2Size-1;j++)
	{
		int index = j;
		int val = nums2[index+1];
		while(index>=0)
		{
			if(nums2[index]>val)
			{
				nums2[index+1] = nums2[index];
			}else
			{
				break;	
			}

			index = index-1;
		}
		nums2[index+1] = val;
	}
	

	int a=0;
	int b=0;
	while(a<nums1Size && b<nums2Size)
	{
		if(nums1[a]==nums2[b])
		{
			p[psum] = nums1[a];
			psum = psum +1;
			a = a+1;
			b = b+1;
		}else if(nums1[a]<nums2[b])
		{			
			a = a+1;
		}else if(nums1[a]>nums2[b])
		{		
			b = b+1;
		}
	
	}
	* returnSize =psum;

	return p;
}

/*
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

*/

int* plusOne(int* digits, int digitsSize, int* returnSize){
	
	int i=1;
	int res;
	int lastn = digits[digitsSize-i];
	int* p =(int *)malloc((digitsSize+1)*sizeof(int));
	int* p1 =(int *)malloc((digitsSize+1)*sizeof(int));
	int j =0;
	int k =0;
	while(i<=digitsSize)
	{
		if(lastn+1 ==10)
		{
			res = 0;
			digits[digitsSize-i] = res;
			p[j] = res;
			i++;
			j++;
			if(i<=digitsSize)
			{
				lastn = digits[digitsSize-i];
				
			}else
			{
				p[j] = 1;		
			}
			
		}else{
			res = lastn+1;
			digits[digitsSize-i] = res;
			p[j] = res;
			if(digitsSize-i !=0)
			{
				j++;
				int q = digitsSize-i-1;
				for(q=digitsSize-i-1;q>=0;q--)
				{
					p[j] = digits[q];
					j++;
				}
			}
			
			break;
		}
		
	}

	//printf("%d \n",k);
	printf("p--------\n");
	int z1=0;
	for(z1=0;z1<j+1;z1++)
	{
		printf("%d ",p[z1]);
	}

	printf("--------\n");
	printf("j----%d---i---%d---\n",j,i);
	while(j>=0)
	{
		if(i>=digitsSize)
		{
			p1[k] = p[j];
			printf("\n**%d**\n",p1[k]);
			k++;
			j--;
			
		}else{
			p1[k] = p[j-1];
			k++;
			j = j-1;
			if(j == 0) break;
		}
	
	}

	
	*returnSize = k;
	printf("%d \n",k);
	printf("p1--------\n");
	int z=0;
	for(z=0;z<k;z++)
	{
		printf("%d ",p1[z]);
	}

	return p1;

}

int* plusOne2(int* digits, int digitsSize, int* returnSize){
	
	for(int i=digitsSize-1;i>=0;i--)
	{
		if(digits[i] !=9)
		{
			digits[i] = digits[i]+1;
			* returnSize = digitsSize;
			return digits;
		}else
		{
			digits[i] = 0;
		}

	}

	int newlen = digitsSize+1;
	* returnSize = newlen;
	int* p =(int *)malloc(newlen*sizeof(int));
	for(int j = 1;j<newlen;j++)
	{
		p[j] = digits[j-1];
	}
	p[0] = 1;

	return p;

}

/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

��ע�� �������ڲ���������������ԭ�ض�������в�����
*/

void moveZeroes(int* nums, int numsSize){
	
	for(int i =0;i<numsSize;i++)
	{
		printf("%d",nums[i]);

	}
	printf("\n");
	for( i =0;i<numsSize;i++)
	{
		printf("�� %d �� : %d\n",i,nums[i]);
		for(int j =0;j<numsSize;j++)
		{
			printf("%d",nums[j]);
		}
		printf("\n");

		if(nums[i] == 0)
		{
			int index = i+1;
			/*
			printf("index: %d nums[index]:%d \n",index,nums[index]);
			printf("numsSize: %d\n",numsSize);
			*/
			int temp = nums[i];
			int iszero=0;//��¼�м�Ϊ0�ĸ��� �ƶ���ʱ�� �����м���
			while(i<numsSize && index < numsSize)
			{
				if(nums[index] != 0)
				{
					//int temp = nums[i];
					nums[index-1-iszero] = nums[index];
					nums[index]=temp;
					//nums[index] = temp;
					//i = i+1;
					index = index+1;
				}else
				{
					//i = i+1;
					//index = i+1;
					//nums[index] = temp;
					//nums[index-1] = temp;
					iszero = iszero+1;
					index = index+1;
					//break;
				}

			}
			//nums[index-1] = temp;

			printf("������:\n");
			for(j =0;j<numsSize;j++)
			{
				printf("%d",nums[j]);
			}
			printf("\n");
			
			//i = index-1;

		}
	}

	printf("\n----\n");
	for(i =0;i<numsSize;i++)
	{
		printf("%d ",nums[i]);

	}
	
}


void moveZeroes2(int* nums, int numsSize){

	for(int z =0;z<numsSize;z++)
	{
		printf("%d",nums[z]);

	}
	printf("\n");
	
	int i=0;
	for(int j =0;j<numsSize;j++)
	{
		if(nums[j]==0)
		{
			i = i+1;
		}else if(i!=0)//���nums[j]����0 ����ǰ�滹��0
		{
			nums[j-i] = nums[j];
			nums[j]=0;
		}
	
	}

	printf("������:\n");
	for(j =0;j<numsSize;j++)
	{
		printf("%d",nums[j]);
	}
	printf("\n");
	
}

void moveZeroes3(int* nums, int numsSize){//�����в���0����ǰŲ

	for(int z =0;z<numsSize;z++)
	{
		printf("%d",nums[z]);

	}
	printf("\n");
	
	int i=0;
	int index=0;
	for(int j =0;j<numsSize;j++)
	{
		if(nums[j]!=0)
		{
			nums[index] = nums[j];
			index++;
		}
	
	}
	
	while(index<numsSize)
	{
		nums[index] = 0;
		index++;
	}

	printf("������:\n");
	for(j =0;j<numsSize;j++)
	{
		printf("%d",nums[j]);
	}
	printf("\n");
	
}

