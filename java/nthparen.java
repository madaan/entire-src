//sg
class nthparen {
    public static void main(String args[]) {
        System.out.println(genNthBalParStr(100, 12000000000l));
    }
public static String genNthBalParStr(int numPairs, long N) {
  long q, p, c, c1, m;
  String str = "";
  q = numPairs;
  m = p = c = 1;
  while  (p < numPairs)  {
    p = p + 1;
    c = ((4 * p - 2) * c)/(p + 1);
  }
  N = c - (N - 1);
  while  (true)  {
    if  (q != 0)  {
      c1 = ((q + 1) * (q - p) * c)/((q + p) * (q - p + 1));
      if  (N > c1)  {
        p = p - 1;
        c = c - c1; 
        N = N - c1;
        str += "(";
        m = m + 1;
      }
      else {
        q = q - 1;
        c = c1;
        str += ")";
        m = m + 1;
      }
    }
    else break;
  }
  return str;
}
}
