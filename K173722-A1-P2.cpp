/*
Made by: K173722
Q2
Brute force matching algorithm
*/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

template <typename t>
class Dynamicsafearray{
	
	private:
	t *ptr;
	int size;
	
	public:
	int getsize(){
		return size;
	}	
		
	Dynamicsafearray(){
		ptr=NULL;
		size=0;
	}
	
	Dynamicsafearray(int a){
		size=a;
		ptr=new t[size];
	}
	
    //copy constructor
	Dynamicsafearray(const Dynamicsafearray<t>& obj){
	this->ptr=0;
	this->size=obj.size;
	this->ptr=new t[obj.size];
	memset(this->ptr,0,sizeof(t)*this->size);
	memcpy(this->ptr,obj.ptr,sizeof(t)*obj.size);
	}
	
	Dynamicsafearray& operator=(string s1){
	delete []ptr;
	this->size=strlen(s1.c_str());
	this->ptr=new t[this->size];
	memset(this->ptr,0,sizeof(t)*this->size);
	memcpy(this->ptr,s1.c_str(),sizeof(t)*this->size);
	}

	void output(){ //to display output of array
		for(int i=0;i<size;i++){
			cout<<ptr[i];
		}
	}
	
	string bruteforcematching(Dynamicsafearray<t>& obj){ //this returns a string
	    //c_str() is used as the string fucntions work with char* pointers hence this functions converts them to char pointers
		int count=0,i=0,j=0,k=0;
		string s,s1; //two strings are taken in order to get the maximum match
		while(i!=getsize()){ //because the we are comparing small string with each and every increasing character of larger string hence 'i' will eventually become equal to size
			if(ptr[i]==obj.ptr[j]){ //if corressponding elements are same
				s+=ptr[i]; //this is being appended to the string
				i++;
				j++;
			}
			else{
				if(j-1>-1){ //out of bound checking 
				if(ptr[i]==obj.ptr[j-1]){
					s+='*'; //as the previously matched element is identical hence * is appended onto the string
					i++; 
				}
				else{ //if(ptr[i]!=obj.ptr[j-1])
				if(strlen(s1.c_str())<strlen(s.c_str())){ //to get maximum match out of the two
				s1=s;//if s1<s then overwrite s1 with the newly found sequence
				}
				else { //if(strlen(s1.c_str())>strlen(s.c_str()))
				s=""; //initialize s to get new match
				j=0; //and start comparing from first element of smaller string
			    }
				}
			    }
				else{ //(j-1>-1)
				j=0;
				count++;
				i=count; //the smaller string is now compared with larger string starting from the next index
			    }
			}
	    }
	    if(strlen(s1.c_str())>strlen(s.c_str())){ //to get the maximum match
	    	s=s1;
		}
		
	    return s;
	}
	
	//destructor
	~Dynamicsafearray(){
		if(ptr!=0)
		delete[] ptr;
		ptr=NULL;	
	}
	
};

int main(){
	
	Dynamicsafearray<char> d1,d2;
	string s1,s2,result;	
		
	ifstream infile;
	///*********hardcoded testcase. You can manually input your testcase file name here***************
	infile.open("input2.txt"); 
	
	if(!infile){ 
	cout<<"\nfile not found\n";
	exit(0);
	}
	
	infile>>s1; //taking input from file
	infile>>s2;
	
	infile.close();
	
	d1=s1; //operator overloading comes to use
	d2=s2;
	
	if(d1.getsize()>d2.getsize()) //condition to ensure that the larger string is compared with the smaller one
    result=d1.bruteforcematching(d2); 
    else 
    result=d2.bruteforcematching(d1);
    
    fstream file;
	file.open("outputA1P2.txt",ios::out|ios::trunc);
	file<<result;	
	
}
