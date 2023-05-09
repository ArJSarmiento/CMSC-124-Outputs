public class Main {
    public static void main(String[] args) {
        Circle circle = new Circle("red", 5.0);
        Rectangle rectangle = new Rectangle("blue", 10.0, 20.0);

        circle.printDetails();
        rectangle.printDetails();

        System.out.println("Circle area: " + circle.getArea());
        System.out.println("Rectangle area: " + rectangle.getArea());
    }
}