

interface Tax
{
 double Tax_Rate = 0.10;
 double calculatePrice();
}
//Class Tax

abstract class Room //Class Room
{
	public double Price;
	public String Name;
	public String RoomNum, RoomType, Category;
	public int PhoneNum;


	public Room(){}

	public Room(double p, String n, String cn, String s, String c,int pnum  )
	{
		Price = p;
		Name = n;
		RoomType = cn;
		RoomNum = s;
		Category = c;
		PhoneNum = pnum;
	}

	public double getPrice(){
		return Price;
	}

	public abstract void displayGuestInfo();

}


class Local extends Room implements Tax //declaration of inherited class Local
{
	 private double totalPrice;


	 public Local(){}

	 public Local(double r, double p, String n, String cn, String s, String c, int pnum)
	 {
		 super(p,n,cn,s,c,pnum);
	
	 }

	 public double calculatePrice()
	 {
		 double calc1, calc2;
		 double service = 0.03;
		 calc1 = super.Price * service; 
		 // calc1 = 15;
		 calc2 = super.Price * Tax_Rate;
		 totalPrice = (super.Price - calc1 + calc2);
		 return totalPrice;
	 }

	 public void displayGuestInfo()
	 {
		 System.out.println(super.Name  + super.PhoneNum + "\t" +"\t"+ super.RoomType + "\t"
		 +  super.RoomNum + "\t\t" + super.Price + "\t" + calculatePrice());

	 }


 }//Local


 class Foreigner extends Room implements Tax //declaration of inherited class Foreigner
 {
	 private double totalPrice;
	 private double Insurance_Tax_Rate;

	 public Foreigner(){}

	 public Foreigner(double r, double p, String n, String cn, String s, String c, int pnum)
	 {
		 super(p,n,cn,s,c,pnum);
		 Insurance_Tax_Rate = r;

	 }

	 public double calculatePrice()
	 {
		 double calc1, calc2;
		 calc1 = super.Price * Insurance_Tax_Rate;
		 calc2 = super.Price * Tax_Rate;
		 totalPrice = super.Price + calc1 + calc2;
		 return totalPrice;
	 }

	 public void displayGuestInfo()
	 {
		 System.out.println(super.Name + "\t" + "\t   " + super.PhoneNum + "           \t" + super.RoomType + "    \t"
		 +  super.RoomNum + "\t\t" + super.Price + "         \t" + calculatePrice());
	 }

 }//Foreigner


