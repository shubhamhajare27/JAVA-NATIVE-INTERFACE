#include<stdio.h>
#include<jni.h>
#include"Sort_Array.h"

void mySort(int * arr,int iSize)
{
	int i=0;
	int j=0;
	int temp=0;

	for(i=0;i<iSize-1;i++)
	{
		for(j=i+1;j<iSize;j++)
		{
			if(arr[j]<arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
}

JNIEXPORT jintArray JNICALL Java_Sort_1Array_sort_1array
  (JNIEnv * env, jobject this, jobject array_list)
{
	jclass arrcls;
	
	jmethodID sizeID;
	
	jmethodID getID;

	int iSize=0;

	int iCnt=0;

	jobject element;

	jobject obj;

	arrcls=(*env)->GetObjectClass(env,array_list);
	
	sizeID=(*env)->GetMethodID(env,arrcls,"size","()I");
	
	getID=(*env)->GetMethodID(env,arrcls,"get","(I)Ljava/lang/Object;");

	iSize=(*env)->CallIntMethod(env,array_list,sizeID);

//	printf("size= %d\n",iSize);

	jint temp[iSize];

	jclass intcls=(*env)->FindClass(env,"java/lang/Integer");

	for(iCnt=0;iCnt<iSize;iCnt++)
	{
		obj=(*env)->CallObjectMethod(env,array_list,getID,iCnt);

		jclass cls=(*env)->GetObjectClass(env,obj);

		jmethodID vid=(*env)->GetMethodID(env,cls,"intValue","()I");

		temp[iCnt]=(*env)->CallIntMethod(env,obj,vid);
	}

/*	printf("Data of ArrayList before sorting\n");

	for(iCnt=0;iCnt<iSize;iCnt++)
	{
		printf("%d ",temp[iCnt]);
	}
*/
	mySort(temp,iSize);
	
	jintArray iarr=(*env)->NewIntArray(env,iSize);

	(*env)->SetIntArrayRegion(env,iarr,0,iSize,temp);

	return iarr;
}


