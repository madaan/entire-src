//sg
 class UpperClass {
public static class StaticInnerClass {}

public class InnerClass {}

public static void main(String[] args) {
        // works
                 StaticInnerClass stat = new StaticInnerClass();
        //                 // doesn't compile
                                 InnerClass inner = new InnerClass();
                                 }
                                 }
