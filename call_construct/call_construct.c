#include<stdio.h>
#include<jni.h>
#include"Call_Construct.h"

JNIEXPORT void JNICALL Java_Call_1Construct_call_1construct
  (JNIEnv * env, jobject this, jobject dobj)
{
	jclass cls;

	jmethodID mID;

	cls=(*env)->GetObjectClass(env,dobj);

	mID=(*env)->GetMethodID(env,cls,"<init>","(II)V");

	if(mID==NULL)
	{
		printf("method not accessed");
		return;
	}

	(*env)->CallNonvirtualVoidMethod(env,dobj,cls,mID,10,20);

}
