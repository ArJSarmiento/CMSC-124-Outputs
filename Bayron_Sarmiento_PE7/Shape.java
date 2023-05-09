public abstract class Shape {
    private String color;

    // Constructor with color parameter
    public Shape(String color) {
        this.color = color;
    }

    // Getter for color
    public String getColor() {
        return color;
    }

    // Setter for color
    public void setColor(String color) {
        this.color = color;
    }

    // Abstract method for calculating area
    public abstract double getArea();

    // Method overloading for printing shape details
    public void printDetails() {
        System.out.println("Shape color: " + color);
    }

    public void printDetails(String additionalInfo) {
        System.out.println("Shape color: " + color + ", " + additionalInfo);
    }
}