#include<iostream>
#include<math.h>
using namespace std;
int getSize(long long d){
    //d=abs(d);
    if(d==0) 
    return 0;
    int count =0; 
    while (d>0) // keep dividing the number by 10 and every time you successfully divide , we count one of its digits
    {
    d=d/10;
    count++;
    }
    return count;
}
int getDigit(int number){
    if (number<10){
 return number;
    }
    else
    return (number/10)+(number%10); //we sum the digit in the tens position and that in the ones
}
int sumofOddPlace(long long number){
    int position =1;  // initialise the first position from the right to be in position 1
    int sum =0;
    while (number>0){
        int digit =number%10; //extract the last digit
        if(position%2 != 0){ //condition for odd position
            sum += digit;
        }
        number=number/10;
        position++;
    }
    return sum;
}
int sumOfDoubleEvenPlace(long long number){
     int position =1;
    int sum =0;
    while (number>0){
        int digit =number%10;
        if(position%2 == 0){
         sum += getDigit(digit*2); //double the digits in even place and then call getDigit to find the digit that will be summed
        }
        number=number/10;
        position++;
    }
return sum;
}
long long getPrefix(long long number,int k){//will return the first k digits of number
    int size= getSize(number);//gives us the number of digits of number
    if(size<=k){
        return number;
    }
    else {
       return number/ pow(10,size-k);
        }
       
}
bool prefixMatched (long long number,int d){ //compares the prefix got in the function getPrefix and the specified number
    int k=getSize(d);
    return getPrefix(number,k)==d;
}
bool isValid(long long number){
    int size=getSize(number);
    bool validLength= (size>=13&&size<=16);//checks length
    bool validPrefix= (prefixMatched(number,4)||prefixMatched(number,5)||prefixMatched(number,6)||prefixMatched(number,37));//checks prefix
    int total= sumOfDoubleEvenPlace(number)+sumofOddPlace(number); // calculates checksum
    bool validChecksum=(total%10==0);//checks if checksum is divisibe by 10
    return validLength&&validChecksum&&validPrefix;
}    
int main(){
    long long cardnumber;
    cout<<"Enter a credit card number(add LL at the end): ";
    cin>>cardnumber;
    if (isValid(cardnumber)==1){
        cout<<"The number "<<cardnumber<<" is valid" ;
    } 
    else{
        cout<<"The number "<<cardnumber<<" is invalid" ;
    }
   
    return 0;
}
