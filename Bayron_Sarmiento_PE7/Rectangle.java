public class Rectangle extends Shape {
    private double width;
    private double height;

    // Constructor with color, width, and height parameters
    public Rectangle(String color, double width, double height) {
        super(color);
        this.width = width;
        this.height = height;
    }

    // Getter for width
    public double getWidth() {
        return width;
    }

    // Setter for width
    public void setWidth(double width) {
        this.width = width;
    }

    // Getter for height
    public double getHeight() {
        return height;
    }

    // Setter for height
    public void setHeight(double height) {
        this.height = height;
    }

    // Overriding getArea method from Shape class
    @Override
    public double getArea() {
        return width * height;
    }

    // Overriding printDetails method from Shape class
    @Override
    public void printDetails() {
        super.printDetails("Rectangle width: " + width + ", height: " + height);
    }
}
