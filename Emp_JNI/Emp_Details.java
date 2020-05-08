class Employee
{
	private String first_name;
	
	private int Identity_no;

	public void GetDetails()
	{
		System.out.println("The Name is "+first_name+" and roll no is "+Identity_no);
	}
}

class Emp_Details
{
	private native void access_emp(Employee obj);

	public static void main(String arg[])
	{
		Emp_Details empObj=new Emp_Details();

		Employee emp=new Employee();

		empObj.access_emp(emp);
	}

	static
	{
		System.loadLibrary("emp_details");
	}
}
