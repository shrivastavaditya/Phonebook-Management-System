#include<iostream>
#include<fstream>
#include<sstream>
#include<stack>
using namespace std;

 
class node{
    public:
    string name;
    string phone_number;
    string email;
    string address;
    node*next;
    node*prev;
    node(){
        next=NULL;
        prev=NULL;
    }
};

stack<node*> st;


class phoneBook{
    public:
    node*head;
    string a;
    string x;
    string b;
    string c;

    phoneBook()
    {
        head=NULL;
        a="";
        x="";
        b="";
        c="";
    }

    void addContact()
    {
        if(head==NULL)
        {
            node * n= new node;
            cout<<"Name of the Person: ";
            cin>>a;
            n->name=a;
            
            cout<<"Enter Contact Number: ";
            cin>>x;
            n->phone_number=x;

            cout<<"Enter email: ";
            cin>>b;
            n->email=b;

            cout<<"Enter address: ";
            cin>>c;
            n->address=c;

            n->next=NULL;
            n->prev=NULL;
            head=n;
            cout<<"Contact added successfully"<<endl;
        }
        else{
            node * n= new node;
            cout<<"Name of the Person: ";
            cin>>a;
            n->name=a;
            
            cout<<"Enter Contact Number: ";
            cin>>x;
            n->phone_number=x;

            cout<<"Enter email: ";
            cin>>b;
            n->email=b;

            cout<<"Enter address: ";
            cin>>c;
            n->address=c;

            n->next=NULL;
            node*temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
            cout<<"Contact added successfully"<<endl;
        }
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"Welcome to the PhoneBook"<<endl;
            cout<<"PhoneBook is empty,Please add some contacts"<<endl;
            cout<<"ThankYou"<<endl;
            return;
        }
        
