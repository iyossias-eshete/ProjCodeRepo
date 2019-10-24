//This is a Phone book Application Written by Iyossias Getachew Nesanet Gamero and Tensae Negussie
//It allows users to Permanently save contacts and also to modify,add,delete and search contacts
//It stores basic info about a person that is their title,name,gender,and phone number
//Some of the codes are commented because they dont function on code blocks if you are using turbo the you should use those alternatives


#include<fstream>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;

enum cases { ADD = 1,DELETE, SEARCH , VIEW, MODIFY};


struct  cont{
long phoneNo;
char fName[15];
char lName[15];
char title[15];
char gender;
};



const cont blankcontact={0000000000 ,'x' ,'x' , 'x' , 'x'};// used for deleting

void view(cont *&,long);
void load(long &,cont *&);
void deleteContact(long &,cont *&,long &);
void modifyContact(long &,cont *&,long &);
int searchContact(long,cont *&,long &);


void load(long &n,cont *&allcontact)
{

long size;//To hold the actual size of the file
fstream fout("Contacts.bin",ios::binary|ios::app);
fout.seekg(0,ios::end);
size=fout.tellg();
n=size/sizeof(cont);
fout.seekg(0);

      if(n%10 != 0)
        size=n+10-(n%10);

allcontact=new (nothrow) cont [size];

int i=0;
ifstream fin("Contacts.bin",ios::binary);//used to read contacts from the binary and store then in a cont struct variable
/*
uncomment me if using turbo
fstream reload("ContactsTemp.bin",ios::binary | | ios::in | ios::out); //To act as a temporary storage for contact
*/

while(!fin.eof())
    {

       fin.read((char *)& allcontact[i],sizeof(cont));
    cout<<".................Loading................."<<endl;//To prompt the user incase the loading process  becomes time taking
        i++;
     /*Comment the uncommented statements in the while loop and uncomment the commented statements if you are using turbo
     fin.read((char *)& allcontact[i],sizeof(cont));
if((allcontact[i].title==blankcontact.title) && (allcontact[i].fName==blankcontact.fName)&& (allcontact[i].lName==blankcontact.lName) && (allcontact[i].gender==blankcontact.gender) &&(allcontact[i].phoneNo==blankcontact.phoneNo))
    {
    i++
    continue;
    }
else
    {
    reload.write((char *)& allcontact[index],sizeof(cont));
    i++;
    }
     */
    }

fin.close();
/*uncomment me if you are using turbo
delete []allcontact;
reload.seekg(0,ios::end);
size=fout.tellg();
n=size/sizeof(cont);
fout.seekg(0);

      if(n%10 != 0)
        size=n+10-(n%10);

allcontact=new (nothrow) cont [size];
i=0;
while(!reload.eof())
{
reload.read((char *)& allcontact[i],sizeof(cont));
i++;
}
reload.close();
fstream replace("Contact.bin",ios::binary | ios::in | ios::out);//To write the temp into contact binary file by replacing everything
for(long j=0;j<i;j++)
{
replace.write((char *)& allcontact[j],sizeof(cont));
}
replace.close();
*/
cout<<".............Loading Complete............\n";
system("cls");
fout.close();
}

void add(long &n,cont *&allcontact)
{
   cont *temp,contact;

    temp =new (nothrow) cont [n+10];//For temporary storage so that the size of allcontact can be increased without loss of data

   for(long i=0;i<n;i++)
    {
    temp[i]=allcontact[i];
    }

   delete [] allcontact;
   allcontact=temp;//Reassigning allcontacts

   ofstream out("Contacts.bin",ios::binary|ios::app);// To write the added contact(s) to the binary file
   char yesNo;//For storing the users response to go again

   do{
    cout<<"Title["<<n+1<<"]:\n";
    cin>>contact.title;
    cout<<"FIRSTNAME["<<n+1<<"]:\n";
    cin>>contact.fName;
    cout<<"LASTNAME["<<n+1<<"]:\n";
    cin>>contact.lName;
    cout<<"GENDER["<<n+1<<"]:\n";
    cin>>contact.gender;
    cout<<"PHONENUMBER["<<n+1<<"]:\n";
    cin>>contact.phoneNo;
    allcontact[n]=contact;
    n++;
    out.write((char *)& contact,sizeof(contact));//writes the added contact to binary file

    if(n%10!=0)
    {
    //Only prompts the user to go again if there is enough space
    cout<<"\nPress y or Y to Add again?\n";
    cin>>yesNo;
    }

    }
    while((yesNo=='y' || yesNo=='Y') && n%10!=0);
    out.close();
}

