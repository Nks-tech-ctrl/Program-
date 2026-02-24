class Emp {
    String name;
    double baseSalary;

    Emp(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }

    double calculateSalary() {
        return baseSalary;
    }
}

class Manager extends Emp {
    double bonus;

    Manager(String name, double baseSalary, double bonus) {
        super(name, baseSalary);
        this.bonus = bonus;
    }

    double calculateSalary() {
        return baseSalary + bonus;
    }
}

class Programmer extends Emp {
    int otHours;
    double otRate;

    Programmer(String name, double baseSalary, int otHours, double otRate) {
        super(name, baseSalary);
        this.otHours = otHours;
        this.otRate = otRate;
    }

    double calculateSalary() {
        return baseSalary + (otHours * otRate);
    }
}

public class Employee{
    public static void main(String args[]) {

        Manager m = new Manager("Rahul", 50000, 10000);
        Programmer p = new Programmer("Amit", 40000, 10, 500);

        System.out.println("Manager Salary: " + m.calculateSalary());
        System.out.println("Programmer Salary: " + p.calculateSalary());
    }
}