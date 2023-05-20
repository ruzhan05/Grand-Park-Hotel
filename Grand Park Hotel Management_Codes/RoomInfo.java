

public class RoomInfo
{

  private Room[] Guestlist; 
  private int listNum;


public RoomInfo()//constructor class RoomInfo
{

	Guestlist = new Room[35];
}
public void assign(Room tk)
{
	Guestlist[listNum] = tk;
	listNum++;
}
public int getAvailableRoom()
{
	return (32 - listNum);
}

public int getRoomNum(){
	return 	listNum;
}




}