void view(cont *&allcontact,long n)

{
    // view displays contacts from the cont allcontact data type
    system("cls");
    std::cout<<"\n\nNo"
             <<std::setw(14)<<"Title\t"
             <<std::setw(15)<<"First Name\t"
             <<std::setw(14)<<"Last Name\t"
             <<std::setw(10)<<"Gender\t"
             <<std::setw(16)<<"Phone Number\n";


    for(long i=0;i<n;i++)
        {

             std::cout<<"\n"
             <<std::setw(2)<<i+1
             <<std::setw(13)<<allcontact[i].title
             <<std::setw(15)<<allcontact[i].fName
             <<std::setw(15)<<allcontact[i].lName
             <<std::setw(12)<<allcontact[i].gender
             <<std::setw(21)<<allcontact[i].phoneNo<<endl;


    }

}


int searchContact(long n,cont *&allcontact,long &index)
{
	system("cls");
	int sf=0;//Used for search result if found or not
	cout<<"\nNote that our search is case sensitive.\nSo please enter the contacts information carefully.";
	string Fname,Lname;//used to accept the names of the contact
	cout<<"\nPlease enter the First name of the person you are looking for.\n";
	cin>>Fname;
	cout<<"\nPlease enter the Last name of the person you are looking for.\n";
	cin>>Lname;
	system("cls");
	std::cout<<"\n\nNo"
             <<std::setw(14)<<"Title\t"
             <<std::setw(15)<<"First Name\t"
             <<std::setw(14)<<"Last Name\t"
             <<std::setw(10)<<"Gender\t"
             <<std::setw(16)<<"Phone Number\n";
    for(long i=0;i<n;i++){
    	if(allcontact[i].fName==Fname && allcontact[i].lName==Lname){
    index=i;
    	std::cout<<"\n"
             <<std::setw(2)<<i+1
             <<std::setw(13)<<allcontact[i].title
             <<std::setw(15)<<allcontact[i].fName
             <<std::setw(15)<<allcontact[i].lName
             <<std::setw(12)<<allcontact[i].gender
             <<std::setw(21)<<allcontact[i].phoneNo<<endl;
		     sf=1;
	}
	if(sf==0 && i==n-1)
	{
	system("cls");
	cout<<"\nSorry sir the contact you entered doesn't seem to appear on our list\n";
	}
	}
	return sf;
}

void deleteContact(long &n,cont *&allcontact,long &index)
{
    system("cls");
    int option;
    int found=1;//If the result is found or not.Stores the value returned from search
    deleteoption://To trap the user from choosing an option thats not on the list
    cout<<"Press 1 to search and delete\n";
    cout<<"Press 2 to Delete using index(No)\n";
    cout<<"Press 3 to go back\n";
    cin>>option;
    if(option == 1)
    {
        found=searchContact(n,allcontact,index);

        if(found==0)
        {
          goto deleteoption;
        }
    }
    else if(option == 2)
    {

        cout<<"Enter the index(No) of the contact you would like to delete\n";
        cin>>index;
        index=index-1;//Because the index is stored staring from 0 on the computer but viewed from 1 for the user

        if(index > n)
        {
          cout<<"The index You entered doesnt exist\n";
          goto deleteoption;
        }
    }
    else if(option == 3)
    {
        return ;
    }
    else
    {
        cout<<"Wrong option!!!\n";
        goto deleteoption;
    }


       if(found){
       for(int j=index;j<n-1;j++){

            allcontact[j]=allcontact[j+1];//To replace the deleted contact with the next n the next with its next and so on
            //This replaces the deleted contact with the next contact makes a final two copy of the same contact
                               }

      n=n-1;//To reduce the number of contacts by 1 since a contact is deleted
      ofstream rewrite("Contacts.bin",ios::binary|ios::out);//To remove the content so that it may be rewritten without the deleted contact
      rewrite.seekp(0);
      for(long i=0;i<n;i++)
      {
       rewrite.write((char *)& allcontact[i],sizeof(allcontact[i]));//To write every contact except the last one that is where the delete contact is copied using the for loop above
      }
      rewrite.close();
      load(n,allcontact);//To reload after deletion so that the delete contact can be removed from the memory(allcontact) as well
            /*comment everything under the if(found) statement and uncomment this commented statements if you are using turbo
            allcontact[index]=blankcontact;
            ofstream del("Contacts.bin",ios::binary|ios::out |ios::app);
            del.seekp(0,(index)*sizeof(cont));
            del.write((char *)& allcontact[index],sizeof(cont));
            del.close;
            load(n,allcontact);
             */
            }



}

