
public class lel extends lol{
	
	public lel() {
		
	}
	public String makeSound() {
		return "meow";
	}
	
	public static void main(String[] args) {
		lol fido =new lel();
		lol fluffy = new other();
		
		lol[] theAnimals =new lol [10];
		theAnimals[0]=fido;
		theAnimals[1]=fluffy;
		System.out.println("fido says "+ theAnimals[0].makeSound());
		System.out.println("fluffy says "+ theAnimals[1].makeSound());
	}
}
