public class Circle extends Shape {
    private double radius;

    // Constructor with color and radius parameters
    public Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }

    // Getter for radius
    public double getRadius() {
        return radius;
    }

    // Setter for radius
    public void setRadius(double radius) {
        this.radius = radius;
    }

    // Overriding getArea method from Shape class
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    // Overriding printDetails method from Shape class
    @Override
    public void printDetails() {
        super.printDetails("Circle radius: " + radius);
    }
}