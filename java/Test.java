//sg
class Test
{
    static class Val {
        int a;
        Val(int a) {
            this.a = a;
        
        }

        @Override
        public String toString() {
            return Integer.toString(a);
        }

        public void setVal(int a) {
            this.a = a;
        }

    }

    static void randomFun(Val z) {
        z.setVal(42);
    }

    public static void main(String args[]) {
        int a = 4, b = 3;
        Val v = new Val(4);
        System.out.println(v);
        Test.randomFun(v);
        System.out.println(v);
    }

}







