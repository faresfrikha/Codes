import java.util.Scanner;
import java.util.*;
public class lol {
	
	public static final double FAVNUMBER =1.56654;
	
	private String name;
	private int weight;
	private boolean  hasOwner=false;
	
	private byte age ;
	private  long uniqueID;
	private  char  character;
	private double  speed;
	private float height;
	
	protected static  int numberOfAnimals =0;
	static Scanner  userinput= new Scanner(System.in);
	
	
	public lol() {
		numberOfAnimals++;
		System.out.println("5+1="+(5+1));
		if(userinput.hasNextLine()) {
			this.setName(userinput.nextLine());
		}
		this.setCharacter(character);
		this.setUniqueID();
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public int getWeight() {
		return weight;
	}


	public void setWeight(int weight) {
		this.weight = weight;
	}


	public boolean isHasOwner() {
		return hasOwner;
	}


	public void setHasOwner(boolean hasOwner) {
		this.hasOwner = hasOwner;
	}


	public byte getAge() {
		return age;
	}


	public void setAge(byte age) {
		this.age = age;
	}


	public long getUniqueID() {
		return uniqueID;
	}


	public void setUniqueID(long uniqueID) {
		this.uniqueID = uniqueID;
		System.out.println("this unique id = "+this.uniqueID);
	}
	public void setUniqueID() {
		long minNumber=1;
		long maxNumber=100000;
		this.uniqueID =  minNumber +(long) (Math.random()*((maxNumber-minNumber)+1));
		String stringNumber =Long.toString(maxNumber);
		int numberString =Integer.parseInt("542");
		System.out.println("this unique id = "+this.uniqueID);
	}


	public char getCharacter() {
		return character;
	}


	public void setCharacter(char character) {
		this.character = character;
	}


	public double getSpeed() {
		return speed;
	}


	public void setSpeed(double speed) {
		this.speed = speed;
	}


	public float getHeight() {
		return height;
	}


	public void setHeight(float height) {
		this.height = height;
	}
	
	protected static  void  countTo(int startingNumber) {
		for(int i=startingNumber;i<=100;i++) {
			if(i==90)continue;
			System.out.println(i);
		}
	}
	
	protected static String printNumbers(int maxNumbers) {
		int i=1;
		while(i<(maxNumbers/2)) {
			System.out.println(i);i++;
			if(i==(maxNumbers/2))break;
		}
		lol.countTo(maxNumbers/2);
		return "END";
	}
	
	/*do {
		System.out.println("give a number : ");
		while(!userinput.hasNextInt()) {
			String numberentered =userinput.next();
			System.out.println("%s is not a number\n",numberentered);
		}
	}*/
	
	public String makeSound() {
		return "Greee";
	}
	public static  void speakAnimal(lol randanimal) {
		System.out.println("animal says "+ 	randanimal.makeSound());
	}

	public static void main(String[] args) {
	
		lol animal = new lol();
		
		int[] fav;
		fav=new int[20];
		fav[0]=100;
		String[] stringArray= {"list","rol"};
		
		String[]  clone =Arrays.copyOf(stringArray,3);
		System.out.println(Arrays.toString(clone));
		System.out.println(Array.binarySearch(clone,"random"));
		
	}

}