        int total=0;
        head=mergeSort(head);
        node*temp=head;
        cout<<" Name"<<"   Number"<<"  Email"<<"   Address\n";
        while(temp!=NULL)
        {
            total++;
            cout<<temp->name;
            cout<<"   "<<temp->phone_number;
            cout<<"   "<<temp->email;
            cout<<"  "<<temp->address;
            cout<<endl;
            temp=temp->next;
        }
        cout<<endl<<"Total Number of Contacts in the Phonebook: "<<total<<endl;
        
    }

    int search()
    {
        bool flag=false;
        node*temp=head;
        cout<<"*******************"<<endl;
        cout<<"Press 1 if you want to search by Name"<<endl;
        cout<<"Press 2 if you want to search by Phone Number"<<endl;
        int command;
        cout<<"Enter the command:"<<endl;
        cin>>command;

        if(command==1 and temp!=NULL)
        {
            cout<<"Enter the name to be searched:"<<endl;
            cin>>a;
            while(temp!=NULL)
            {
                if(temp->name==a)
                {
                    cout<<"***********"<<endl;
                    cout<<"Name :"<<temp->name<<endl;
                    cout<<"Phone NUmber: "<<temp->phone_number<<endl;
                    cout<<"Email: "<<temp->email<<endl;
                    cout<<"Address: "<<temp->address<<endl;
                    cout<<"***********"<<endl;
                    flag=true;
                    break;
                }
                temp=temp->next;
            }
            if(flag==false)
            {
                cout<<"Contact doesn't exist by this name"<<endl;
            }
        }
        else if(command==2 and temp!=NULL)
        {
            cout<<"Enter the Phone Number you want to search:"<<endl;
            cin>>x;
            while(temp!=NULL)
            {
                if(temp->phone_number==x)
                {
                    cout<<"***********"<<endl;
                    cout<<"Name :"<<temp->name<<endl;
                    cout<<"Phone NUmber: "<<temp->phone_number<<endl;
                    cout<<"Email: "<<temp->email<<endl;
                    cout<<"Address: "<<temp->address<<endl;
                    cout<<"***********"<<endl;
                    flag=true;
                    break;
                }
                temp=temp->next;
            }
            if(flag==false)
            {
                cout<<"Contact doesn't exist by this number"<<endl;
            }
        }
    }

    void deleteAllContacts()
    {
        node*temp=head;
        node*temp2;
        if(head==NULL)
        {
            cout<<"PhoneBook is already empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            temp2=temp;
            temp=temp->next;
            delete temp2;
        }
        head=NULL;
        cout<<"All contacts had been deleted successfully"<<endl;

    }

    void deleteOneContact()
    {
        node*temp=head;
        cout<<"****************"<<endl;
        cout<<"Press 1 if you want to search by Name"<<endl;
        cout<<"Press 2 if you want to search by Phone Number"<<endl;
        int command;
        cout<<"Enter the command:"<<endl;
        cin>>command;

        if(command==1 and temp!=NULL)
        {
            bool flag=false;
            cout<<"Enter the name to be searched:"<<endl;
            cin>>a;
            while(temp!=NULL)
            {
                if(temp->name==a)
                {
                    cout<<"***********"<<endl;
                    cout<<"Name :"<<temp->name<<endl;
                    cout<<"Phone NUmber: "<<temp->phone_number<<endl;
                    cout<<"Email: "<<temp->email<<endl;
                    cout<<"Address: "<<temp->address<<endl;
                    cout<<"***********"<<endl;
                    flag=true;
                    break;
                }
                temp=temp->next;
            }
            if(flag==true)
            {
                int command;
                cout<<"Press 1 to delete the contact"<<endl;
                cin>>command;
                if(command==1 and temp==head)
                {
                    node*t1=temp;
                    temp=temp->next;
                    delete t1;
                    temp->prev=NULL;
                    head=temp;
                    cout<<"Contact deleted successfully"<<endl;
                }
                else if(command==1 and temp->next==NULL)
                {
                    temp->prev->next=NULL;
                    delete temp;
                    cout<<"Contact deleted successfully"<<endl;
                }
                else if(command==1)
                {
                    node*t1=temp;
                    temp->prev->next=t1->next;
                    temp->next->prev=t1->prev;
                    delete t1;
                    cout<<"Contact deleted successfully"<<endl;
                }
                else{
                    cout<<"Please enter valid command"<<endl;
                }
            }
            else if(flag==false)
            {
                cout<<"Contact by this name doesn't exist in phoneBook"<<endl;
            }
        }
        else if(command==2 and temp!=NULL)
        {
            bool flag=false;
            cout<<"Enter the number to be searched:"<<endl;
            cin>>x;
            while(temp!=NULL)
            {
                if(temp->phone_number==x)
                {
                    cout<<"***********"<<endl;
                    cout<<"Name :"<<temp->name<<endl;
                    cout<<"Phone NUmber: "<<temp->phone_number<<endl;
                    cout<<"Email: "<<temp->email<<endl;
                    cout<<"Address: "<<temp->address<<endl;
                    cout<<"***********"<<endl;
                    flag=true;
                    break;
                }
                temp=temp->next;
            }
            if(flag==true)
            {
                int command;
                cout<<"Press 1 to delete the contact"<<endl;
                cin>>command;
                if(command==1 and temp==head)
                {
                    node*t1=temp;
                    temp=temp->next;
                    delete t1;
                    temp->prev=NULL;
                    head=temp;
                    cout<<"Contact deleted successfully"<<endl;
                }
                else if(command==1 and temp->next==NULL)
                {
                    temp->prev->next=NULL;
                    delete temp;
                    cout<<"Contact deleted successfully"<<endl;
                }
                else if(command==1)
                {
                    node*t1=temp;
                    temp->prev->next=t1->next;
                    temp->next->prev=t1->prev;
                    delete t1;
                    cout<<"Contact deleted successfully"<<endl;
                }
                else{
                    cout<<"Please enter valid command"<<endl;
                }
            }
            else if(flag==false)
            {
                cout<<"Contact by this number doesn't exist in phoneBook"<<endl;
            }
        }
    }
    
    //slow will point to the middle element of the Linked List
    node*midEle(node*head)
    {
        node*slow=head;
        node*fast=slow->next;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    node*merge(node*a,node*b)
    {
        node*dummy=new node;
        node*curr=dummy;
        while(a!=NULL and b!=NULL)
        {
            if(a->name<b->name)
            {
                curr->next=a;
                a=a->next;
                curr=curr->next;
            }
            else{
                curr->next=b;
                b=b->next;
                curr=curr->next;
            }
        }
        while(a!=NULL)
        {
            curr->next=a;
            a=a->next;
            curr=curr->next;
        }
        while(b!=NULL)
        {
            curr->next=b;
            b=b->next;
            curr=curr->next;
        }
        return dummy->next;
    }

    node*mergeSort(node*head)
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        node*mid=midEle(head);
        node*rightStart=mid->next;
        mid->next=NULL;
        node*a=mergeSort(head);
        node*b=mergeSort(rightStart);
        node*newHead=merge(a,b);
        return newHead;
    }

    int editContact()
    {
        node*temp=head;
        cout<<"*******************"<<endl;
        cout<<"Press 1 if you want to search by name"<<endl;
        cout<<"Press 2 if you want to search by number"<<endl;
        int command;
        cout<<"Enter the command :"<<endl;
        cin>>command;

        if(command==1 and temp!=NULL)
        {
            bool flag=false;
            cout<<"Enter the name to be edited:"<<endl;
            cin>>a;
            while(temp!=NULL)
            {
                if(temp->name==a)
                {
                    cout<<"****************"<<endl;
                    cout<<"Name :"<<temp->name<<endl;
                    cout<<"Contact Number :"<<temp->phone_number<<endl;
                    cout<<"Email :"<<temp->email<<endl;
                    cout<<"Address :"<<temp->address<<endl;
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==1)
            {
                int command;
                cout<<"Press 1 to edit the contact : "<<endl;
                cin>>command;
                if(command==1)
                {
                    cout<<"ENter the new name :"<<endl;
                    cin>>a;
                    cout<<"Enter the updated number :"<<endl;
                    cin>>x;
                    cout<<"Enter the updated email :"<<endl;
                    cin>>b;
                    cout<<"Enter the updated address :"<<endl;
                    cin>>c;

                    temp->name=a;
                    temp->phone_number=x;
                    temp->email=b;
                    temp->address=c;
                    
                    cout<<"Contact updated successfully"<<endl;
                }
                else{
                    cout<<"Enter the right command"<<endl;
                }
            }
        }
        else if(command==2 and temp!=NULL)
        {
            bool flag=false;
            cout<<"Enter the contact number too be edited :";
            cin>>x;
            while(temp!=NULL)
            {
                if(temp->phone_number==x){
                    cout<<"**************"<<endl;
                    cout<<"Name :"<<temp->name<<endl;
                    cout<<"Contact Number :"<<temp->phone_number<<endl;
                    cout<<"Email :"<<temp->email<<endl;
                    cout<<"Address :"<<temp->address<<endl;
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==true){
                int command;
                cout<<"Press 1 to edit the contact:"<<endl;
                cin>>command;
                if(command==1){
                    cout<<"ENter the new name :"<<endl;
                    cin>>a;
                    cout<<"Enter the updated number :"<<endl;
                    cin>>x;
                    cout<<"Enter the updated email :"<<endl;
                    cin>>b;
                    cout<<"Enter the updated address :"<<endl;
                    cin>>c;

                    temp->name=a;
                    temp->phone_number=x;
                    temp->email=b;
                    temp->address=c;
                    
                    cout<<"Contact updated successfully"<<endl;
                }
                else{
                    cout<<"Please enter the right command"<<endl;
                }
            }
        }
        else{
            cout<<"Please enter the right command "<<endl;
        }
    }
    void formatting(){
            cout<<"**************"<<endl;
	    	cout<<"  1. Add a Contact"<<endl;
	    	cout<<"  2. Edit an existing Contact"<<endl;
	    	cout<<"  3. Delete a Contact"<<endl;
	    	cout<<"  4. Search a Contact"<<endl;
	    	cout<<"  5. Display All the Contacts"<<endl;
	    	cout<<"  6. Delete All Contacts"<<endl;
            cout<<"  7. Recent Call History List"<<endl;
	    	cout<<"**************"<<endl;
		
	    	int command;
	    	cout<<"  Enter the Command: ";
	    	cin>>command;
	    	try
	    	{
	    		if(command>=1&&command<=7)
	    		{
	    			if(command==1)
	            	{
	            		addContact();
	            		book();
	    	        	formatting();
	            	}
	            	else if(command==2)
		        	{
		        		editContact();
                         book();
		        		formatting();
			        }
	            	else if(command==3)
	            	{
	    	        	deleteOneContact();
                        book();
	    	        	formatting();
	            	}
	            	else if(command==4)
	            	{
	            		search();
	            		formatting();
	            	}
	            	else if(command==5)
	            	{      		
	            		display();
	            		book();
	            		formatting();
	            	}
	            	else if(command==6)
	            	{
	            		deleteAllContacts();
	            		book();
	            		formatting();	
		        	}
                    else if(command==7)
                    {
                        calling();
                        formatting();
                    }
				}
				else
				{
					throw(command);
				}
			}
			catch(int command)
			{
				cout<<"  You Entered wrong Command... Run the Code Again"<<endl;
				formatting();
			}
	    }
    void book()
    {
        node*temp=head;
        ofstream myfile("Phonebook.txt");
        if(myfile.is_open()){
            while(temp!=NULL)
            {
                myfile<<temp->name<<"\n";
                myfile<<temp->phone_number<<"\n";
                myfile<<temp->email<<"\n";
                myfile<<temp->address<<"\n";

                temp=temp->next;
            }
            myfile.close();
            
        }
        else{
            cout<<"File is Empty."<<endl;
        }
    }
    void reopenbook()
    {
        bool blank;
        string str="";
        fflush(stdin);
        fflush(stdout);
        ifstream myfile("Phonebook.txt");
        fflush(stdin);
        fflush(stdout);
        if(myfile.is_open() && myfile.peek()!=EOF){
            int i=0;
            node*n=new node;
            while(myfile>>str){
                if(i%4==0){
                    if(head==NULL){
                        n->name=str;
                        n->next=NULL;
                        n->prev=NULL;
                        head=n;
                    }else{
                        n=new node();
                        n->name=str;
                        n->next=NULL;
                        node*temp=head;
                        while(temp->next!=NULL){
                            temp=temp->next;
                        }
                        temp->next=n;
                        n->prev=temp;
                    }
                }else if(i%4==1){
                    if(head==NULL){
                        n->phone_number=str;
                        n->next=NULL;
                        n->prev=NULL;
                        head=n;
                    }else{
                        n->phone_number=str;
                    }
                }
                else if(i%4==2){
                    if(head==NULL){
                        n->email=str;
                        n->next=NULL;
                        n->prev=NULL;
                        head=n;
                    }else{
                        n->email=str;
                    }
                }
                else if(i%4==3){
                    if(head==NULL){
                        n->address=str;
                        n->next=NULL;
                        n->prev=NULL;
                        head=n;
                    }else{
                        n->address=str;
                    }
                }
                i++;
            }
            myfile.close();
        }
        else{
            cout<<"Empty file"<<endl;
        }
    }
    void history(stack<node *> a)
    {
        while(!a.empty())
        {
            node * t =a.top();
            cout<<t->name<<"\t\t";
            cout<<t->phone_number<<"\t\t";
            cout<<t->email<<"\t\t";
            cout<<t->address<<"\t\t";
            cout<<endl;
            a.pop();
        }
    }
    void calling()
    {
       
        cout<<"Enter the name of person you want to call:"<<endl;
        cin>>a;
        bool flag=false;
        node*temp=head;
        while(temp!=NULL)
        {
            if(temp->name==a)
            {
                st.push(temp);
                flag=true;
                break;
            }
            temp=temp->next;
        }
        if(flag==false)
        {
            cout<<"This contact does not exist,please add to contact first"<<endl;
        }
        else{
            history(st);
        }
    }
    
    };
int main()
{
    phoneBook pb;
    pb.reopenbook();
    string n;
    cout<<"Enter your name: "<<endl;
    cin>>n;
    cout<<"***********"<<endl;
    cout<<"    "<<n<<"   Welcome to the PhoneBook  "<<endl;
    cout<<"***********"<<endl;
    pb.formatting();
    return 0;
}