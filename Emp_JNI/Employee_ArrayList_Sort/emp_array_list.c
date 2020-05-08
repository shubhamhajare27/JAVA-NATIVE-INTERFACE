#include<stdio.h>
#include<jni.h>
#include"Employee_ArrayList.h"

JNIEXPORT void JNICALL Java_Employee_1ArrayList_sort_1emp
  (JNIEnv * env, jobject this, jobject emp)
{
	jclass arrcls;

	jobject element;

	jmethodID jid;
	
	jclass empcls;

	jfieldID identityID;
	
	int emp_id;

	arrcls=(*env)->GetObjectClass(env,emp);

	if(arrcls==NULL)
	{
		printf("tt");
		return;
	}

	jid=(*env)->GetMethodID(env,arrcls,"get","(I)java/lang/object;");

	if(jid==NULL)
	{
		printf("kk");
		return;
	}

	element=(*env)->CallObjectMethod(env,emp,jid,0);

	empcls=(*env)->GetObjectClass(env,element);

	identityID=(*env)->GetFieldID(env,empcls,"id","I");

	emp_id=(*env)->GetObjectField(env,element,identityID);

	printf("%d\n",emp_id);


}


