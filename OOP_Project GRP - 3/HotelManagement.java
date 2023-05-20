import java.util.*;
public class HotelManagement //main
{
  public static void main(String args[])
  {
  Scanner menu1 = new Scanner(System.in);
  Scanner menu2 = new Scanner(System.in);
  ArrayList<Guest> pList = new ArrayList<Guest>();
  RoomInfo b1 = new RoomInfo();			
  RoomInfo b2 = new RoomInfo();

  //run loop until menu 4 is not pressed
    int choose;
      do{
         System.out.println("\n\n********** BOOKING Room for Grand Park Hotel ************");
  	     System.out.println("1. Book Room");
  	     System.out.println("2. Display rooms available");
  	     System.out.println("3. Display booked room details");
  	     System.out.println("4. Exit\n");

  	     System.out.print("Please enter your choice (1-4) : ");
  	     choose = menu1.nextInt();

  		 switch(choose)
  		 {
  			case 1:       //menu1 to book room
  			   Guest g1;
  			   Scanner menu = new Scanner(System.in);
  			   String d;
  			   String n, ctype;
  			   int p;
  			   int c;
			
			System.out.print("Enter guest Name: ");
			n = menu.next();
  			System.out.print("\nEnter Passport Number: ");
  		    d = menu.next();
		    System.out.print("Enter guest phoneNum: ");
			p = menu.nextInt();



			System.out.print("Enter guest category(Foreigner - 1/ Local - 2): "); //this is inheritance for class Room
		    c = menu.nextInt();                                                     //choose bwtween Foreigner or Local

			   if(c == 2){
					ctype = "Local";
		   	   }
		   	   else{
				ctype = "Foreigner";
			   }

			   g1 = new Guest(d,n,p,ctype);
			   int choice;
			   int SingleAv= b1.getAvailableRoom();
			   int DoubleAv = b2.getAvailableRoom();

			   do{
			   System.out.println("\nWhich room you want to book?");
			   System.out.println("1. Single - RM100.00 per night (Available room " + SingleAv + ")" );
			   System.out.println("2. Double - RM120.00 per night (Available room " + DoubleAv + ")" );
			   System.out.print("Your choice: ");
			   choice = menu2.nextInt();
			   }while((choice == 1 && SingleAv == 0) || (choice == 2 && DoubleAv == 0));

			   boolean status = true;

			   switch (choice){

			   case 1:  // if guest choose single room

			   	double service_charge = 0.10, discRate = 0.4;
			   	double price = 100.0;
			   	String roomType = "Single";

			  	if(ctype == "Local"){ // if guest is local
					String cate = "Local";
					Local n1 = new Local(discRate,price,g1.getName(),roomType,"10" + (b1.getRoomNum()+1),cate,g1.getPhoneNum());
					System.out.println("\nYour room price is: RM" + n1.getPrice());
			  		System.out.println("Your total room price is: RM" + n1.calculatePrice()+ "(including VAT and service charge)");
				    System.out.println("\nThank you for staying with us!");
					b1.assign(n1);
					for(int i = 0; i<pList.size(); i++){

						if (d.equals(pList.get(i).getID())){

							g1.book(n1);
							status = false;
							break;
					}}

				    if(pList.size() == 0 || status){

					   g1.book(n1);
					   pList.add(g1);
				    }

				}
				else{
					String cate = "Foreigner"; // if guest is foreigner
					Foreigner n1 = new Foreigner(service_charge,100.0,g1.getName(),roomType,"10" + (b1.getRoomNum()+1),cate,g1.getPhoneNum());
					System.out.println("\nYour original room price is: RM" + n1.getPrice());
			  		System.out.println("Your total Room price is: RM" + n1.calculatePrice()+ "(including VAT and service charge)");
				    System.out.println("\nThank you for staying with us!");
					b1.assign(n1);
					for(int i = 0; i<pList.size(); i++){

						if (d.equals(pList.get(i).getID())){

							g1.book(n1);
							status = false;
							break;
					}}

				    if(pList.size() == 0 || status){

					   g1.book(n1);
					   pList.add(g1);

				    }
				}
			  	break;

			   case 2:

				double service_charge2 = 0.10, discRate2 = 0.3;
			   	double price2 = 120.0;
			   	String roomType2 = "Double";

			  	if(ctype == "Local"){
					String cate = "Local";
					Local n1 = new Local(discRate2, price2, g1.getName(),roomType2,"20" + (b2.getRoomNum()+1),cate,g1.getPhoneNum());
					System.out.println("\nYour original room price is: RM" + n1.getPrice());
			  		System.out.println("Your total room price is: RM" + n1.calculatePrice()+ "(including VAT and service charge)");
					  System.out.println("\nThank you for staying with us!");
			  		b2.assign(n1);
					for(int i = 0; i<pList.size(); i++){

						if (d.equals(pList.get(i).getID())){

							g1.book(n1);
							status = false;
							break;
					}}

				    if(pList.size() == 0 || status){

					   g1.book(n1);
					   pList.add(g1);
				    }
				}
				else{
					String cate = "Foreigner";
					Foreigner n1 = new Foreigner(service_charge2,120.0,g1.getName(),roomType2,"20" + (b2.getRoomNum()+1),cate,g1.getPhoneNum());
					System.out.println("\nYour original room price is: RM" + n1.getPrice());
			  		System.out.println("Your total room price is: RM" + n1.calculatePrice()+ "(including VAT and service charge)");
					System.out.println("\nThank you for staying with us!");
				    b2.assign(n1);
					for(int i = 0; i<pList.size(); i++){

						if (d.equals(pList.get(i).getID())){

							pList.get(i).book(n1);
							status = false;
							break;
					}}

				    if(pList.size() == 0 || status){

					   g1.book(n1);
					   pList.add(g1);
				    }
				}


			  	break;
			   }
			   break;

        	case 2: //If user wants to see the available rooms

                System.out.println("\nAvailable rooms: ");
                System.out.println("\nSingle room: " + b1.getAvailableRoom() + " rooms  available!");
                System.out.println("\nDouble room: " + b2.getAvailableRoom() + " rooms  available!");

                break;



          	case 3:  //in menu 3, show the info for the room booked

          		if(pList.size() == 0){
					System.out.println("Sorry, no rooms have been booked yet!");
				}
				else

					for(int i = 0; i<pList.size(); i++){

						System.out.println("\nPassport No:" + pList.get(i).getID());
						System.out.println("Name: " + pList.get(i).getName());
						System.out.println("Phone number:" + pList.get(i).getPhoneNum());
						System.out.println("Category: " + pList.get(i).getCategoryId());

						pList.get(i).displayInfoRoom();
				}
				break;

          	case 4:
                System.out.println("Thank You..");
                break;
  	      }
  	    System.out.println("\nReturning to main menu...");
  	 	try {
		Thread.sleep(3500);
        } catch (Exception e) {}

  	  }while(choose != 4);
    }
}