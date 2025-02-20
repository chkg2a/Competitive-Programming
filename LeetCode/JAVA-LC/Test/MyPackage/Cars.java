package MyPackage;

interface Vehicle {
    void start();
    void stop();
}

public class Cars implements Vehicle {
    @Override
    public void start() {
        System.out.println("Car is starting");
        New newobj = new New();
        newobj.bro();
    }

    @Override
    public void stop() {
        System.out.println("Car is stopping");
    }
}
