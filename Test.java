import java.util.*;
public class Test 
{
public static void main(String args[])
{
    int[]x={1,7,-5,-12,-13,99,-6,31,15};
    int p=0;
    for(int i=x.length-1;i>p;)
    {
        if(x[i]<0)
        {
            int j=i;
            while(j!=0)
            {
            int t=x[j];
            x[j]=x[j-1];
            x[j-1]=t;//交换
            j--;
            }
            p++;
        }
        else i--;
    }
    System.out.println(Arrays.toString(x));
}
}
