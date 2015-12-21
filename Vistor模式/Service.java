package Vistor模式;

public class Service {
	private Visitor visitor = new VisitorImpl();
	
	void doService(Customer customer){
		customer.doCustomer();
		((Visitable)customer).accept(visitor);
		customer.pay();
	}
	
	public static void main(String[] args) {
		Service service = new Service();
		service.doService(new Member());
	}
}
