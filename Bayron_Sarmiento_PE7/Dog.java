public class Dog extends Animal {
    public Dog(String name, int age) {
        super(name, age);
    }

    // Method Overloading
    public void speak() {
        System.out.println("Woof woof!");
    }

    // Method Overriding
    public void canMakeSound() {
        System.out.println("Yes, I can woof");
    }
}