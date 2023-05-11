public class Animal {
    private String name;
    private int age;

    public Animal(String name, int age){
        this.name = name;
        this.age = age;
    }

    public String getName(){
        return name;
    }

    public void setage(int age){
        this.age = age;
    }

    public int getAge(){
        return age;
    }

    public void setName(String name){
        this.name = name;
    }

    public void printDetails(){
        System.out.println("Animal name: " + name + ", age: " + age);
    }

    public void speak() {
        System.out.println("Animal speaking...");
    }

    public void canMakeSound() {
        System.out.println("The animal can make a sound");
    }
}