class Numbers
{
    public static boolean isNum(int num)
    {
        boolean returnValue;

        returnValue = false;

        if(num >= 0 && num < 10)
        {
            returnValue = true;
        }
        return returnValue;
    }

    public static void main (String [] args)
    {   
        int input; //numbers entered by user
        int numCount = 0; //numbers less than 10
        int index;
        boolean result;
        int a[] = {1,2,11,12};
        System.out.print("How many numbers to test? ");
        String lessThanTen = "";
        for(index = 0; index < a.length; index++ )
        {
            System.out.println("Enter a number ");
            result = isNum(a[index]);
            if(result == true)
            {
                lessThanTen = lessThanTen + "  " +  Integer.toString(a[index]);
                numCount++;
            }
        }

        System.out.println("Total numbers below 10 is :" + lessThanTen);    

    }
}
