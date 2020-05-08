import java.util.ArrayList;
class Sort_Array
{
	private native int[] sort_array(ArrayList arr);

	public static void main(String args[])
	{
		Sort_Array sa=new Sort_Array();

		ArrayList<Integer> arr=new ArrayList<Integer>(3);

		arr.add(3);
		arr.add(1);
		arr.add(2);

		for(int i=0;i<3;i++)
		{
			System.out.println("before:"+arr.get(i));
		}

		int[] array = sa.sort_array(arr);

		for(int i=0;i<3;i++)
		{
			System.out.println(array[i]);
		}
	}

	static 
	{
		System.loadLibrary("sort_array");
	}
}
