public class test {
    public static void evensLeft(int[] array) {
        int j = array.length-1;
        int h = 0;
        int[] newArray= new int[array.length];
        System.arraycopy(array, 0, newArray, 0, array.length);
        for (int k = 0; k < newArray.length; k++) {
            if(newArray[k]%2==0) {
                array[h]=newArray[k];
                h++;
            } else {
                array[j]=newArray[k];
                j--;
            }
        }
    }
    public static void main(String[] args) {
        int a[] = {1,2,3,4,5};
        evensLeft(a);
        for(int i = 0; i < 5; i++) {
            System.out.println(a[i]);
        }

    }
}
