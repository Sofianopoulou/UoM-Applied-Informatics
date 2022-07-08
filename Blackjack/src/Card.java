import java.util.Random;

public class Card {
	
	int card;
	
	public Card() {
		Random random = new Random();
		card = random.nextInt(10) + 2;
	}
	
	public int getCard() {
		return card;
	}
}

