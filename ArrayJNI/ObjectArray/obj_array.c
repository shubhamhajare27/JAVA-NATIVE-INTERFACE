#include<stdio.h>
#include<jni.h>
#include"ObjectArray.h"
	
JNIEXPORT jobjectArray JNICALL 
Java_ObjectArray_twoDimensionalArray(JNIEnv * env,jobject this,jint iSize)
{
	jobjectArray result;

	int i=0;

	jclass intArrayClass=(*env)->FindClass(env,"[I");

	if(intArrayClass==NULL)
	{
		return NULL;
	}

	result=(*env)->NewObjectArray(env,iSize,intArrayClass,NULL);

	if(result==NULL)
	{
		return NULL;
	}
	

	int j=0;

	for(i=0;i<iSize;i++)
	{
		jintArray iarr=(*env)->NewIntArray(env,iSize);

		jint temp[3]={0};

		if(iarr==NULL)
		{
			break;	
		}

		for(j=0;j<iSize;j++)
		{
			temp[j]=i+j;
		}

		(*env)->SetIntArrayRegion(env,iarr,0,iSize,temp);
		(*env)->SetObjectArrayElement(env,result,i,iarr);
		(*env)->DeleteLocalRef(env,iarr);
			
	}

	if(i<iSize)
	{
		return NULL;
	}

	return result;
}
