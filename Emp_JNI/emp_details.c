#include<stdio.h>
#include<jni.h>
#include"Emp_Details.h"

/*void SetName(jobject * emp_ptr)
{
	jfieldID fid_name;
	
	jstring jstr;

	jclass str_name;

	jclass cls=(*env)->GetObjectClass(env,emp);
	
	fid_name=(*env)->GetFieldID(env,cls,"name","Ljava/lang/String;");

	if(fid_name==NULL)
	{
		return;
	}

	jstr=(*env)->NewStringUTF(env,"shubham");
	
	(*env)->SetObjectField(env,emp,fid_name,jstr);	
}
*/


JNIEXPORT void JNICALL Java_Emp_1Details_access_1emp
  (JNIEnv * env, jobject this, jobject emp)
{
	jfieldID fid_name;
	
	jfieldID fid_ID;

	jmethodID mid;

	jstring jstr;

	jclass str_name;

	jclass cls=(*env)->GetObjectClass(env,emp);
	
	fid_name=(*env)->GetFieldID(env,cls,"first_name","Ljava/lang/String;");

	if(fid_name==NULL)
	{
		return;
	}

	jstr=(*env)->NewStringUTF(env,"shubham");
	
	(*env)->SetObjectField(env,emp,fid_name,jstr);	

	fid_ID=(*env)->GetFieldID(env,cls,"Identity_no","I");
	
	(*env)->SetIntField(env,emp,fid_ID,10);

	mid=(*env)->GetMethodID(env,cls,"GetDetails","()V");

	if(mid==NULL)
	{
		return;
	}

	(*env)->CallVoidMethod(env,emp,mid);
	

}
	
