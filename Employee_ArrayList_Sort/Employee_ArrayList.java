import java.util.ArrayList;

class Employee
{
	 int id;

	 String emp_name;

	 float salary;

	 public Employee(int id,String emp_name,float salary)
	 {
		 this.id=id;
		 this.emp_name=emp_name;
		 this.salary=salary;
	 }
}

class Employee_ArrayList
{
	private native void sort_emp(ArrayList emp_obj);
	
	public static void main(String argv[])
	{
		ArrayList<Employee> emp=new ArrayList<Employee>();

		emp.add(new Employee(2,"shubham",12000));
		emp.add(new Employee(3,"harshal",15000));
		emp.add(new Employee(1,"vinit",32000));

		System.out.println("employee array before sorting:-");

		for(int i=0;i<3;i++)
		{
			System.out.println(" "+emp.get(i).id);
		}

		Employee_ArrayList obj= new Employee_ArrayList();
		obj.sort_emp(emp);

		System.out.println("employee array after sorting:-");

		for(int i=0;i<3;i++)
		{
			System.out.println(" "+emp.get(i).id);
		}
	}

	static
	{
		System.loadLibrary("sort_emp");
	}
}