void modifyContact(long &n,cont *&allcontact,long &index)
{
    system("cls");
    int option;
    int found=1;//If the result is found or not.Stores the value returned from search
    modifyoption://To trap the user from choosing an option thats not on the list
    cout<<"Press 1 to search and modify\n";
    cout<<"Press 2 to modify using index(No)\n";
    cout<<"Press 3 to go back\n";
    cin>>option;
    if(option == 1)
    {
        found=searchContact(n,allcontact,index);

        if(found==0)
        {
          goto modifyoption;
        }
    }
    else if(option == 2)
    {

        cout<<"Enter the index(No) of the contact you would like to modify\n";
        cin>>index;
        index=index-1;//Because the index is stored staring from 0 on the computer but viewed from 1 for the user

        if(index > n)
        {
          cout<<"The index You entered doesnt exist\n";
          goto modifyoption;
        }
    }
    else if(option == 3)
    {
        return ;
    }
    else
    {
        cout<<"Wrong option!!!\n";
        goto modifyoption;
    }
     if(found)
     {
    cout<<"Title["<<index+1<<"]:\n";
    cin>>allcontact[index].title;
    cout<<"FIRSTNAME["<<index+1<<"]:\n";
    cin>>allcontact[index].fName;
    cout<<"LASTNAME["<<index+1<<"]:\n";
    cin>>allcontact[index].lName;
    cout<<"GENDER["<<index+1<<"]:\n";
    cin>>allcontact[index].gender;
    cout<<"PHONENUMBER["<<index+1<<"]:\n";
    cin>>allcontact[index].phoneNo;

     ofstream rewrite("Contacts.bin",ios::binary|ios::out);//To truncate its content so that the modified version can be rewritten
      rewrite.seekp(0);
      for(long i=0;i<n;i++)
      {
       rewrite.write((char *)& allcontact[i],sizeof(allcontact[i]));//Writing the modified version
      }
      rewrite.close();

      /*comment everything under the if(found) statement and uncomment this commented statements if you are using turbo
            ofstream rep("Contacts.bin",ios::binary|ios::out |ios::app);
            rep.seekp(0,(index)*sizeof(cont));
            rep.write((char *)& allcontact[index],sizeof(cont));
            rep.close;
             */
     }


}


int main()
{
    cont *allcontact;
    long n=1;
    long index;
    char yesNo;
    load(n,allcontact);
    int option;
    char yes_no;
    do{
    system("cls");
	cout<<"PhoneBook \n";
    cout<<endl;
    cout<<"1.ADD     ..............................   Press 1\n";
    cout<<"2.DELETE  ..............................   Press 2\n";
    cout<<"3.SEARCH  ..............................   Press 3\n";
    cout<<"4.VIEW    ..............................   Press 4\n";
    cout<<"5.MODIFY  ..............................   Press 5\n";
    cout<<"6.Exit    ..............................   Press 6 or any key\n";
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tBY:\n\t\t\t\t\t\t\t1.Iyossias Getachew \n\t\t\t\t\t\t\t2.Neshanet Gamero \n\t\t\t\t\t\t\t3.Tensae Negussie \n\n\n";
    cin>>option;

    switch(option)
    {

    case ADD:add(n,allcontact);
	break;
	case DELETE:deleteContact(n,allcontact,index);
	break;
	case SEARCH:searchContact(n,allcontact,index);
	break;
	case VIEW:view(allcontact,n);
	break;
    case MODIFY:modifyContact(n,allcontact,index);
    break;
    default: return 0 ;
    break;
    }
    cout<<"\nPress 'y' or 'Y' to go to menu\n";
    cin>>yes_no;
    }
    while (yes_no=='Y' || yes_no=='y');
    cout<<"\n\n\t\t\t\t\t\tBY:\n\t\t\t\t\t\tIyossias Getachew\n\t\t\t\t\t\tNesanet Gamerot\n\t\t\t\t\t\tTensae Negussie\n";

    }



