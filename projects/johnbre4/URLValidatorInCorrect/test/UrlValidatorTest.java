

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testUrl(String url) {
	   
	   //UrlValidator validator =  new UrlValidator();
	   if(true) {
		   String[] schemes = {"http","https"};
		   UrlValidator validator = new UrlValidator(schemes, UrlValidator.ALLOW_ALL_SCHEMES);
		   boolean urlIsValid = validator.isValid(url);
		   System.out.println(url + ": " + urlIsValid);
	   }
   }

   public void testManualTest()
   {
//You can use this function to implement your manual testing
 
   
	   testUrl("http://www.oregonstate.edu");
	   testUrl("http://www.google.com");
	   testUrl("www.google.ai");
	   testUrl("http://www.oregonstate.edu");
	   testUrl("www.amazon.com");
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing
	   System.out.println("First Partition");
	   testUrl("http://www.oregonstate.edu");
	   testUrl("https://www.oregonstate.edu");
	   testUrl("ttp://www.oregonstate.edu");
	   testUrl("httP://www.oregonstate.edu");
	   testUrl("htswfs://www.oregonstate.edu");
	   testUrl("h_://www.oregonstate.edu");
	   testUrl("-ttp://www.oregonstate.edu");
	   testUrl("abc://www.oregonstate.edu");
	   testUrl("htttp://www.oregonstate.edu");
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing
	   System.out.println("Second Partition");
	   testUrl("http//www.oregonstate.edu");
	   testUrl("http::www.oregonstate.edu");
	   testUrl("http:/www.oregonstate.edu");
	   testUrl("http:www.oregonstate.edu");


   }
   //You need to create more test cases for your Partitions if you need to 

   public void testYourOtherPartitions(){
		 //You can use this function to implement your Second Partition testing	
	   System.out.println("Host Partition");
	   testUrl("http://Www.oregonstate.edu");
	   testUrl("http://ww2.oregonstate.edu");
	   testUrl("http://@www.oregonstate.edu");
	   testUrl("http://ww&.oregonstate.edu");
	   testUrl("http://ww?.oregonstate.edu");
	   testUrl("http://1ww.oregonstate.edu");
	   	   
	   System.out.println("Domain Partition");
	   testUrl("Fdasfdsa.wesw");
	   testUrl("http://sdafdfasd.weasdfs");
	   testUrl("http://www.Abc.com");
	   testUrl("http://www.fdsa2.com");
	   testUrl("http://www.fe$as.com");
	   testUrl("http://www.goo&le.com");
	   testUrl("http://www.goo?le.com");
	   testUrl("http://www.oregon state.edu");
	   
	   System.out.println("TLD Partition");
	   testUrl("http://www.google.c&m");
	   testUrl("http://www.google.c?m");
	   testUrl("http://www.google..com");   // two .. at the end
	   testUrl("http://www.google.ac");  // first country code alphabetically
	   testUrl("http://www.google.zw");  // last country code alphabetically
	   testUrl("http://www.google.acadamy");  // first ICANN alphabetically
	   testUrl("http://www.google.zone");  // last ICANN alphabetically (sticking with English languages)
	   testUrl("http://www.google.c om");
	   
	   System.out.println("Port Partition");
	   testUrl("http://www.google.com:80");
	   testUrl("http://www.google.com:ABC");
	   testUrl("http://www.google.com:8!");
	   testUrl("http://www.google.com:8080");
	   testUrl("http://www.google.com:29000");
	   testUrl("http://www.google.com:96000");
	   
	   System.out.println("Querystring Partition");
	   testUrl("http://www.google.com:80?fruit=apple");
	   testUrl("http://www.google.com:80?fruit=apple&cost=1");
	   testUrl("http://www.google.com:80?fruit=apple?cost=1");
	   testUrl("http://www.google.com:80&fruit=apple");
	   
	   System.out.println("Querystring Partition");
	   testUrl("http://128.193.4.112");
	   testUrl("http://300.193.4.112");
	   testUrl("http://128.300.4.112");
	   testUrl("http://128.193.300.112");
	   testUrl("http://128.193.4.300");
	   


   }
 
   
   
public void testIsValid()
   {
	   //You can use this function for programming based testing
	   System.out.println("Programming Based Testing");
	   String[] testUrlScheme = new String[5];
	   testUrlScheme[0] = "http://";
	   testUrlScheme[1] = "http:/";
	   testUrlScheme[2] = "https:";
	   testUrlScheme[3] = "htswfs:";
	   testUrlScheme[4] = "abc:/";
	   
	   String[] testUrlAuthority = new String[5];
	   testUrlAuthority[0] = "www.google.com";
	   testUrlAuthority[1] = "www.oregonstate.edu";
	   testUrlAuthority[2] = "255.255.255.255";
	   testUrlAuthority[3] = "256.256.256.256";
	   testUrlAuthority[4] = "go.a";
	   
	   String[] testUrlPort = new String[5];
	   testUrlPort[0] = ":80";
	   testUrlPort[1] = ":-1";
	   testUrlPort[2] = "";
	   testUrlPort[3] = ":65a";
	   testUrlPort[4] = ":65535";
	   
	   String[] testUrlPathOptions = new String[4];
	   testUrlPathOptions[0] = "/test";
	   testUrlPathOptions[1] = "";
	   testUrlPathOptions[2] = "/../212";
	   testUrlPathOptions[3] = "/$123";
	   
	   String[] testUrlQuery = new String[3];
	   testUrlQuery[0] = "?test";
	   testUrlQuery[1] = "";
	   testUrlQuery[2] = "?action=view";
	   
	   for (int i = 0; i < 5; i++)
	   {
		   for (int j = 0; j < 5; j++)
		   {
			   for (int k = 0; k < 5; k++)
			   {
				   for (int m = 0; m < 4; m++)
				   {
					   for (int n = 0; n < 3; n++)
					   {
						   String completeURL = testUrlScheme[i] + testUrlAuthority[j] + testUrlPort[k] + testUrlPathOptions[m] + testUrlQuery[n];
						   testUrl(completeURL);
					   }
				   }
				   
			   }
			
		   }
		   
	   }	   
	   
   }
   


}
