public class Bird extends Animal {
    public Bird(String name, int age) {
        super(name, age);
    }

    // Method Overloading
    public void speak() {
        System.out.println("Tweet tweet!");
    }

    // Method Overriding
    public void canMakeSound() {
        System.out.println("Yes, I can tweet");
    }
}