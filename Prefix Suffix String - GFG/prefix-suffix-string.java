//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;

public class code1 
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            String s1[]=in.readLine().trim().split(" ");
            String s2[]=in.readLine().trim().split(" ");

            Solution ob=new Solution();
            int ans=ob.prefixSuffixString(s1,s2);
            out.println(ans);

        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
    public int prefixSuffixString(String s1[],String s2[])
    {
        int count=0;
        
        for(int i=0;i<s2.length;i++){
            String prepost=s2[i];
            for(int j=0;j<s1.length;j++){
                String word=s1[j];
                if(word.length()>=prepost.length() && check(word,prepost)){
                    count++;
                    break;
                }
            }
        }
        return count;
 
    }
    public boolean check(String word,String prepost){
            int m=word.length();
            int n=prepost.length();
            boolean flag1=true;
            
            for(int i=0;i<n;i++){
                if(word.charAt(i)!=prepost.charAt(i)){
                    flag1=false;
                }
            }
            boolean flag2=true;
            for(int i=n-1,j=m-1;i>=0;i--,j--){
                if(word.charAt(j)!=prepost.charAt(i)){
                    flag2=false;
                }
            }
            return (flag1||flag2);
    }
}