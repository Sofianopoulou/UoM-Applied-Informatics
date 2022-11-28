import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("Welcome to the simplified blackjack game!");
		
		// Player's first 2 cards
		Card card1 = new Card();
		Card card2 = new Card();
		
		System.out.println("You get a " + card1.getCard() + " and " + card2.getCard() + ".");
		int Players_total = card1.getCard() + card2.getCard();
		System.out.println("Your total is " + Players_total + ".");
		
		
		//Dealer's first 2 cards
		Card card3 = new Card();
		Card card4 = new Card();
		int Dealers_total = card3.getCard() + card4.getCard();
		System.out.println("\nThe dealer has a " + card3.getCard() + " showing, and a hidden card.\n");
		

		//Player is playing
		boolean loop = true;
		while(loop && Players_total<=21) {
			System.out.println("Would you like to “hit” or “stay”? ");
			String reply = scanner.nextLine();
			
			if(reply.equals("hit") && Players_total<=21)
			{
				Card extra_card = new Card();
				Players_total += extra_card.getCard();
				
				System.out.println("You drew a " + extra_card.getCard());
				System.out.println("Your total is " + Players_total + ".\n");
			} else { loop=false; }
		}
		
		
		if ( Players_total <= 21) 
		{
			
			//Dealer is playing
			System.out.println("OK, dealer is playing.");
			System.out.println("His hidden card was " + card4.getCard() + ".");
			System.out.println("His total is " + Dealers_total + ".\n");
		
			while(Dealers_total<=16) {
				System.out.println("Dealer chooses to hit. \n");
				Card extra_card = new Card();
				Dealers_total += extra_card.getCard();
				System.out.println("He draws a " + extra_card.getCard() + ".");
				System.out.println("His total is " + Dealers_total);
			}
			System.out.println("Dealer stays.\n");
		
			System.out.println("Dealer total is " + Dealers_total + ".");
			System.out.println("Your total is " + Players_total + ".");
        
		}
		
        
        //Who wins?
        if(Players_total > 21) { System.out.println("\nDEALER WINS!"); }
        if(Players_total <= 21 && Dealers_total > 21) { System.out.println("\nPLAYER WINS!"); }
        if(Players_total > Dealers_total && Players_total <= 21) { System.out.println("\nPLAYER WINS!"); }
        if(Dealers_total >= Players_total && Dealers_total<=21 && Players_total <=21) { System.out.println("\nDEALER WINS!"); }

        
        scanner.close();
        
        }
}