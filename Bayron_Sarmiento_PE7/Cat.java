public class Cat extends Animal {
    public Cat(String name, int age) {
        super(name, age);
    }

    // Method Overloading
    public void speak() {
        System.out.println("Meow meow!");
    }

    // Method Overriding
    public void canMakeSound() {
        System.out.println("Yes, I can meow");
    }
}