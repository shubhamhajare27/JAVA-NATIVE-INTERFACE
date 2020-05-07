#include<stdio.h>
#include<stdlib.h>
#include<jni.h>
#include"IntArray.h"

JNIEXPORT jint JNICALL 
Java_IntArray_sumArray(JNIEnv * env,jobject this,jintArray array)
{
	//jint buff[10];
	
	jint size=(*env)->GetArrayLength(env,array);

	jint buff[size];
	//jint * ptr=(jint *)malloc(sizeof(jint));

	jint i,sum=0;
	
	(*env)->GetIntArrayRegion(env,array,0,size,buff);
	
	for(i=0;i<10;i++)
	{
		sum+=buff[i];
	}
	
	//free(ptr);

	return sum;
}
