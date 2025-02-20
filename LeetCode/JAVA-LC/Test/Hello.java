public class Hello {
  static void swapped(int [] arr){
    //n = n + n2;
    //n2 = n - n2;
    //n = n - n2;
    arr[0] ^= arr[1];
    arr[1] ^= arr[0];
    arr[0] ^= arr[1];
  }
  public static void main(String[] args) {
    int[] a = {10,50};
    System.out.print(a[0] + " " + a[1] + '\n');
    swapped(a);
    System.out.print(a[0] + " " + a[1]);
  }
}
