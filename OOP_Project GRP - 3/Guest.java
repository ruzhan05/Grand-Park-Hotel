
public class Guest //class Guest to store the information of the guest
{
	private Room[] book;
	private String ID;
	private String Name;
	private int phoneNum;
	private int RoomNum;
	private String CategoryId;

 Guest(String ID, String n, int phone, String cid)//constructor
 {
   this.ID = ID;
   Name = n;
   phoneNum = phone;
   CategoryId = cid;
   book = new Room[30];
 }
 public String getID()
 {
	 return ID;
 }
 public String getName()
 {
	 return Name;
 }
 public int getPhoneNum()
 {
	 return phoneNum;
 }

 public String getCategoryId()
 {
	 return CategoryId;
 }

 public void book(Room tk)
 {
	 book[RoomNum] = tk;
	 RoomNum++;
 }

 public void displayInfoRoom(){

	System.out.println("\nName"  + "    \tPhone number" + "    \tRoom Type" + "   \tRoom No."
	 + "   \tPrice" + "    \tTotal price");
	 for(int i=0; i<RoomNum; i++){

		Room r = (Room)book[i];


		 r.displayGuestInfo();
	 }
 }
}