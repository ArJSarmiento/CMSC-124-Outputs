//  Name: Sean Gabriel Bayron
//  Student Number: 2021-04354
//  Name: Arnel Jan Sarmiento
//  Student Number: 2021-05094
//  Date: 2023-4-30
//  This program is a Java Program that demonstrates the use of Inheritance, Encapsulation, Method Overloading and Method Overriding.
//  The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.

public class Main {
    public static void main(String[] args) {
        Dog myDog = new Dog("Bolt", 3);
        myDog.speak();
        myDog.canMakeSound();

        Cat myCat = new Cat("Puss", 2);
        myCat.speak();
        myCat.canMakeSound();
    }
}